//
// Created by mscheman on 8/27/24.
//

#include "InputHandler.h"

InputHandler::InputHandler() {}

template <typename T>
T InputHandler::userInput(const std::string &prompt) {
	std::string input;
	T ret;

	input = "";
	while (true) {
		std::cout << prompt << "> ";
		std::getline(std::cin, input);
		if (typeid(ret).name() == typeid(std::string).name())
		{
			ret = input;
			break;
		}
		else if (typeid(ret).name() == typeid(unsigned int).name())
		{
			errno = 0;
			ret = std::strtol(input.c_str(), __nullptr, 10);
			if (!errno)
				break ;
		}
		else if (typeid(ret).name() == typeid(float).name())
		{
			errno = 0;
			ret = std::strtof(input.c_str(), __nullptr);
			if (!errno)
				break ;
		}
		else
			return 0;
	}
	return ret;
}
