#include "ScalarConverter.hpp"
#include <iomanip>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &src) {
    (void)src;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj) {
    (void)obj;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isChar(const std::string &str) {
    return (str.length() == 3 && str[0] == '\'' && str[2] == '\'');
}

bool ScalarConverter::isInt(const std::string &str) {
    if (str.empty())
        return false;

    size_t i = 0;
    if (str[0] == '+' || str[0] == '-')
        i++;

    for (; i < str.length(); i++) {
        if (!isdigit(str[i]))
            return false;
    }

    char *end;
    long value = std::strtol(str.c_str(), &end, 10);

    return (value <= INT_MAX && value >= INT_MIN);
}


bool ScalarConverter::isFloat(const std::string &str) {
    if (str.empty())
        return false;

    if (isSpecialFloat(str))
        return true;

    if (str[str.length() - 1] != 'f')
        return false;

    std::string numPart = str.substr(0, str.length() - 1);

    if (numPart.find('.') == std::string::npos) {
        return false;
    }

    size_t i = 0;
    if (numPart[0] == '+' || numPart[0] == '-')
        i++;

    bool pointSeen = false;

    for (; i < numPart.length(); i++) {
        if (numPart[i] == '.') {
            if (pointSeen)
            return false;
            pointSeen = true;
        } else if (!isdigit(numPart[i])) {
            return false;
        }
    }

    return true;
}

bool ScalarConverter::isDouble(const std::string &str) {
    if (str.empty())
    return false;

    if (isSpecialDouble(str))
        return true;

    bool isPointSeen = false;
    size_t i = 0;

    if (str[0] == '+' || str[0] == '-')
    i++;

    for (; i < str.length(); i++) {
        if (str[i] == '.') {
            if (isPointSeen)
                return false;
            isPointSeen = true;
            continue;
        }

        if (!isdigit(str[i]))
            return false;
    }

    return true;
}

bool ScalarConverter::printResult(char c, int i, float f, double d, bool isInf, bool isNan) {
    std::cout << CYAN << "char: " << RESET;
    if (isPrintable(c))
        std::cout << GREEN << "'" << c << "'" << RESET << std::endl;
    else
        std::cout << RED << "Non displayable" << RESET << std::endl;

    std::cout << CYAN << "int: " << RESET;
    if (isInf || isNan) {
        std::cout << RED << "impossible" << RESET << std::endl;
    } else {
        std::cout << GREEN << i << RESET << std::endl;
    }

    std::cout << CYAN << "float: " << RESET;
    if (isNan) {
        std::cout << GREEN << "nanf" << RESET << std::endl;
    } else if (isInf) {
        if (f < 0) {
            std::cout << GREEN << "-inff" << RESET << std::endl;
        } else {
            std::cout << GREEN << "+inff" << RESET << std::endl;
        }
    } else {
        std::cout << GREEN << f;
        if (f == static_cast<int>(f))
        std::cout << ".0";
        std::cout << "f" << RESET << std::endl;
    }

    std::cout << CYAN << "double: " << RESET;
    if (isNan) {
        std::cout << GREEN << "nan" << RESET << std::endl;
    } else if (isInf) {
        if (d < 0) {
            std::cout << GREEN << "-inf" << RESET << std::endl;
        } else {
            std::cout << GREEN << "+inf" << RESET << std::endl;
        }
    } else {
        std::cout << GREEN << d;
        if (d == static_cast<int>(d))
        std::cout << ".0";
        std::cout << RESET << std::endl;
    }

    return true;
}

void ScalarConverter::convert(const std::string &str) {
    char c;
    int i;
    float f;
    double d;

    if (isChar(str)) {
        c = str[1];
        i = static_cast<int>(c);
        f = static_cast<float>(c);
        d = static_cast<double>(c);
    } else if (isInt(str)) {
        i = std::atoi(str.c_str());
        c = static_cast<char>(i);
        f = static_cast<float>(i);
        d = static_cast<double>(i);
    } else if (isFloat(str)) {
        f = std::strtof(str.c_str(), NULL);
        c = static_cast<char>(f);
        i = static_cast<int>(f);
        d = static_cast<double>(f);
    } else if (isDouble(str)) {
        d = std::strtod(str.c_str(), NULL);
        c = static_cast<char>(d);
        i = static_cast<int>(d);
        f = static_cast<float>(d);
    } else {
        std::cout << RED << "Error: Invalid input" << RESET << std::endl;
        return;
    }

    printResult(c, i, f, d, isinf(f), isnan(f));
}

// ----- helper functions -----
bool ScalarConverter::isSpecialFloat(const std::string &str) {
    return (str == "+inff" || str == "-inff" || str == "nanf");
}

bool ScalarConverter::isSpecialDouble(const std::string &str) {
    return (str == "+inf" || str == "-inf" || str == "nan");
}

bool ScalarConverter::isPrintable(const char &c) {
    return (isprint(c) && 31 < c && int(c) < 128);
}
