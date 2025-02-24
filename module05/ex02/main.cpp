#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        std::cout << std::endl;
        std::cout << GREEN << "=== Testing ShrubberyCreationForm ===" << RESET << std::endl;

        Bureaucrat bureaucrat("bureaucrat", 137);
        ShrubberyCreationForm shrubbery("garden");

        std::cout << bureaucrat << std::endl;
        std::cout << shrubbery << std::endl;

        bureaucrat.signForm(shrubbery);
        bureaucrat.executeForm(shrubbery);
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    try
    {
        std::cout << std::endl;
        std::cout << GREEN << "=== Testing RobotomyRequestForm ===" << RESET << std::endl;

        Bureaucrat bureaucrat("bureaucrat", 45);
        RobotomyRequestForm robotomy("target");

        std::cout << bureaucrat << std::endl;
        std::cout << robotomy << std::endl;

        bureaucrat.signForm(robotomy);
        bureaucrat.executeForm(robotomy);
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    try
    {
        std::cout << std::endl;
        std::cout << GREEN << "=== Testing PresidentialPardonForm ===" << RESET << std::endl;

        Bureaucrat bureaucrat("bureaucrat", 5);
        PresidentialPardonForm pardon("criminal");

        std::cout << bureaucrat << std::endl;
        std::cout << pardon << std::endl;

        bureaucrat.signForm(pardon);
        bureaucrat.executeForm(pardon);
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    std::cout << std::endl;
    std::cout << GREEN << "=== Testing Error Cases ===" << RESET << std::endl;

    // Test 1: Grade too low to execute
    try
    {
        Bureaucrat low("low", 150);
        ShrubberyCreationForm shrubbery("test");

        low.signForm(shrubbery);
        low.executeForm(shrubbery);
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    // Test 2: Executing unsigned form
    try
    {
        Bureaucrat high("high", 1);
        RobotomyRequestForm robotomy("test");

        high.executeForm(robotomy);
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    std::cout << std::endl;
    return 0;
}

// __attribute__((destructor))
// static void destructor()
// {
//     system("leaks -q bureaucrat");
// }
