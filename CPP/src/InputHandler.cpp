//
// Created by mscheman on 8/27/24.
//

#include "InputHandler.h"

Kit InputHandler::loadKit(const std::string &kit)
{
	std::string		filePath = "user/" + kit + ".kit";
	std::fstream	file(filePath);
	std::string		kitName;

	std::getline(file, kitName);
	Stats kitStat = _loadStats(file);

	if (!file.is_open())
		throw InputHandler::KitFileNotFound();

	Kit newKit(kitName, kitStat);
	Damage newDamage;
	do {
		newDamage = _loadAttack(file);
		newKit += newDamage;
	} while (!file.eof());
	return newKit;
}

Stats InputHandler::_loadStats(std::fstream& file)
{
	Stats			kitStat;
	std::string		fileLine;
	std::string		statLine;
	float			statValue;

	for (int i = 0; i < CRIT_DAMAGE + 1; i++)
	{
		if (file.eof())
			throw KitFileIncomplete();
		std::getline(file, statLine);
		statLine = &statLine[5];
		statValue = std::stof(statLine);
		if (statLine.find('%') != std::string::npos)
			statValue /= 100.0f;
		kitStat.setValue(static_cast<t_stats>(i), statValue);
		if (i != CDR)
			continue ;
		if (file.peek() != '\n')
			continue ;
		kitStat.setValue(CRIT_CHANCE, 0.0f);
		kitStat.setValue(CRIT_DAMAGE, 0.0f);
		break ;
	}
	return kitStat;
}

Damage InputHandler::_loadAttack(std::fstream& file)
{
	Damage damage = Damage::damageNull;
	std::string	fileLine;
	std::string tmp;
	std::vector<t_stats> stats;
	std::vector<float> ratios;

	while (!file.eof())
	{
		std::getline(file, fileLine);
		if (fileLine.empty() || fileLine != "#ATTACK:")
			continue;
		// Name
		std::getline(file, fileLine);
		if (fileLine.compare(0, 6, "Name: ") != 0)
			return Damage::damageNull;
		damage.setName(&fileLine[6]);
		// Type
		std::getline(file, fileLine);
		if (fileLine.compare(0, 6, "Type: ") != 0)
			return Damage::damageNull;
		damage.setType(Damage::strToType(&fileLine[6]));
		// Cooldown
		std::getline(file, fileLine);
		if (fileLine.compare(0, 10, "Cooldown: ") != 0)
			return Damage::damageNull;
		damage.setCooldown(std::stof(&fileLine[10]));
		// Base Damage
		std::getline(file, fileLine);
		if (fileLine.compare(0, 13, "Base Damage: ") != 0)
			return Damage::damageNull;
		damage.setBase(std::stof(&fileLine[13]));
		// Stats
		{
			std::getline(file, fileLine);
			if (fileLine.compare(0, 7, "Stats: ") != 0)
				return Damage::damageNull;
			for (std::string::iterator it = fileLine.begin() + 7; it < fileLine.end(); ++it) {
				tmp.clear();
				while (it < fileLine.end() && *it != ' ') {
					tmp += *it;
					it++;
				}
				if (Stats::strToStat(tmp) == ESTATS_END)
					return Damage::damageNull;
				stats.push_back(Stats::strToStat(tmp));
			}
		}
		// Ratios
		{
			std::getline(file, fileLine);
			if (fileLine.compare(0, 7, "Ratio: ") != 0)
				return Damage::damageNull;
			for (std::string::iterator it = fileLine.begin() + 7; it < fileLine.end(); ++it) {
				tmp.clear();
				while (it < fileLine.end() && *it != ' ') {
					tmp += *it;
					it++;
				}
				ratios.push_back(std::stof(tmp) / 100);
			}
			if (ratios.size() != stats.size())
				return Damage::damageNull;
		}
		for (size_t i = 0; i < stats.size(); ++i)
			damage.addRatio(stats[i], ratios[i]);
		break;
	}
	return damage;
}

std::string InputHandler::userInput(const std::string &prompt, bool (*check)(const std::string &))
{
	std::string input;
	do {
		if (std::cin.eof())
			return "";
		std::cout << prompt;
		std::getline(std::cin, input);
	} while (!check(input));
	return (input);
}

bool InputHandler::ignoreInput(const std::string &)
{
	return true;
}

std::vector<std::string> InputHandler::inputSplit(const std::string &input)
{
	std::vector<std::string> list;
	std::string add;

	for (std::string::const_iterator it = input.cbegin(); it != input.cend(); ++it)
	{
		add = "";
		while (it != input.cend() && isspace(*it))
			it++;
		if (it == input.cend())
			break ;
		while (it != input.cend() && !isspace(*it))
		{
			add.push_back(*it);
			++it;
		}
		list.push_back(add);
		if (it == input.cend())
			break ;
	}
	return (list);
}

t_command InputHandler::commandInput(const std::string &prompt, bool (*check)(const t_command &)) {
	std::string input;
	t_command command;
	do
	{
		command.clear();
		if (std::cin.eof())
			return command;
		std::cout << prompt;
		std::getline(std::cin, input);
		command = inputSplit(input);
	} while (!check(command));
	return (command);
}

bool InputHandler::ignoreInput(const t_command &) {
	return true;
}

