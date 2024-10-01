//
// Created by mscheman on 8/27/24.
//

#include "InputHandler.h"

Kit InputHandler::loadKit(const std::string &kit)
{
	std::string		filePath = "user/" + kit + ".kit";
	std::fstream	file(filePath);
	std::string		fileLine;

	std::string		kitName;
	Stats			kitStat;
	std::string		statLine;
	float			statValue;

	if (!file.is_open())
		throw InputHandler::KitFileNotFound();

	std::getline(file, kitName);
	
	for (int i = 0; i < CRM + 1; i++)
	{
		if (file.eof())
			throw KitFileIncomplete();
		std::getline(file, statLine);
		statLine = &statLine[5];
		statValue = std::stof(statLine);
		if (statLine.find('%') != std::string::npos)
			statValue /= 100.0f;
		kitStat.setValue((t_stats)i, statValue);
		if (i != CDR)
			continue ;
		if (file.peek() != '\n')
			continue ;
		kitStat.setValue(CRC, 0.0f);
		kitStat.setValue(CRM, 0.0f);
		break ;
	}
	Kit newKit(kitName, kitStat);
	return newKit;
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
