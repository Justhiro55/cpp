#include "RPN.hpp"

// ----- constructor -----
RPN::RPN() {
}

RPN::RPN(const RPN &obj) {
    *this = obj;
}

RPN &RPN::operator=(const RPN &obj) {
    if (this != &obj) {
        this->_number = obj._number;
    }
    return *this;
}

RPN::~RPN() {}

// ----- member functions -----
int RPN::executeOperator(int a, int b, char op) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b == 0)
                throw std::runtime_error("division by zero");
            return a / b;
        default:
            throw std::invalid_argument("Invalid operator");
    }
}

void RPN::calculate(std::string &input) {
    try {
        for (size_t i = 0; i < input.length(); ++i) {
            if (isdigit(input[i])) {
                int num = input[i] - '0';
                if (num < 0 || num > 9)
                    throw std::out_of_range("Number out of range");
                this->_number.push(num);
            } else if (istoken(input[i])) {
                if (this->_number.size() < 2)
                    throw std::runtime_error("Not enough operands");

                int b = this->_number.top();
                this->_number.pop();
                int a = this->_number.top();
                this->_number.pop();

                int result = executeOperator(a, b, input[i]);
                this->_number.push(result);
            }
        }
        if (this->_number.size() != 1)
            throw std::runtime_error("Invalid expression");
    } catch (const std::exception &e) {
        std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
        exit(EXIT_FAILURE);
    }
    std::cout << this->_number.top() << RESET << std::endl;
}

// ----- helper functions -----
bool istoken(const char token)
{
    return (token == '+' || token == '-' || token == '*' || token == '/');
}
