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
