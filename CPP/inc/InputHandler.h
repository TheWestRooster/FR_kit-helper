//
// Created by mscheman on 8/27/24.
//

#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Kit.h"
#include "colors.h"

class InputHandler {
	public:
		// Methods
		static Kit loadKit(const std::string &kit);

		// Exceptions
		class KitFileNotFound : public std::exception {
			public:
				const char *what() throw() {
					return BRED "Kit File not found." CLR ;
				}
		};
		class KitFileIncomplete : public std::exception {
			public:
				const char *what() throw() {
					return BRED "Kit File is incomplete." CLR ;
				}
		};
};


#endif //INPUTHANDLER_H
