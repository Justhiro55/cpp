#include <iostream>
#include <string>
#include "whatever.hpp"

int main(void)
{
    int a = 2;
    int b = 3;

    std::cout << CYAN << "\n--- Standard test ---" << RESET << std::endl;
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
    std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

    std::cout << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";

    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
    std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

    int x = 42;
    int y = 42;
    std::cout << CYAN << "\n--- Equal values test ---" << RESET << std::endl;
    std::cout << "x = " << x << ", y = " << y << std::endl;

    std::cout << "Address of x: " << &x << std::endl;
    std::cout << "Address of y: " << &y << std::endl;

    std::cout << std::endl;

    std::cout << "Address of min(x, y): " << &::min(x, y) << std::endl;
    std::cout << "Address of max(x, y): " << &::max(x, y) << std::endl;

    y = 43;
    std::cout << "\nAfter changing y to 43:" << std::endl;
    std::cout << "min(x, y) = " << ::min(x, y) << std::endl;
    std::cout << "max(x, y) = " << ::max(x, y) << std::endl;

    return 0;
}