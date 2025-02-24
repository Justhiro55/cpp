// ShrubberyCreationForm.hpp
#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <fstream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

class ShrubberyCreationForm : public AForm
{
    public:
        // Orthodox Canonical Form
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm& obj);
        virtual ~ShrubberyCreationForm();
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &obj);

        // exception class
        class GradeTooHighException : public std::exception
        {
            public:
                const char* what(void) const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what(void) const throw();
        };

        // member functions
        virtual void execute(const Bureaucrat &executor) const;

    private:
        std::string _target;
};

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &obj);

#endif
