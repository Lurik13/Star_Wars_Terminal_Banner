#include "main.hpp"

unsigned int Painter::ft_random()
{
	gettimeofday(&this->timeval_struct, NULL);
	suseconds_t first_usecond = this->timeval_struct.tv_usec;
	usleep(2);
	gettimeofday(&this->timeval_struct, NULL);
	suseconds_t second_usecond = this->timeval_struct.tv_usec;
	return (((first_usecond + second_usecond) / 2 * 1103515243 + 12345) % 2147483647);
}

void Painter::display_stars(int max_size, bool left)
{
	int random_limit = 15 < max_size ? 15 : max_size;
	if (left == true)
		random_limit = 10 < max_size ? 10 : max_size;
	int random = 2 + (ft_random() % random_limit - 2);
	if (max_size - this->index_in_line < 4)
		random = 10;
	while (this->index_in_line < max_size)
	{
		while (this->index_in_line < max_size && random)
		{
			random--;
			std::cout << " ";
			this->index_in_line++;
		}
		if (this->index_in_line < max_size)
			display_char('.');
		this->index_in_line++;
		random_limit = 30 < max_size ? 30 : max_size;
		random = ft_random() % random_limit + 212 / this->window_width * 4;
	}
}

void Painter::make_it_responsive(bool end)
{
	if (end == false)
		display_stars((this->window_width - MIN_WIDTH) / 2, true);
	else
	{
		display_stars(this->window_width, false);
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

