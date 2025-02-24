#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try{
        std::cout << std::endl;
        std::cout << GREEN << "=== Basic Test ===" << RESET << std::endl;

        Bureaucrat bureaucrat("bureaucrat", 5);
        std::cout << bureaucrat << std::endl;

        Form form("test_form", false, 150, 150);
        std::cout << GREEN << "[Original Form]" << RESET << std::endl;
        std::cout << form << std::endl;

        Form form_copy;
        form_copy = form;
        std::cout << GREEN << "[Copied Form]" << RESET << std::endl;
        std::cout << form_copy << std::endl;

        std::cout << GREEN << "[Signing Form]" << RESET << std::endl;
        bureaucrat.signForm(form);
        std::cout << form << std::endl;

    } catch (std::exception &e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    std::cout << GREEN << "=== Error Cases ===" << RESET << std::endl;
    // Test 1: Grade too low for bureaucrat
    try {
        std::cout << YELLOW << "[Test 1: Grade too low]" << RESET << std::endl;
        Bureaucrat toolow("toolow", 151);
    } catch (std::exception &e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    // Test 2: Grade too high for bureaucrat
    try {
        std::cout << YELLOW << "[Test 2: Grade too high]" << RESET << std::endl;
        Bureaucrat toohigh("toohigh", 0);
    } catch (std::exception &e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    // Test 3: Form sign grade too low
    try {
        std::cout << YELLOW << "[Test 3: Form sign grade too low]" << RESET << std::endl;
        Form invalid("invalid", false, 151, 150);
    } catch (std::exception &e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    // Test 4: Bureaucrat cannot sign form
    try {
        std::cout << YELLOW << "[Test 4: Cannot sign form]" << RESET << std::endl;
        Bureaucrat low("low", 150);
        Form high("high", false, 1, 1);
        low.signForm(high);
    } catch (std::exception &e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    return 0;
}

// 	__attribute__((destructor))
// static void destructor()
// {
//     system("leaks -q bureaucrat");
// }
