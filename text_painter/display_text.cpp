#include "main.hpp"

int new_lines(std::string text, unsigned long i)
{
    if (text[i] == '\\' && i + 1 < text.size() && text[i + 1] == 'n')
    {
        std::cout << std::endl;
        i++;
        return (-1);
    }
    return (i);
}

void display_text(Utils *utils)
{
	for (unsigned long i = 0; i < utils->text.size(); i++)
	{
		int displayed = false;
        // if (new_lines(utils->text, i) != -1)
        // {
            if (utils->text[i] == '\\' && i + 1 < utils->text.size() && utils->text[i + 1] == 'n')
            {
                std::cout << std::endl;
                i++;
                continue ;
            }
            int tmp = i;
            if (utils->text[tmp] == '.' && tmp > 0 && (isalpha(utils->text[tmp - 1]) || utils->text[tmp] == '.')
                && !(tmp > 2 && utils->text[tmp - 2] == '\\' && utils->text[tmp - 1] == 'n'))
            {
                while (utils->text[tmp] == '.')
                    tmp--;
                if (isalpha(utils->text[tmp]))
                {
                    std::cout << utils->main_colour << utils->text[i] << "\e[0m";
                    continue ;
                }
            }
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
        // }
	}
}
