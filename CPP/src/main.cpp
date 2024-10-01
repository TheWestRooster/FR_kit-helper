//
// Created by mscheman on 8/16/24.
//

#include "FR_kit-helper.h"

static KitHelper *chooseConstructor(int argc, char **argv);

int	main(int argc, char *argv[])
{
	if (argc > 3)
	{
		std::cout << BRED "Invalid number of parameters" CLR << std::endl;
		return 0;
	}
	KitHelper *kithelper;
	try
	{
		kithelper = chooseConstructor(argc, argv);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 0;
	}
	kithelper->run();
	delete kithelper;
}

static KitHelper *chooseConstructor(int argc, char **argv) {
	switch (argc)
	{
	case 1:
		return (new KitHelper());
	case 2:
		return new KitHelper(
			InputHandler::loadKit(argv[1])
		);
		break;
	case 3:
		return new KitHelper(
			InputHandler::loadKit(argv[1]),
			InputHandler::loadKit(argv[2])
		);
		break;
	default:
		return 0;
	}
}