#pragma once

#include <string>
#include <iostream>
#include <map>
#include <exception>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <sys/time.h>
#include <unistd.h> 

#include "colours/grey.hpp"
#include "colours/types.hpp"

#define MIN_WIDTH 78
#define NORMAL_MODE 13
#define END_INSIDE_MODE 42
#define MIDDLE 63
#define BEGIN_INSIDE_MODE 84

#define DARKRED "\e[38;2;170;0;0m" // custom colour
#define DARKGREEN "\e[38;2;0;130;0m" //custom colour
#define TURQUOISE "\e[38;2;0;251;255m" // custom colour
#define LIGHTYELLOW "\e[38;2;255;228;54m" // custom colour

class Painter
{
	public:
		void display_text();
		void print_struct();
		Painter(int argc = 0, char **argv = NULL);
		~Painter() {};
	private:
		std::string							text;
		std::map<char, std::string>			to_replace;
		std::string							main_colour;
		std::map<std::string, std::string>	colours;
		int									window_width;
		int									mode;
		int									index_in_line;
		struct timeval						timeval_struct;

		// display_text.cpp
		int new_lines(std::string text, unsigned long *i, int *line_number);
		int paint_sentence_dots(std::string text, unsigned long i, std::string main_colour);
		std::string select_colour(std::string choice);
		void display_char(char c);

		// Painter.cpp
		void verif_params(int argc, char **argv);
		std::map<char, std::string> fill_map(int argc, char **argv);
		void init_colours();

		// responsiveness.cpp
		unsigned int ft_random();
		void display_stars(int max_size, bool left);
		void make_it_responsive(bool end);
};

// fin de chaque texte : \n et plus rien