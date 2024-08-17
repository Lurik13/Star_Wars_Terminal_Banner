#include "main.hpp"

Painter::Painter(int argc, char **argv)
{
	verif_params(argc, argv);
	this->text = argv[3];
	this->to_replace = fill_map(argc, argv);
	this->main_colour = argv[4];
	this->window_width = atoi(argv[1]);
	this->index_in_line = -1;
	init_colours();
}

void Painter::verif_params(int argc, char **argv)
{
	if (argc >= 5 && argc % 2 == 1)
	{
		if (std::strcmp(argv[2], "NORMAL") == 0)
			this->mode = NORMAL_MODE;
		else if (std::strcmp(argv[2],"END") == 0)
			this->mode = END_INSIDE_MODE;
		else if (std::strcmp(argv[2],"MIDDLE") == 0)
			this->mode = MIDDLE;
		else if (std::strcmp(argv[2],"BEGIN") == 0)
			this->mode = BEGIN_INSIDE_MODE;
		else
			throw(std::runtime_error("Wrong mode!"));
		for (int i = 5; i < argc; i++)
			if (i % 2 == 1 && std::string(argv[i]).size() != 1)
				throw(std::runtime_error(std::string("\"") + argv[i] + std::string("\" is not a char.")));
	}
	else
		throw(std::runtime_error("Wrong number of params.\n./a.out <window_width> <mode> <text> <main_colour> <char, string> <char, string> ... % 2"));
}

std::map<char, std::string> Painter::fill_map(int argc, char **argv)
{
	std::map<char, std::string> to_replace;
	for (int i = 5; i < argc - 1; i++)
		if (i % 2 == 1)
			to_replace.insert(std::pair<char, std::string>(argv[i][0], argv[i + 1]));
	return (to_replace);
}

void Painter::init_colours()
{
	std::string triggers[] = {
        "DARKRED", "DARKGREEN", "TURQUOISE", "LIGHTYELLOW",
        "WHITE", "GREY0", "GREY1", "GREY2", "GREY3", "GREY4", "GREY5", "GREY6", "GREY7", "GREY8", "GREY9", "BLACK"};
	std::string colours[] = {
        DARKRED, DARKGREEN, TURQUOISE, LIGHTYELLOW,
        WHITE, GREY0, GREY1, GREY2, GREY3, GREY4, GREY5, GREY6, GREY7, GREY8, GREY9, BLACK};
	
	for (int i = 0; i < 16; i++)
		this->colours.insert(std::pair<std::string, std::string>(triggers[i], colours[i]));
	this->main_colour = select_colour(this->main_colour);
}

// ligne 19: triggers.size()