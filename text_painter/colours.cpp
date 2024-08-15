#include "main.hpp"

std::string select_colour(Utils *utils, std::string choice)
{
	if (utils->colours.find(choice) == utils->colours.end())
		return ("");
	return (utils->colours.find(choice)->second);
}

Utils init_colours(Utils *utils)
{
	std::string triggers[] = {"DARKRED", "DARKGREEN", "TURQUOISE", "LIGHTYELLOW",
		"GAINSBORO", "LIGHTGREY", "SILVER", "DARKGRAY", "GRAY", "DIMGRAY", "LIGHTCHARCOAL", "CHARCOAL", "SHADOW", "LIGHTSLATEGRAY", "SLATEGRAY", "DARKSLATEGRAY", "BLACK"};
	std::string colours[] = {DARKRED, DARKGREEN, TURQUOISE, LIGHTYELLOW,
		GAINSBORO, LIGHTGREY, SILVER, DARKGRAY, GRAY, DIMGRAY, LIGHTCHARCOAL, CHARCOAL, SHADOW, LIGHTSLATEGRAY, SLATEGRAY, DARKSLATEGRAY, BLACK};
	
	for (int i = 0; i < 17; i++)
		utils->colours.insert(std::pair<std::string, std::string>(triggers[i], colours[i]));
	utils->main_colour = select_colour(utils, utils->main_colour);
	return (*utils);
}
