#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <cstdlib>
#include <string>
#include <stdexcept>
#include <cctype>
#include <stack>

// ----- color code -----
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

// ----- Class -----
class RPN
{
    public:
        // ----- constructor -----
        RPN();
        RPN(const RPN &obj);
        RPN &operator=(const RPN &obj);
        ~RPN();

        // ----- member functions -----
        void calculate(std::string &input);
        int executeOperator(int a, int b, char op);

    private:
        std::stack<int> _number;
};

bool istoken(const char token);

#endif
