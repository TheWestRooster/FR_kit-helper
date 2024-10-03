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
		if (input[0] == "help")
			_help();
		else if (input[0] == "load")
			_load(input);
		else if (input[0] == "reload")
			_reload(input);
		else if (input[0] == "print")
			_print(input);
		else if (input[0] == "change")
			_change(input);
		else if (input[0] == "swap")
			_swap(input);
		else if (input[0] == "utils")
			_utils();
		else if (input[0] == "damage")
			_damage(input);
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
	PRINT "\treload (<attacker/victim> = attacker): Reload the kit using the associated .kit file" << NL;
	PRINT "\tprint (<attacker/victim/all> = attacker): Prints the wanted kit" << NL;
	PRINT "\tchange <attacker/victim> <stat> <value>: Changes the stats of a loaded kit" << NL;
	PRINT "\tswap: Swaps the attacker and the victim" << NL;
	PRINT "\tutils: Prints all valid damage type and stats" << NL;
	PRINT "\tdamage: Prints the usage of the damage command." << NL;
	PRINT NL;
}

void KitHelper::_load(const t_command &input)
{
	const size_t size = input.size();
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
	catch(...)
	{
		std::cerr << BRED "Error while loading kit " CLR << input[1] << BRED "." CLR << NL;
	}
	PRINT NL;
}

void KitHelper::_reload(const t_command &input)
{
	const size_t size = input.size();
	PRINT NL;
	try
	{
		if (size == 2 && input[1] == "victim")
		{
			const Kit newKit = InputHandler::loadKit(_victim.getName());
			PRINT YLW "Reloaded Victim kit" CLR << NL;
			_victim = newKit;
		}
		else
		{
			const Kit newKit = InputHandler::loadKit(_attacker.getName());
			PRINT YLW "Reloaded Attacker kit" CLR << NL;
			_attacker = newKit;
		}
	}
	catch(...)
	{
		std::cerr << BRED "Error while loading kit " CLR << input[1] << BRED "." CLR << NL;
	}
	PRINT NL;
}

void KitHelper::_print(const t_command &input)
{
	const size_t size = input.size();
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
}

void KitHelper::_change(const t_command &input)
{
	const size_t size = input.size();
	Stats changedStats = Kit::nullStats;
	Kit	*changed;
	float previousStat = 0;
	t_stats stat;
	float newAmount;
	int addMode = 0;

	if (size != 4)
		return _invalidParams(input);
	
	stat = Stats::strToStat(input[2]);
	if (stat == ESTATS_END || stat >= MISSING_PVS)
		return _invalidParams(input);
	
	if (input[3][0] == '+' || input[3][0] == '-')
		addMode = 1;

	try {
		newAmount = std::stof(input[3]);
	} catch(...) {
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
	std::swap(_attacker, _victim);
	PRINT NL;
	PRINT YLW "Swapped " CLR << _victim.getName() << YLW " and " CLR << _attacker.getName() << NL;
	PRINT NL;
}

void KitHelper::_utils() {
	PRINT NL;
	PRINT "Here is all valid damage types:" << NL;
	for (int type = PHYSICAL; type < ETYPE_END; type++)
		PRINT "  - " << Damage::typeToStr(static_cast<t_type>(type)) << NL;
	PRINT NL;
	PRINT "Here is all valid stats input:" << NL;
	for (int stat = PVS; stat < ESTATS_END; stat++)
		PRINT "  - " << Stats::statToStr(static_cast<t_stats>(stat))  << NL;
	PRINT NL;
}

static void damageHelp();
static void damageCreate(Kit &kit, const t_command &input);
static void damageAppend(Damage &attack, const std::string &ratio, const std::string &stat);
static void damageBase(Damage &attack, const std::string &input);
static void damageType(Damage &attack, const std::string &input);
static void damageCd(Damage &attack, const std::string &input);
static void damageRemove(Kit &kit, const std::string &input);
static void damagePop(Damage &attack);
static void damageCalculate(Damage &attack, const Kit &attacker, const Kit &victim);
static void damageDPS(Damage &attack, const Kit &attacker, const Kit &victim);
static void damagePrint(const Kit &kit);

void KitHelper::_damage(const t_command &input)
{
	const size_t size = input.size();
	Kit *kit;

	if (size < 2)
		return damageHelp();
	// Detect which loaded kit to modify
	if (input[1] == "attacker")
		kit = &_attacker;
	else if (input[1] == "victim")
		kit = &_victim;
	else
		return (_invalidParams(input));
	// Print
	if (input[2] == "print")
		return damagePrint(*kit);
	// check again
	if (size < 3)
		return _invalidParams(input);
	// Instantiates the Damage class
	Damage &damage = kit->findAttack(input[3]);
	if (damage == Damage::damageNull && input[2] != "create")
		return (_invalidParams(input));
	// Detect if the subcommand have enough parameters
	if (input[2] == "create" && size != 9)
		return _invalidParams(input);
	if (input[2] == "append" && size != 6)
		return _invalidParams(input);
	if ((input[2] == "type" || input[2] == "base" || input[2] == "cd") && size != 5)
		return _invalidParams(input);
	// Execution of subcommands
	if (input[2] == "create")
		damageCreate(*kit, input);
	else if (input[2] == "append")
		damageAppend(damage, input[4], input[5]);
	else if (input[2] == "base")
		damageBase(damage, input[4]);
	else if (input[2] == "type")
		damageType(damage, input[4]);
	else if (input[2] == "cd")
		damageCd(damage, input[4]);
	else if (input[2] == "remove")
		damageRemove(*kit, input[3]);
	else if (input[2] == "pop")
		damagePop(damage);
	else if (input[2] == "calculate")
		damageCalculate(damage, _attacker, _victim);
	else if (input[2] == "dps")
		damageDPS(damage, _attacker, _victim);
	else
		_invalidParams(input);
}

static void damageCreate(Kit &kit, const t_command &input) {
	std::string name = input[3];
	t_type type;
	float cd;
	float base;
	float ratio;
	t_stats stat;

	if (!(kit.findAttack(name) == Damage::damageNull)) {
		PRINT BRED "Attack arleady exists" << NL;
		return ;
	}
	type = Damage::strToType(input[4]);
	if (type == ETYPE_END) {
		PRINT BRED "Invalid type to create" << NL;
		return ;
	}
	try {
		cd = std::stof(input[5]);
	} catch (...) {
		PRINT BRED "Invalid cooldown to create" << NL;
		return ;
	}
	try {
		base = std::stof(input[6]) / 100.0f;
	} catch (...) {
		PRINT BRED "Invalid base damage to create" << NL;
		return ;
	}
	try {
		ratio = std::stof(input[7]) / 100.0f;
	} catch (...) {
		PRINT BRED "Invalid ratio to create" << NL;
		return ;
	}
	stat = Stats::strToStat(input[8]);
	if (stat == ESTATS_END) {
		PRINT BRED "Invalid stat to create" << NL;
		return ;
	}

	Damage newDamage(name, type, cd, base);
	newDamage.addRatio(stat, ratio);
	PRINT "Created " << newDamage << NL;
	kit += newDamage;
}

static void damageAppend(Damage &attack, const std::string &ratio, const std::string &stat) {
	t_stats newStats;
	float newRatio;

	try {
		newRatio = std::stof(ratio) / 100.0f;
	} catch (...) {
		PRINT BRED "Invalid ratio to append" << NL;
		return ;
	}
	newStats = Stats::strToStat(stat);
	if (newStats == ESTATS_END) {
		PRINT BRED "Invalid stat to append" << NL;
		return ;
	}
	PRINT NL;
	PRINT "Added ratio: " << roundf(newRatio * 100) << "% ";
	PRINT Stats::statToStr(newStats) << " to " << attack.getName() << NL;
	PRINT NL;
	attack.addRatio(newStats, newRatio);
}

static void damageBase(Damage &attack, const std::string &input) {
	float newBase;

	try {
		newBase = std::stof(input);
	} catch (...) {
		PRINT BRED "Couldn't change the base damage" << NL;
		return ;
	}
	PRINT NL;
	PRINT "Changed base damage of " << attack.getName();
	PRINT " from " << attack.getBase() << " to " << newBase << NL;
	PRINT NL;
	attack.setBase(newBase);
}

static void damageType(Damage &attack, const std::string &input) {
	t_type newType;

	newType = Damage::strToType(input);
	if (newType == ETYPE_END) {
		PRINT BRED "Couldn't change the type of damage" << NL;
		return ;
	}
	PRINT NL;
	PRINT "Changed type of damage of " << attack.getName();
	PRINT " from " << Damage::typeToStr(attack.getType());
	PRINT " to " << Damage::typeToStr(newType) << NL;
	PRINT NL;
	attack.setType(newType);
}

static void damageCd(Damage &attack, const std::string &input) {
	float newCD;

	try {
		newCD = std::stof(input);
	} catch (...) {
		PRINT BRED "Couldn't change the cooldown" << NL;
		return ;
	}
	PRINT NL;
	PRINT "Changed cooldown of " << attack.getName();
	PRINT " from " << attack.getCooldown() << " to " << newCD << NL;
	PRINT NL;
	attack.setCooldown(newCD);
}

static void damageRemove(Kit &kit, const std::string &input) {
	if (kit.findAttack(input) != Damage::damageNull) {
		PRINT NL;
		PRINT "Removed attack " << input << " from " << kit.getName() << NL;
		PRINT NL;
	} else {
		PRINT NL;
		PRINT BRED "Kit " << kit.getName() << " does not have attack " << input << CLR << NL;
		PRINT NL;
	}
	kit.removeAttack(input);
}

static void damagePop(Damage &attack) {
	float lastRatio = attack.getRatios().back();
	t_stats lastStat = attack.getStats().back();
	PRINT NL;
	PRINT YLW "Pop'd ratio: " CLR << roundf(lastRatio * 100) << "% ";
	PRINT Stats::statToStr(lastStat) << YLW " from " CLR << attack.getName() << CLR << NL;
	PRINT NL;
	--attack;
}

static void damageCalculate(Damage &attack, const Kit &attacker, const Kit &victim) {
	PRINT NL;
	attack.calculateDamage(attacker, victim, true);
	PRINT NL;
}

static void damageDPS(Damage &attack, const Kit &attacker, const Kit &victim) {
	PRINT NL;
	PRINT attack.getName() << "'s DPS: " << attack.calculateDPS(attacker, victim) << NL;
	PRINT NL;
}

static void damagePrint(const Kit &kit) {
	PRINT NL;
	if (kit.getAttacks().empty()) {
		PRINT BBLK "none" CLR << NL;
	}
	for (auto it: kit.getAttacks()) {
		PRINT it << NL;
	}
	PRINT NL;
}

static void damageHelp() {
	PRINT NL;
	PRINT "Here is the damage command's prototype:" << NL;
	PRINT "\tdamage <attacker/victim> <subcommand> <...>" << NL;
	PRINT NL;
	PRINT "Here is all the subcommands and their parameters:" << NL;
	PRINT "\tcreate <name> <type> <cooldown> <base damage> <ratio%> <stat>" << NL;
	PRINT "\tappend <name> <ratio%> <stat>" << NL;
	PRINT "\tbase <name> <new base damage>" << NL;
	PRINT "\ttype <name> <new type>" << NL;
	PRINT "\tcd <name> <new cooldown>" << NL;
	PRINT "\tcd <name> <new cooldown>" << NL;
	PRINT "\tdelete <name>" << NL;
	PRINT "\tpop <name>: Deletes the last appended ratio" << NL;
	PRINT "\tcalculate <name>: Calculates the damage of the attack" << NL;
	PRINT "\tdps <name>: Calculates the dps of the attack" << NL;
	PRINT "\tprint: Prints all attack of a kit" << NL;
	PRINT NL;
}

void KitHelper::_invalidParams(const t_command &input)
{
	PRINT PRP "Invalid parameters for command " CYN << input[0] << NL;
	PRINT CLR "Checks the parameters value and number: " << NL;
	if (input.size() == 1)
		PRINT BLK "none" CLR << NL;
	for (t_command::const_iterator it = ++input.cbegin(); it != input.cend(); ++it)
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
