#pragma once

#include <string>
#include <iostream>
#include <map>
#include <exception>
#include <cctype>

#include "colours/grey.hpp"
#include "colours/types.hpp"

#define DARKRED "\e[38;2;170;0;0m" // custom colour
#define DARKGREEN "\e[38;2;0;130;0m" //custom colour
#define TURQUOISE "\e[38;2;0;251;255m" // custom colour
#define LIGHTYELLOW "\e[38;2;255;228;54m" // custom colour

// Grays
#define GAINSBORO "\e[38;2;220;220;220m"
#define LIGHTGREY "\e[38;2;211;211;211m"
#define SILVER "\e[38;2;192;192;192m"
#define DARKGRAY "\e[38;2;169;169;169m"
#define GRAY "\e[38;2;128;128;128m"
#define DIMGRAY "\e[38;2;105;105;105m"
#define LIGHTCHARCOAL "\e[38;2;85;85;85m" // custom colour
#define CHARCOAL "\e[38;2;67;67;67m" // custom colour
#define SHADOW "\e[38;2;53;53;53m" // custom colour
#define LIGHTSLATEGRAY "\e[38;2;119;136;153m"
#define SLATEGRAY "\e[38;2;112;128;144m"
#define DARKSLATEGRAY "\e[38;2;47;79;79m"
#define BLACK "\e[38;2;0;0;0m"

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

		// display_text.cpp
		int new_lines(std::string text, unsigned long *i);
		int paint_sentence_dots(std::string text, unsigned long i, std::string main_colour);

		// main.cpp
		std::map<char, std::string> fill_map(int argc, char **argv);

		// Painter.cpp
		std::string select_colour(std::string choice);
		void verif_params(int argc, char **argv);
		void init_colours();
};
