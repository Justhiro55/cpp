#include "RPN.hpp"

bool isValidExpression(const std::string& expression)
{
    // check: empty
    if (expression.empty())
        exit(EXIT_SUCCESS);

    // check: first or last character
    if (!isdigit(expression[0]) && expression[0] != '-')
        return false;
    else if (expression[expression.length() - 1] == ' ')
        return false;

    for (size_t i = 0; i < expression.length() - 1; ++i)
    {
        // check: invalid character
        if (!isdigit(expression[i]) && !istoken(expression[i]) && expression[i] != ' ')
            return false;

        // check: sequence of spaces
        if (expression[i] == ' ' && expression[i + 1] == ' ')
            return false;
        // check: sequence of not space
        else if (expression[i] != ' ' && expression[i + 1] != ' ')
            return false;

    }
    return true;
}

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cerr << RED;
        std::cerr << "Error: wrong number of arguments" << std::endl;
        std::cerr << "Usage: " << av[0] << " <expression>" << std::endl;
        return EXIT_FAILURE;
    }

    if (!isValidExpression(av[1])) {
        std::cerr << RED << "Error" << RESET << std::endl;
        return EXIT_FAILURE;
    }

    RPN rpn;
    std::string expression(av[1]);
    rpn.calculate(expression);

    return EXIT_SUCCESS;
}
