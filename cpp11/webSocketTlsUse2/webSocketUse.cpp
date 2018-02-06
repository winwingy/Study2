#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>

#include "websocket_endpoint.h"

int main(int argc, char **argv)
{
	bool done = false;
	std::string input;
	kagula::websocket_endpoint endpoint;

	endpoint.connect("");

	while (!done) {
		std::cout << "Enter Command: ";
		std::getline(std::cin, input);

		if (input == "quit") {
			done = true;
		}
		else if (input.substr(0, 4) == "send") {
			std::stringstream ss(input);

			std::string cmd;
			std::string message;

			ss >> cmd;
			std::getline(ss, message);

			endpoint.send(message);
		}
		else if (input.substr(0, 4) == "show") {
			endpoint.show();
		}
		else {
			std::cout << "> Unrecognized Command" << std::endl;
		}
	}

	endpoint.close();

	return 0;
}
