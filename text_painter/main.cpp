#include "main.hpp"

// Colours: https://fr.wikipedia.org/wiki/Couleur_du_Web
// https://htmlcolorcodes.com/fr/tableau-de-couleur/tableau-de-couleur-design-material/

void Painter::print_struct()
{
	std::cout << "Text = " << this->text << "\nTo_replace = \n";
	for (std::map<char, std::string>::iterator it = this->to_replace.begin(); \
		it != this->to_replace.end(); it++)
		std::cout << "             " << it->first << " - " << it->second << std::endl;
}

int main(int argc, char **argv)
{
	try
	{
		Painter painter(argc, argv);
		painter.display_text();
		// painter.print_struct();
	}
	catch (std::runtime_error &e)
	{
		std::cout << BOLD << DARKRED << e.what() <<  R_RESET;
	}
}
