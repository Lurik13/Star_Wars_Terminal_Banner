#include "main.hpp"

void Painter::print_struct()
{
	std::cout << "Text = " << this->text << "\nTo_replace = \n";
	for (std::map<char, std::string>::iterator it = this->to_replace.begin(); \
		it != this->to_replace.end(); it++)
		std::cout << "             " << it->first << " - " << it->second << std::endl;
}

void Painter::make_it_responsive(bool end)
{
	if (end == false)
	{
		while (this->index_in_line < (this->window_width - MIN_WIDTH) / 2)
		{
			std::cout << " ";
			this->index_in_line++;
		}
	}
	else
	{
		while (this->index_in_line < this->window_width)
		{
			std::cout << " ";
			this->index_in_line++;
		}
		std::cout << std::endl;
	}
}

int Painter::new_lines(std::string text, unsigned long *i, int *line_number)
{
	if (*i == 0 && this->mode != BEGIN_INSIDE_MODE)
		make_it_responsive(false);
	if ((text[*i] == '\\' && *i + 1 < text.size() && text[*i + 1] == 'n')
		|| text[*i] == '\0')
	{
		if (this->mode == BEGIN_INSIDE_MODE && *line_number == 0)
			std::cout << std::endl;
		else
			make_it_responsive(true);
		this->index_in_line = 0;
		make_it_responsive(false);
		*line_number += 1;
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
	int line_number = 0;
	for (unsigned long i = 0; i < this->text.size(); i++)
	{
		this->index_in_line++;
		int displayed = false;
		if (new_lines(this->text, &i, &line_number) != -1
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
	if (this->mode != END_INSIDE_MODE)
		std::cout << std::endl;
}
