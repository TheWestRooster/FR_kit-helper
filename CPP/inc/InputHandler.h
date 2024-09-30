//
// Created by mscheman on 8/27/24.
//

#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <iostream>
#include <string>
#include "colors.h"
#include <typeinfo>
#include <cstdlib>
#include <cerrno>

class InputHandler {
	public:
		template <typename T>
		T	userInput(const std::string &prompt);
};


#endif //INPUTHANDLER_H
