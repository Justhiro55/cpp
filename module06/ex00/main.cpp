#include "ScalarConverter.hpp"
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << RED << "Error: Invalid number" << RESET << std::endl;
        std::cout << YELLOW << "Usage: " << argv[0] << " <literal>" << RESET << std::endl;
        return 1;
    }

    ScalarConverter::convert(argv[1]);
    return 0;
}
