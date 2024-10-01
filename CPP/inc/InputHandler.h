//
// Created by mscheman on 8/27/24.
//

#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Kit.h"
#include "colors.h"

typedef std::vector<std::string> t_command;

class InputHandler {
	public:
		// Methods
		static Kit loadKit(const std::string &kit);
		static std::string userInput(const std::string &prompt, bool (*check)(const std::string&)=ignoreInput);
		static bool ignoreInput(const std::string &);
		static t_command inputSplit(const std::string &input);

		static t_command commandInput(const std::string &prompt, bool (*check)(const t_command&)=ignoreInput);
		static bool ignoreInput(const t_command &);

		// Exceptions
		class KitFileNotFound : public std::exception {
			public:
				KitFileNotFound() {};
				inline const char *what() throw() {
					return BRED "Kit File not found." CLR ;
				}
		};
		class KitFileIncomplete : public std::exception {
			public:
				KitFileIncomplete() {};
				inline const char *what() throw() {
					return BRED "Kit File is incomplete." CLR ;
				}
		};
};


#endif //INPUTHANDLER_H
