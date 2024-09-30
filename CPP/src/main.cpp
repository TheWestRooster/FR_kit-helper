//
// Created by mscheman on 8/16/24.
//

#include "FR_kit-helper.h"

int	main(int argc, char *argv[])
{
	argc = 2;
	if (argc == 1 || argc > 3)
	{
		std::cout << BRED "Invalid number of parameters" CLR << std::endl;
		return 0;
	}
	(void)argv;
	Kit attacker = InputHandler::loadKit("Soshiro");
	Kit victim = InputHandler::loadKit("Template");
	Damage sword("Sword", attacker, PHYSICAL);

	sword.addRatio(ATK, 1.30f);
	sword.addRatio(ESTATS_END, 0);
	std::cout << floor(sword.calculateDamage(victim, true)) << std::endl;
	// Damage firstHit("1er Hit", attacker, PHYSICAL);
	// firstHit.addRatio(ATK, 2.60f);
	// firstHit.addRatio(VICTIM_CPV, 0.15f);
	// firstHit.addRatio(ESTATS_END, 0);
	// victim -= firstHit.calculateDamage(victim, true);
	// Damage secondHit("2eme Hit", attacker, PHYSICAL);
	// secondHit.addRatio(ATK, 3.90f);
	// secondHit.addRatio(VICTIM_MPV, 0.30f);
	// secondHit.addRatio(ESTATS_END, 0);
	// victim -= secondHit.calculateDamage(victim, true);
	// std::cout << firstHit.calculateDamage(victim) + secondHit.calculateDamage(victim) << std::endl;
}
