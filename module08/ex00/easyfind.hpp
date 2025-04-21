#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>
#include <cmath>
#include <cctype>
#include <sstream>
#include <climits>
#include <stdexcept>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>

// ----- color code -----
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

// ----- template function -----
template<typename T>
typename T::iterator easyfind(T &container, int value)
{
    typename T::iterator iter = std::find(container.begin(), container.end(), value);
    if (iter == container.end())
        throw std::runtime_error("Value not found");
    return iter;
};

#endif
