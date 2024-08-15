#include "main.hpp"

// Colours: https://fr.wikipedia.org/wiki/Couleur_du_Web
// https://htmlcolorcodes.com/fr/tableau-de-couleur/tableau-de-couleur-design-material/

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
		std::cout << "\e[1m" << DARKRED << e.what() <<  R_RESET;
	}
}
