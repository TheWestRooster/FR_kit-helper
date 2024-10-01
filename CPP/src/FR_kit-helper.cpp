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
	t_command input;
	if (_attacker == Kit::templateKit)
		PRINT YLW "Warning: Attacker kit is not loaded" CLR << NL;
	if (_victim == Kit::templateKit)
		PRINT YLW "Warning: Victim kit is not loaded" CLR << NL;
	PRINT "The program doesn't handle spaces in command parameters, use '_' instead." << NL;
	while (true)
	{
		input.clear();
		input = InputHandler::commandInput("> ");
		if (std::cin.eof())
			break;
		if (input.empty())
			continue ;
		else if (input[0] == "help")
			_help();
		else if (input[0] == "load")
			_load(input);
		else if (input[0] == "print")
			_print(input);
		else if (input[0] == "change")
			_change(input);
		else if (input[0] == "swap")
			_swap(input);
		else
			_unknownCommand();
	}
}

void KitHelper::_help()
{
	PRINT NL;
	PRINT "Here is the list of all commands and their use:" << NL;
	PRINT "\thelp: Prints this message" << NL;
	PRINT "\tload <kit> (<attacker/victim> = attacker): Loads the .kit file associated to the kit" << NL;
	PRINT "\tprint (<attacker/victim/all> = attacker): Prints the wanted kit" << NL;
	PRINT "\tchange <attacker/victim> <stat> <value>: Changes the stats of a loaded kit" << NL;
	PRINT "\tswap: Swaps the attacker and the victim" << NL;
	PRINT NL;
}

void KitHelper::_load(const t_command &input)
{
	size_t size = input.size();
	PRINT NL;
	if (size == 1 || size > 3)
		return _invalidParams(input);
	if (size == 3 && (input[2] != "victim" && input[2] != "attacker"))
		return _invalidParams(input);
	try
	{
		Kit newKit = InputHandler::loadKit(input[1]);
		if (size == 3 && input[2] == "victim")
		{
			PRINT YLW "Overwriting Victim kit into " CLR << newKit.getName() << NL;
			_victim = newKit;
		}
		else
		{
			PRINT YLW "Overwriting Attacker kit into " CLR << newKit.getName() << NL;
			_attacker = newKit;
		}
	}
	catch(const std::exception &e)
	{
		std::cerr << BRED "Error while loading kit " CLR << input[1] << BRED "." CLR << NL;
	}
	PRINT NL;
}

void KitHelper::_print(const t_command &input)
{
	size_t size = input.size();
	PRINT NL;
	if (size == 1 || (size == 2 && input[1] == "attacker"))
		PRINT "Attacker: " << _attacker;
	else if (size == 2 && input[1] == "victim")
		PRINT "Victim: " << _victim;
	else if (size == 2 && input[1] == "all")
		PRINT "Attacker: " << _attacker << "Victim: " << _victim;
	else
		return _invalidParams(input);
	PRINT NL;
	return ;
}

void KitHelper::_change(const t_command &input)
{
	size_t size = input.size();
	Stats changedStats = Kit::nullStats;
	Kit	*changed;
	float previousStat = 0;
	t_stats stat;
	float newAmount;
	int addMode = 0;

	if (size != 4)
		return _invalidParams(input);
	
	stat = Stats::strToStat(input[2]);
	if (stat == ESTATS_END || stat >= MPV)
		return _invalidParams(input);
	
	if (input[3][0] == '+' || input[3][0] == '-')
		addMode = 1;

	try {
		newAmount = std::stof(input[3]);
	} catch(const std::exception& e) {
		return _invalidParams(input);
	}
	
	if (input[1] == "attacker")
		changed = &_attacker;
	else if (input[1] == "victim")
		changed = &_victim;
	else
		return _invalidParams(input);
	previousStat = changed->extractStat(stat);
	if (!addMode)
		changedStats.setValue(stat, newAmount - previousStat);
	else
		changedStats.setValue(stat, newAmount);
	*changed += changedStats;
	PRINT YLW "Changed " CLR << Stats::statToStr(stat) << YLW " of " CLR << changed->getName();
	PRINT YLW " from " BLK << previousStat << YLW " to " CLR << changed->extractStat(stat);
	PRINT NL;
}

void KitHelper::_swap(const t_command &input)
{
	(void)input;
	Kit temp(_attacker);
	_attacker = _victim;
	_victim = temp;
	PRINT NL;
	PRINT YLW "Swapped " CLR << _victim.getName() << YLW " and " CLR << _attacker.getName() << NL;
	PRINT NL;
}

void KitHelper::_damage(const t_command &input)
{
	size_t size = input.size();
	Kit *changed;

	if (size < 4)
		return _invalidParams(input);
	
	if (input[3] == "append" && size < 5)
		return _invalidParams(input);
	if (input[3] == "set_type" && size < 4)
		return _invalidParams(input);
	
	if (input[1] == "attacker")
		changed = &_attacker;
	else if (input[1] == "victim")
		changed = &_victim;
	else
		return (_invalidParams(input));

	changed->changePV(150);

}

// damage attacker <damage_name> <append/pop/set_type/calculate> ([append]<STAT> <RATIO>)

void KitHelper::_invalidParams(const t_command &input)
{
	PRINT PRP "Invalid parameters for command " CYN << input[0] << NL;
	PRINT CLR "Checks the parameters value and number: " << NL;
	if (input.size() == 1)
		PRINT BLK "none" CLR << NL;
	for (t_command::const_iterator it = ++input.cbegin(); it != input.cend(); it++)
		PRINT BLK << *it << " " CLR;
	PRINT NL;
}

void KitHelper::_unknownCommand()
{
	PRINT NL;
	PRINT PRP "Unrecognized command." << NL;
	PRINT CLR "Try 'help'" << NL;
	PRINT NL;
}
