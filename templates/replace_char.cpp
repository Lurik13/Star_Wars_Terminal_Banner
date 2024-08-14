#include <string>
#include <iostream>
#include <map>
#include <exception>

#define RED "\e[38;2;170;0;0m"
#define TURQUOISE "\e[38;2;0;251;255m"
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
	return (utils->colours.find(choice)->second);
}

Utils init_colours(Utils *utils)
{
	std::string triggers[3] = {"RED", "GREEN", "TURQUOISE"};
	std::string colours[3] = {RED, "\e[38;2;0;170;0m", TURQUOISE};
	
	for (int i = 0; i < 3; i++)
		utils->colours.insert(std::pair<std::string, std::string>(triggers[i], colours[i]));
	std::cout << "main_colour = " << utils->main_colour << std::endl;
	utils->main_colour = select_colour(utils, utils->main_colour);
	return (*utils);
}

std::map<char, std::string> fill_map(int argc, char **argv)
{
	std::map<char, std::string> to_replace;
	for (int i = 3; i != argc - 1; i++)
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

		for (std::map<std::string, std::string>::iterator it = utils.colours.begin(); \
			it != utils.colours.end(); it++)
			std::cout << it->first << " ";
		std::cout << "\n\n--------------------------------\n\n";

		display_text(&utils);
		// print_struct(&utils);
	}
	catch (std::runtime_error &e)
	{
		std::cout << RED << e.what() <<  R_RESET;
	}
}

// segfault with "\e..."