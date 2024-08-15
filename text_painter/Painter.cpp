#include "main.hpp"

Painter::Painter(int argc, char **argv)
{
	verif_params(argc, argv);
	this->text = argv[1];
	this->to_replace = fill_map(argc, argv);
	this->main_colour = argv[2];
	init_colours();
}

void Painter::verif_params(int argc, char **argv)
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

std::map<char, std::string> Painter::fill_map(int argc, char **argv)
{
	std::map<char, std::string> to_replace;
	for (int i = 3; i < argc - 1; i++)
		if (i % 2 == 1)
			to_replace.insert(std::pair<char, std::string>(argv[i][0], argv[i + 1]));
	return (to_replace);
}

void Painter::init_colours()
{
    #define WHITE "\e[38;2;255;255;255m"
#define GREY0 "\e[38;2;250;250;250m"
#define GREY1 "\e[38;2;245;245;245m"
#define GREY2 "\e[38;2;238;238;238m"
#define GREY3 "\e[38;2;224;224;224m"
#define GREY4 "\e[38;2;189;189;189m"
#define GREY5 "\e[38;2;158;158;158m"
#define GREY6 "\e[38;2;117;117;117m"
#define GREY7 "\e[38;2;97;97;97m"
#define GREY8 "\e[38;2;66;66;66m"
#define GREY9 "\e[38;2;33;33;33m"
#define BLACK "\e[38;2;0;0;0m"
	std::string triggers[] = {
        "DARKRED", "DARKGREEN", "TURQUOISE", "LIGHTYELLOW",
        "WHITE", "GREY0", "GREY1", "GREY2", "GREY3", "GREY4", "GREY5", "GREY6", "GREY7", "GREY8", "GREY9", "BLACK",
		"GAINSBORO", "LIGHTGREY", "SILVER", "DARKGRAY", "GRAY", "DIMGRAY", "LIGHTCHARCOAL", "CHARCOAL", "SHADOW", "LIGHTSLATEGRAY", "SLATEGRAY", "DARKSLATEGRAY", "BLACK"};
	std::string colours[] = {
        DARKRED, DARKGREEN, TURQUOISE, LIGHTYELLOW,
        WHITE, GREY0, GREY1, GREY2, GREY3, GREY4, GREY5, GREY6, GREY7, GREY8, GREY9, BLACK,
		GAINSBORO, LIGHTGREY, SILVER, DARKGRAY, GRAY, DIMGRAY, LIGHTCHARCOAL, CHARCOAL, SHADOW, LIGHTSLATEGRAY, SLATEGRAY, DARKSLATEGRAY, BLACK};
	
	for (int i = 0; i < 29; i++)
		this->colours.insert(std::pair<std::string, std::string>(triggers[i], colours[i]));
	this->main_colour = select_colour(this->main_colour);
}

// ligne 19: triggers.size()