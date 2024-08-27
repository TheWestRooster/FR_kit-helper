//
// Created by mscheman on 8/27/24.
//

#ifndef CPP_INPUTHANDLER_H
#define CPP_INPUTHANDLER_H

#include <iostream>
#include <string>
#include "colors.h"
#include <typeinfo>
#include <cstdlib>
#include <cerrno>

class InputHandler {
	public:
		InputHandler();
		template <typename T>
		T	userInput(const std::string &prompt);
};


#endif //CPP_INPUTHANDLER_H
