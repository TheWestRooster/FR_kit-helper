//
// Created by mscheman on 8/16/24.
//

#include "FR_kit-helper.h"

int	main()
{
	InputHandler	inputHandler;

	std::cout << BOLD "Welcome to " BCYN "FR_kit-helper" CLR BOLD " by LeCoqBeau" CLR << std::endl;

	std::cout << inputHandler.userInput<float>(" ") << std::endl;
}

