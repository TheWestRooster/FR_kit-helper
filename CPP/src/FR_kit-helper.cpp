#include "FR_kit-helper.h"

KitHelper::KitHelper() {}

KitHelper::KitHelper(const Kit &attacker) {
	_attacker = attacker;
}

KitHelper::KitHelper(const Kit &attacker, const Kit &victim) {
	_attacker = attacker;
	_victim = victim;
}

void KitHelper::run() {
	if (_attacker == Kit::templateKit)
		std::cout << YLW "Warning: Attacker kit is not loaded" CLR << std::endl;
	if (_victim == Kit::templateKit)
		std::cout << YLW "Warning: Victim kit is not loaded" CLR << std::endl;
}