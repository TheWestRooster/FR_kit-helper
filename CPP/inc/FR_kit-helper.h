//
// Created by mscheman on 8/27/24.
//

#ifndef FR_KIT_HELPER_H
#define FR_KIT_HELPER_H

#include "InputHandler.h"
#include "Kit.h"

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
};

#endif //FR_KIT_HELPER_H
