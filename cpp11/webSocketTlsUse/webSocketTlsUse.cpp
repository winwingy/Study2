// webSocketTlsUse.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <websocketpp/config/asio_client.hpp>

#include <websocketpp/client.hpp>

#include <iostream>

//#include <boost/chrono.hpp>


typedef websocketpp::client<websocketpp::config::asio_tls_client> client;

using websocketpp::lib::placeholders::_1;
using websocketpp::lib::placeholders::_2;
using websocketpp::lib::bind;

// pull out the type of messages sent by our config
typedef websocketpp::config::asio_tls_client::message_type::ptr message_ptr;
typedef websocketpp::lib::shared_ptr<boost::asio::ssl::context> context_ptr;
typedef client::connection_ptr connection_ptr;


class perftest {
public:
	typedef perftest type;
	//typedef boost::chrono::duration<int,std::micro> dur_type;

	perftest () {
		m_endpoint.set_access_channels(websocketpp::log::alevel::all);
		m_endpoint.set_error_channels(websocketpp::log::elevel::all);

		// Initialize ASIO
		m_endpoint.init_asio();

		// Register our handlers
		m_endpoint.set_socket_init_handler(bind(&type::on_socket_init,this,::_1));
		m_endpoint.set_tls_init_handler(bind(&type::on_tls_init,this,::_1));
		m_endpoint.set_message_handler(bind(&type::on_message,this,::_1,::_2));
		m_endpoint.set_open_handler(bind(&type::on_open,this,::_1));
		m_endpoint.set_close_handler(bind(&type::on_close,this,::_1));
	}

	void start(std::string uri) {
		websocketpp::lib::error_code ec;
		client::connection_ptr con = m_endpoint.get_connection(uri, ec);

		if (ec) {
			m_endpoint.get_alog().write(websocketpp::log::alevel::app,ec.message());
		}

		//con->set_proxy("http://58.251.230.3:9000");

		m_endpoint.connect(con);

		// Start the ASIO io_service run loop
		//m_start = boost::chrono::high_resolution_clock::now();
		m_endpoint.run();
	}

	void on_socket_init(websocketpp::connection_hdl hdl) {
		//m_socket_init = boost::chrono::high_resolution_clock::now();
	}

	context_ptr on_tls_init(websocketpp::connection_hdl hdl) {
		//m_tls_init = boost::chrono::high_resolution_clock::now();
		context_ptr ctx(new boost::asio::ssl::context(boost::asio::ssl::context::sslv23_client));

		try {
			ctx->set_options(boost::asio::ssl::context::default_workarounds |
				boost::asio::ssl::context::no_sslv3 |
				boost::asio::ssl::context::single_dh_use);
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		return ctx;
	}

	void on_open(websocketpp::connection_hdl hdl) {
		//m_open = boost::chrono::high_resolution_clock::now();
		m_endpoint.send(hdl, "123", websocketpp::frame::opcode::text);
	}
	void on_message(websocketpp::connection_hdl hdl, message_ptr msg) {
		//m_message = boost::chrono::high_resolution_clock::now();
		m_endpoint.close(hdl,websocketpp::close::status::going_away,"");
	}
	void on_close(websocketpp::connection_hdl hdl) {
		//m_close = boost::chrono::high_resolution_clock::now();

		//std::cout << "Socket Init: " << boost::chrono::duration_cast<dur_type>(m_socket_init-m_start).count() << std::endl;
		//std::cout << "TLS Init: " << boost::chrono::duration_cast<dur_type>(m_tls_init-m_start).count() << std::endl;
		//std::cout << "Open: " << boost::chrono::duration_cast<dur_type>(m_open-m_start).count() << std::endl;
		///std::cout << "Message: " << boost::chrono::duration_cast<dur_type>(m_message-m_start).count() << std::endl;
		//std::cout << "Close: " << boost::chrono::duration_cast<dur_type>(m_close-m_start).count() << std::endl;
	}
private:
	client m_endpoint;

// 	boost::chrono::high_resolution_clock::time_point m_start;
// 	boost::chrono::high_resolution_clock::time_point m_socket_init;
// 	boost::chrono::high_resolution_clock::time_point m_tls_init;
// 	boost::chrono::high_resolution_clock::time_point m_open;
// 	boost::chrono::high_resolution_clock::time_point m_message;
// 	boost::chrono::high_resolution_clock::time_point m_close;
};

int main(int argc, char* argv[]) {
	std::string uri = "wss://echo.websocket.org";

 	std::stringstream ss;
 	ss << time(nullptr);
 	uri = "wss://ls.dev.xsteach.cn:8084/socket.io/?EIO=4&transport=websocket&t=" 
 	+ ss.str();

	if (argc == 2) {
		uri = argv[1];
	}

	try {
		perftest endpoint;
		endpoint.start(uri);
	} catch (const std::exception & e) {
		std::cout << e.what() << std::endl;
	} catch (websocketpp::lib::error_code e) {
		std::cout << e.message() << std::endl;
	} catch (...) {
		std::cout << "other exception" << std::endl;
	}
}