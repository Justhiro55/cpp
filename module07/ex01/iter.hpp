#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>
#include <cmath>
#include <cctype>
#include <sstream>
#include <climits>

// ----- color code -----
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

template <typename T>
void iter(T *array, size_t length, void (*func)(T const &))
{
    for (size_t i = 0; i < length; i++)
        func(array[i]);
}

#endif
