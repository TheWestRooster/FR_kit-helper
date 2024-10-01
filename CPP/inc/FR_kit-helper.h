//
// Created by mscheman on 8/27/24.
//

#ifndef FR_KIT_HELPER_H
#define FR_KIT_HELPER_H

#include "InputHandler.h"
#include "Kit.h"

#define NL std::endl
#define PRINT std::cout <<

class KitHelper
{
public:
	KitHelper();
	KitHelper(const Kit &attacker);
	KitHelper(const Kit &attacker, const Kit &victim);
	void run();
private:
	Kit _attacker;
	Kit _victim;
	void _help();
	void _load(const t_command &input);
	void _print(const t_command &input);
	void _change(const t_command &input);
	void _swap(const t_command &input);
	void _damage(const t_command &input);
	void _invalidParams(const t_command &input);
	void _unknownCommand();
};

#endif //FR_KIT_HELPER_H
