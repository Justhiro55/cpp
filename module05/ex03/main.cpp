// main.cpp
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"

int main()
{
    std::cout << std::endl;
    std::cout << GREEN << "=== Testing Intern Class ===" << RESET << std::endl;

    // Test creating a valid form
    try
    {
        std::cout << YELLOW << "\n[Creating RobotomyRequestForm]" << RESET << std::endl;
        Intern someRandomIntern;
        Form* rrf;

        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        if (rrf)
        {
            Bureaucrat boss("Boss", 1);
            std::cout << *rrf << std::endl;
            boss.signForm(*rrf);
            boss.executeForm(*rrf);
            delete rrf;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    // Test creating a valid form
    try
    {
        std::cout << YELLOW << "\n[Creating PresidentialPardonForm]" << RESET << std::endl;
        Intern someRandomIntern;
        Form* ppf;

        ppf = someRandomIntern.makeForm("presidential pardon", "Criminal");
        if (ppf)
        {
            Bureaucrat boss("Boss", 1);
            std::cout << *ppf << std::endl;
            boss.signForm(*ppf);
            boss.executeForm(*ppf);
            delete ppf;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    // Test creating a valid form
    try
    {
        std::cout << YELLOW << "\n[Creating ShrubberyCreationForm]" << RESET << std::endl;
        Intern someRandomIntern;
        Form* scf;

        scf = someRandomIntern.makeForm("shrubbery creation", "Home");
        if (scf)
        {
            Bureaucrat boss("Boss", 1);
            std::cout << *scf << std::endl;
            boss.signForm(*scf);
            boss.executeForm(*scf);
            delete scf;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    // Test with invalid form name
    try
    {
        std::cout << YELLOW << "\n[Testing invalid form name]" << RESET << std::endl;
        Intern someRandomIntern;
        Form* form;

        form = someRandomIntern.makeForm("invalid form", "Target");
        if (form)
            delete form;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    std::cout << std::endl;
    return 0;
}

__attribute__((destructor))
static void destructor()
{
    system("leaks -q bureaucrat");
}
