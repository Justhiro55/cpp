#include "iter.hpp"

void print(int const &i)
{
    std::cout << i << std::endl;
}

void strlength(std::string const &str)
{
    std::cout << str.length() << std::endl;
}

int main(void)
{
    std::cout << CYAN << "\n---print function test---" << RESET << std::endl;
    int tab[] = {0, 1, 2, 3, 4};
    ::iter(tab, 5, print);

    std::cout << CYAN << "\n---strlength function test---" << RESET << std::endl;
    std::string str[] = {"Hello", "World", "!"};
    ::iter(str, 3, strlength);

    std::cout << std::endl;
    return 0;
}