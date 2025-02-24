// Intern.hpp
#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

class Form;

class Intern
{
    public:
        // Orthodox Canonical Form
        Intern();
        Intern(const Intern& obj);
        virtual ~Intern();
        Intern &operator=(const Intern &obj);

        // Form creation function
        Form* makeForm(const std::string &form_name, const std::string &form_target);

        // Form exception class
        class FormNotFoundException : public std::exception {
            public:
                const char* what(void) const throw();
        };

    private:
        // Form creation methods
        Form* createShrubbery(const std::string &target) const;
        Form* createRobotomy(const std::string &target) const;
        Form* createPresidential(const std::string &target) const;
};

#endif
