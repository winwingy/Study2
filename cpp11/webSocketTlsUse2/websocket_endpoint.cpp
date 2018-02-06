#include "stdafx.h"

#include <websocketpp/config/asio_client.hpp>
#include <websocketpp/client.hpp>

#include <websocketpp/common/thread.hpp>
#include <websocketpp/common/memory.hpp>

#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <sstream>

#include "websocket_endpoint.h"

typedef websocketpp::client<websocketpp::config::asio_tls_client> ws_client;
typedef websocketpp::config::asio_tls_client::message_type::ptr message_ptr;
typedef websocketpp::lib::shared_ptr<boost::asio::ssl::context> context_ptr;
typedef ws_client::connection_ptr connection_ptr;
using websocketpp::lib::bind;

namespace kagula
{

	class connection_metadata {
	public:
		typedef websocketpp::lib::shared_ptr<connection_metadata> ptr;

		connection_metadata()
			: m_hdl()
			, m_status("Connecting")
			, m_uri()
			, m_server("N/A")
		{}

		void setHdlUri(websocketpp::connection_hdl hdl, std::string uri)
		{
			m_hdl = hdl;
			m_uri = uri;
		}

		connection_metadata(websocketpp::connection_hdl hdl, std::string uri)
			: m_hdl(hdl)
			, m_status("Connecting")
			, m_uri(uri)
			, m_server("N/A")
		{}

		void on_open(ws_client *client, websocketpp::connection_hdl hdl) {
			m_status = "Open";

			ws_client::connection_ptr con = client->get_con_from_hdl(hdl);
			m_server = con->get_response_header("Server");
			con->send("aaa");
		}

		// if connection failed, the function will be invoke.
		void on_fail(ws_client *client, websocketpp::connection_hdl hdl) {
			m_status = "Failed";

			ws_client::connection_ptr con = client->get_con_from_hdl(hdl);
			m_server = con->get_response_header("Server");
			m_error_reason = con->get_ec().message();
		}

		void on_close(ws_client *client, websocketpp::connection_hdl hdl) {
			m_status = "Closed";
			ws_client::connection_ptr con = client->get_con_from_hdl(hdl);
			std::stringstream s;
			s << "close code: " << con->get_remote_close_code() << " ("
				<< websocketpp::close::status::get_string(con->get_remote_close_code())
				<< "), close reason: " << con->get_remote_close_reason();
			m_error_reason = s.str();
		}

		void on_message(websocketpp::connection_hdl, message_ptr msg) {
			if (msg->get_opcode() == websocketpp::frame::opcode::text) {
				m_messages.push_back("<< " + msg->get_payload());
			}
			else {
				m_messages.push_back("<< " + websocketpp::utility::to_hex(msg->get_payload()));
			}
		}


		void on_socket_init(websocketpp::connection_hdl hdl) {

		}		

		context_ptr on_tls_init(websocketpp::connection_hdl hdl) {
			context_ptr ctx(new boost::asio::ssl::context(
				boost::asio::ssl::context::sslv23_client));

			try {
				ctx->set_options(boost::asio::ssl::context::default_workarounds |
					boost::asio::ssl::context::no_sslv2 |
					boost::asio::ssl::context::single_dh_use);
			} catch (std::exception& e) {
				std::cout << e.what() << std::endl;
			}
			return ctx;
		}


		websocketpp::connection_hdl get_hdl() const {
			return m_hdl;
		}

		std::string get_status() const {
			return m_status;
		}

		std::string get_uri() const {
			return m_uri;
		}

		void record_sent_message(std::string message) {
			m_messages.push_back(">> " + message);
		}

		friend std::ostream & operator<< (std::ostream & out, connection_metadata const & data);
	private:
		websocketpp::connection_hdl m_hdl;
		std::string m_status;
		std::string m_uri;
		std::string m_server;
		std::string m_error_reason;
		std::vector<std::string> m_messages;
	};

	std::ostream & operator<< (std::ostream & out, connection_metadata const & data) {
		out << "> URI: " << data.m_uri << "\n"
			<< "> Status: " << data.m_status << "\n"
			<< "> Remote Server: " << (data.m_server.empty() ? "None Specified" : data.m_server) << "\n"
			<< "> Error/close reason: " << (data.m_error_reason.empty() ? "N/A" : data.m_error_reason) << "\n";
		out << "> Messages Processed: (" << data.m_messages.size() << ") \n";

		std::vector<std::string>::const_iterator it;
		for (it = data.m_messages.begin(); it != data.m_messages.end(); ++it) {
			out << *it << "\n";
		}

		return out;
	}

	ws_client g_wsEndPoint;
	connection_metadata::ptr g_wsClientConnection;

	websocketpp::lib::shared_ptr<websocketpp::lib::thread> g_threadWS;

	websocket_endpoint::websocket_endpoint(){
// 		g_wsEndPoint.clear_access_channels(websocketpp::log::alevel::all);
// 		g_wsEndPoint.clear_error_channels(websocketpp::log::elevel::all);
		g_wsEndPoint.set_access_channels(websocketpp::log::alevel::all);
		g_wsEndPoint.set_error_channels(websocketpp::log::elevel::all);

		g_wsEndPoint.init_asio();
// 		g_wsEndPoint.start_perpetual();
// 		g_threadWS = websocketpp::lib::make_shared<websocketpp::lib::thread>(
// 			&ws_client::run, &g_wsEndPoint);
	}

	websocket_endpoint::~websocket_endpoint() {
		g_wsEndPoint.stop_perpetual();

		if (g_wsClientConnection->get_status() == "Open") {
			// Only close open connections
			websocketpp::lib::error_code ec;
			g_wsEndPoint.close(g_wsClientConnection->get_hdl(), websocketpp::close::status::going_away, "", ec);
			if (ec) {
				std::cout << "> Error closing ws connection " << g_wsClientConnection->get_uri() << " :" << ec.message() << std::endl;
			}
		}

		g_threadWS->join();
	}
#include <sstream>
	int websocket_endpoint::connect(std::string const & uri2) {

		g_wsClientConnection = websocketpp::lib::make_shared<connection_metadata>();

		g_wsEndPoint.set_open_handler(websocketpp::lib::bind(
			&connection_metadata::on_open,
			g_wsClientConnection,
			&g_wsEndPoint,
			websocketpp::lib::placeholders::_1
			));
		g_wsEndPoint.set_fail_handler(websocketpp::lib::bind(
			&connection_metadata::on_fail,
			g_wsClientConnection,
			&g_wsEndPoint,
			websocketpp::lib::placeholders::_1
			));
		g_wsEndPoint.set_close_handler(websocketpp::lib::bind(
			&connection_metadata::on_close,
			g_wsClientConnection,
			&g_wsEndPoint,
			websocketpp::lib::placeholders::_1
			));
		g_wsEndPoint.set_message_handler(websocketpp::lib::bind(
			&connection_metadata::on_message,
			g_wsClientConnection,
			websocketpp::lib::placeholders::_1,
			websocketpp::lib::placeholders::_2
			));

		g_wsEndPoint.set_socket_init_handler(websocketpp::lib::bind(
			&connection_metadata::on_socket_init,g_wsClientConnection,
			websocketpp::lib::placeholders::_1));
		g_wsEndPoint.set_tls_init_handler(websocketpp::lib::bind(
			&connection_metadata::on_tls_init,
			g_wsClientConnection,
			websocketpp::lib::placeholders::_1));


		std::string uri = "wss://echo.websocket.org";
// 		std::stringstream ss;
// 		ss << time(nullptr);
// 		uri = "ws://ls.dev.xsteach.cn:8084/socket.io/?EIO=4&transport=websocket&t=" 
// 		+ ss.str();


		websocketpp::lib::error_code ec;

		ws_client::connection_ptr pConnection = g_wsEndPoint.get_connection(uri, ec);

		websocketpp::lib::error_code  ec2;
		pConnection->set_proxy("http://120.199.64.163:8081", ec2);

		if (ec) {
			std::cout << "> Connect initialization error: " << ec.message() << std::endl;
			return -1;
		}

		g_wsClientConnection->setHdlUri(pConnection->get_handle(), uri);

		g_wsEndPoint.connect(pConnection);
		g_wsEndPoint.run();
		return 0;
	}

	void close(websocketpp::close::status::value code, std::string reason) {
		websocketpp::lib::error_code ec;

		g_wsEndPoint.close(g_wsClientConnection->get_hdl(), code, reason, ec);
		if (ec) {
			std::cout << "> Error initiating close: " << ec.message() << std::endl;
		}
	}

	void websocket_endpoint::close()
	{
		if (g_wsClientConnection->get_status()=="Open")
		{
			int close_code = websocketpp::close::status::normal;
			kagula::close(close_code, "");
		}
	}	

	void websocket_endpoint::send(std::string message) {
		websocketpp::lib::error_code ec;

		g_wsEndPoint.send(g_wsClientConnection->get_hdl(), message, websocketpp::frame::opcode::text, ec);
		if (ec) {
			std::cout << "> Error sending message: " << ec.message() << std::endl;
			return;
		}

		g_wsClientConnection->record_sent_message(message);
	}	

	void websocket_endpoint::show()
	{
		std::cout << * g_wsClientConnection << std::endl;
	}
}
