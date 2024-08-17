#include "main.hpp"

void Painter::print_struct()
{
	std::cout << "Text = " << this->text << "\nTo_replace = \n";
	for (std::map<char, std::string>::iterator it = this->to_replace.begin(); \
		it != this->to_replace.end(); it++)
		std::cout << "             " << it->first << " - " << it->second << std::endl;
}

void Painter::make_it_responsive()
{
	for (int i = 0; i < (this->window_width - MIN_WIDTH) / 2; i++)
		std::cout /*<< main_colour */<< " ";
}

int Painter::new_lines(std::string text, unsigned long *i)
{
	if (*i == 0)
		make_it_responsive();
	if (text[*i] == '\\' && *i + 1 < text.size() && text[*i + 1] == 'n')
	{
		std::cout << std::endl;
		make_it_responsive();
		*i+= 2;
		return (-1);
	}
	return (*i);
}

int Painter::paint_sentence_dots(std::string text, unsigned long i, std::string main_colour)
{
	if (text[i] == '.' && i > 0 && (isalpha(text[i - 1]) || text[i] == '.')
		&& !(i > 2 && text[i - 2] == '\\' && text[i - 1] == 'n'))
	{
		while (text[i] == '.')
			i--;
		if (isalpha(text[i]))
		{
			std::cout << main_colour << text[i + 1] << RESET;
			return (true);
		}
	}
	return (false);
}

std::string Painter::select_colour(std::string choice)
{
	if (isdigit(choice[0]))
	{
		std::string types[] = {RESET, BOLD, DIM, ITALIC, UNDERLINED, BLINK, OVERLINE, INVERT, HIDDEN, STRIKEOUT};
		std::cout << types[choice[0] - 48];
		choice.erase(0, 1);
	}
	if (this->colours.find(choice) == this->colours.end())
		return ("");
	return (this->colours.find(choice)->second);
}

void Painter::display_text()
{
	for (unsigned long i = 0; i < this->text.size(); i++)
	{
		int displayed = false;
		if (new_lines(this->text, &i) != -1
			&& paint_sentence_dots(this->text, i, this->main_colour) == false)
		{
			for (std::map<char, std::string>::iterator it = this->to_replace.begin(); \
				it != this->to_replace.end(); it++)
			{
				if (it->first == this->text[i])
				{
					std::cout << select_colour(it->second) << it->first << RESET;
					displayed = true;
					break ;
				}
			}
			if (displayed == false)
				std::cout << this->main_colour << this->text[i] << RESET;
		}
	}
}
