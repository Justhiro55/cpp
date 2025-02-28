#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

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

class ScalarConverter
{
    public:
        // ----- type check functions -----
        static void convert(const std::string &str);

    private:
        // ----- orthodox canonical form -----
        ScalarConverter();
        ScalarConverter(const ScalarConverter &src);
        ScalarConverter &operator=(const ScalarConverter &rhs);
        ~ScalarConverter();

        // ----- type check functions -----
        static bool isChar(const std::string &str);
        static bool isInt(const std::string &str);
        static bool isFloat(const std::string &str);
        static bool isDouble(const std::string &str);

        // ----- print functions -----
        static bool printResult(char c, int i, float f, double d, bool isInf, bool isNan);

        // ----- helper functions -----
        static bool isSpecialFloat(const std::string &str);
        static bool isSpecialDouble(const std::string &str);
        static bool isPrintable(const char &c);
};

#endif
