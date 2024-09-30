//
// Created by mscheman on 8/27/24.
//

#include "InputHandler.h"

template <typename T>
static T convert(std::string &input);

template <typename T>
T InputHandler::userInput(const std::string &prompt) {
	std::string input;
	T ret;

	input = "";
	while (true) {
		std::cout << prompt << "> ";
		std::getline(std::cin, input);
		try
		{
			ret = convert<T>(input);
		}
		catch(const std::exception& e)
		{
			std::cerr << BRED << e.what() << CLR << std::endl;
			std::exit(EXIT_FAILURE);
		}
	}
	return ret;
}

template <typename T>
static T convert(std::string &input) {
	if (typeid(T).name() == typeid(std::string).name())
	{
		return input;
	}
	else if (typeid(T).name() == typeid(unsigned int).name())
	{
		return std::atoi(input.c_str());
	}
	else if (typeid(T).name() == typeid(float).name())
	{
		return std::atof(input.c_str());
	}
	else
		return 0;
}
