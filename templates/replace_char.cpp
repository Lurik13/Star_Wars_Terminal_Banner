#include <string>
#include <iostream>



int main(int argc, char **argv)
{
    if (argc == 3)
    {
        std::string text = argv[1];
        (void)text;
        char letter = argv[2][0];
        std::cout << letter << std::endl;
    }
    else
        std::cout << "Wrong number of params\n";
}
