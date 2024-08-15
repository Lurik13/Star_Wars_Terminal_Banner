#pragma once

#include <string>
#include <iostream>
#include <map>
#include <exception>
#include <cctype>

#include "colours/grays.hpp"
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

typedef struct Utils
{
	std::string							text;
	std::map<char, std::string>			to_replace;
	std::string							main_colour;
	std::map<std::string, std::string>	colours;
} Utils;

// colours.cpp
std::string select_colour(Utils *utils, std::string choice);
Utils init_colours(Utils *utils);

// display_text.cpp
void display_text(Utils *utils);

// main.cpp
void verif_params(int argc, char **argv);
std::map<char, std::string> fill_map(int argc, char **argv);
void print_struct(Utils *utils);