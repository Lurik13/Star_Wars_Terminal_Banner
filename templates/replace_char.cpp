#include <string>
#include <iostream>
#include <map>
#include <exception>
#include <cctype>

// Colours: https://fr.wikipedia.org/wiki/Couleur_du_Web

#define DARKRED "\e[38;2;170;0;0m" // custom colour
#define DARKGREEN "\e[38;2;0;130;0m" //custom colour
#define TURQUOISE "\e[38;2;0;251;255m" // custom colour
#define LIGHTYELLOW "\e[38;2;255;228;54m" // custom colour

// Grays
#define GAINSBORO "\e[38;2;220;220;220m"
#define LIGHTGREY "\e[38;2;211;211;211m"
#define SILVER "\e[38;2;192;192;192m"
#define DARKGRAY "\e[38;2;169;169;169m"
#define GRAY "\e[38;2;128;128;128m"
#define DIMGRAY "\e[38;2;105;105;105m"
#define LIGHTCHARCOAL "\e[38;2;85;85;85m" // custom colour
#define CHARCOAL "\e[38;2;67;67;67m" // custom colour
#define SHADOW "\e[38;2;53;53;53m" // custom colour
#define LIGHTSLATEGRAY "\e[38;2;119;136;153m"
#define SLATEGRAY "\e[38;2;112;128;144m"
#define DARKSLATEGRAY "\e[38;2;47;79;79m"
#define BLACK "\e[38;2;0;0;0m"

#define RESET "\e[0m"
#define R_RESET "\e[0m\n"


typedef struct Utils
{
	std::string text;
	std::map<char, std::string> to_replace;
	std::string main_colour;
	std::map<std::string, std::string> colours;
} Utils;

void verif_params(int argc, char **argv)
{
	if (argc >= 3 && argc % 2 == 1)
	{
		for (int i = 3; i < argc; i++)
			if (i % 2 == 1 && std::string(argv[i]).size() != 1)
				throw(std::runtime_error(std::string("\"") + argv[i] + std::string("\" is not a char.")));
	}
	else
		throw(std::runtime_error("Wrong number of params.\n./a.out <text> <main_colour> <char, string> <char, string> ... % 2"));
}

std::string select_colour(Utils *utils, std::string choice)
{
	if (utils->colours.find(choice) == utils->colours.end())
		return ("");
	return (utils->colours.find(choice)->second);
}

Utils init_colours(Utils *utils)
{
	std::string triggers[17] = {"DARKRED", "DARKGREEN", "TURQUOISE", "LIGHTYELLOW",
		"GAINSBORO", "LIGHTGREY", "SILVER", "DARKGRAY", "GRAY", "DIMGRAY", "LIGHTCHARCOAL", "CHARCOAL", "SHADOW", "LIGHTSLATEGRAY", "SLATEGRAY", "DARKSLATEGRAY", "BLACK"};
	std::string colours[17] = {DARKRED, DARKGREEN, TURQUOISE, LIGHTYELLOW,
		GAINSBORO, LIGHTGREY, SILVER, DARKGRAY, GRAY, DIMGRAY, LIGHTCHARCOAL, CHARCOAL, SHADOW, LIGHTSLATEGRAY, SLATEGRAY, DARKSLATEGRAY, BLACK};
	
	for (int i = 0; i < 17; i++)
		utils->colours.insert(std::pair<std::string, std::string>(triggers[i], colours[i]));
	utils->main_colour = select_colour(utils, utils->main_colour);
	return (*utils);
}

std::map<char, std::string> fill_map(int argc, char **argv)
{
	std::map<char, std::string> to_replace;
	for (int i = 3; i < argc - 1; i++)
		if (i % 2 == 1)
			to_replace.insert(std::pair<char, std::string>(argv[i][0], argv[i + 1]));
	return (to_replace);
}

void print_struct(Utils *utils)
{
	std::cout << "Text = " << utils->text << "\nTo_replace = \n";
	for (std::map<char, std::string>::iterator it = utils->to_replace.begin(); \
		it != utils->to_replace.end(); it++)
		std::cout << "             " << it->first << " - " << it->second << std::endl;
}

void display_text(Utils *utils)
{
	for (unsigned long i = 0; i < utils->text.size(); i++)
	{
		int displayed = false;
		if (utils->text[i] == '\\' && i + 1 < utils->text.size() && utils->text[i + 1] == 'n')
		{
			std::cout << std::endl;
			i++;
			continue ;
		}
		int tmp = i;
		if (utils->text[tmp] == '.' && tmp > 0 && (isalpha(utils->text[tmp - 1]) || utils->text[tmp] == '.')
			&& !(tmp > 2 && utils->text[tmp - 2] == '\\' && utils->text[tmp - 1] == 'n'))
		{
			while (utils->text[tmp] == '.')
				tmp--;
			if (isalpha(utils->text[tmp]))
			{
				std::cout << utils->main_colour << utils->text[i] << "\e[0m";
				continue ;
			}
		}
		for (std::map<char, std::string>::iterator it = utils->to_replace.begin(); \
			it != utils->to_replace.end(); it++)
		{
			if (it->first == utils->text[i])
			{
				std::cout << select_colour(utils, it->second) << it->first << "\e[0m";
				displayed = true;
				break ;
			}
		}
		if (displayed == false)
			std::cout << utils->main_colour << utils->text[i] << "\e[0m";
	}
}

int main(int argc, char **argv)
{
	try
	{
		verif_params(argc, argv);
		Utils utils;
		utils.main_colour = argv[2];
		utils = init_colours(&utils);
		utils.text = argv[1];
		utils.to_replace = fill_map(argc, argv);
		display_text(&utils);
		// print_struct(&utils);
	}
	catch (std::runtime_error &e)
	{
		std::cout << DARKRED << e.what() <<  R_RESET;
	}
}
