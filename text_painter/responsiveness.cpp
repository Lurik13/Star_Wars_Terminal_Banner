#include "main.hpp"

void Painter::display_big_star()
{
	std::vector<std::string> colours = {LIGHTYELLOW, WHITE, GREY0, GREY1, GREY2, GREY3, GREY4, GREY5, GREY6, GREY7};
	size_t random = (int)rand() % (colours.size());
	size_t i = 0;

	std::vector<std::string>::iterator iter = colours.begin();
		// std::cout << random;
	for (; iter != colours.end(); iter++)
	{
		// std::cout << iter->first << std::endl;
		if (i == random)
		{
			std::cout << *iter << '+' << RESET;
			break ;
		}
		i++;
	}
}

void Painter::display_stars(int max_size)
{
	while (this->index_in_line < max_size)
	{
		if (rand() <= (long)RAND_MAX * 4 / 100)
		{
			if (rand() <= (long)RAND_MAX * STARS_PERCENTAGE / 100)
				display_big_star();
			else
				display_char('.');
			if (++this->index_in_line < max_size)
				std::cout << " ";
		}
		else
			std::cout << " ";
		this->index_in_line++;
	}
}

void Painter::make_it_responsive(bool end)
{
	if (end == false)
		display_stars((this->window_width - MIN_WIDTH) / 2);
	else
	{
		display_stars(this->window_width);
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
		usleep(50000);
		this->index_in_line = 0;
		make_it_responsive(false);
		*line_number += 1;
		*i+= 2;
		return (-1);
	}
	return (*i);
}

