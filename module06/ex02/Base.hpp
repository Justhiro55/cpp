#ifndef Base_HPP
#define Base_HPP

#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>
#include <cmath>
#include <cctype>
#include <sstream>
#include <iomanip>

// ----- color code -----
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

class Base
{
    public:
        virtual ~Base();
};

#endif
