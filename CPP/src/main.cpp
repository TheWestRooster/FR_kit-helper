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
	Kit Attacker;
	Kit Victim("Victim", Kit::templateStats);
	Damage aDMG("Epee", Attacker);
	aDMG.addRatio(ATK, 1.30f);
	aDMG.addRatio(VICTIM_MPV, 0.15f);
	Victim = 150;
	aDMG.calculateDamage(Victim, true);
}
