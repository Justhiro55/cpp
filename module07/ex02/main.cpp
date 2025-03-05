#include <iostream>
#include <string>
#include "Array.hpp"

#define MAX_VAL 5
int main()
{
    std::cout << "\n----- int array -----\n" << std::endl;
    Array<int> numbers(MAX_VAL);
    int *mirror = new int[MAX_VAL];

    srand(time(NULL));

    std::cout << "Array size: " << numbers.size() << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    numbers.printArray();

    std::cout << std::endl;

    //SCOPE
    std::cout << "Array size: " << numbers.size() << std::endl << std::endl;
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    std::cout << "Array size: " << numbers.size() << std::endl << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << RED << "didn't save the same value!!" << RESET << std::endl;
            return 1;
        }
    }

    numbers.printArray();

    std::cout << std::endl;

    try
    {
        std::cout << "-- Trying to access out of range --" << std::endl;
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << '\n';
    }

    std::cout << "\n----- string array -----\n" << std::endl;
    Array<std::string> strings(3);

    std::cout << "String array size: " << strings.size() << std::endl;

    std::cout << std::endl;

    strings[0] = "42";
    strings[1] = "Tokyo";
    strings[2] = "hhagiwar";

    std::cout << "String values: " << std::endl;
    for (unsigned int i = 0; i < strings.size(); i++)
    {
        std::cout << BLUE << strings[i] << RESET << std::endl;
    }
    std::cout << std::endl;

    try
    {
        std::cout << "-- Trying to access out of range --" << std::endl;
        strings[3] = "Out of bounds";
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    delete [] mirror;
    std::cout << std::endl;
    return 0;
}

__attribute__((destructor))
static void destructor()
{
    system("leaks -q Array");
}
