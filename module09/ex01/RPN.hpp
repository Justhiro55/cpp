#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>
#include <cmath>
#include <map>
#include <cctype>
#include <sstream>
#include <climits>
#include <stdexcept>
#include <vector>
#include <deque>
#include <list>
# include <fstream>

// ----- color code -----
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

// macros


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
        std::vector<int> _number;
};

bool istoken(const char token);

#endif
