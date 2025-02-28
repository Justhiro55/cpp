#ifndef Serialization_HPP
#define Serialization_HPP

#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>
#include <cmath>
#include <cctype>
#include <sstream>
#include <iomanip>
#include <stdint.h>

// ----- color code -----
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

struct Data
{
    std::string playerName;
    int score;
    bool isGameCompleted;
};

class Serialization
{
    public:
        static uintptr_t serialize(Data *ptr);
        static Data *deserialize(uintptr_t raw);

    private:
        // ----- orthodox canonical form -----
        Serialization();
        Serialization(const Serialization &src);
        Serialization &operator=(const Serialization &rhs);
        ~Serialization();
};

#endif
