#pragma once

#include <string>
#include <iostream>
#include <map>
#include <exception>
#include <cctype>
#include <cstdlib>

#include "colours/grey.hpp"
#include "colours/types.hpp"

#define MIN_WIDTH 78

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

		// display_text.cpp
		void make_it_responsive();
		int new_lines(std::string text, unsigned long *i);
		int paint_sentence_dots(std::string text, unsigned long i, std::string main_colour);
		std::string select_colour(std::string choice);

		// Painter.cpp
		void verif_params(int argc, char **argv);
		std::map<char, std::string> fill_map(int argc, char **argv);
		void init_colours();
};
