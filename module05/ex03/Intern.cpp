// Intern.cpp
#include "Intern.hpp"

// ----- orthodox canonical form -----
Intern::Intern()
{
    std::cout << "Intern Default Constructor called" << std::endl;
}

Intern::Intern(const Intern &obj)
{
    (void)obj;
    std::cout << "Intern Copy Constructor called" << std::endl;
}

Intern::~Intern()
{
    std::cout << "Intern Destructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &obj) {
    (void)obj;
    return *this;
}

// ----- main function -----
Form* Intern::makeForm(const std::string &form_name, const std::string &form_target)
{
    std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    Form* (Intern::*formCreators[3])(const std::string &) const = {
        &Intern::createShrubbery,
        &Intern::createRobotomy,
        &Intern::createPresidential
    };

    for (int i = 0; i < 3; i++)
    {
        if (form_name == formNames[i])
        {
            Form* form = (this->*formCreators[i])(form_target);
            std::cout << "Intern creates " << form_name << std::endl;
            return form;
        }
    }

    throw Intern::FormNotFoundException();
}

// ----- formCreators -----
Form* Intern::createShrubbery(const std::string &target) const
{
    return new ShrubberyCreationForm(target);
}

Form* Intern::createRobotomy(const std::string &target) const
{
    return new RobotomyRequestForm(target);
}

Form* Intern::createPresidential(const std::string &target) const
{
    return new PresidentialPardonForm(target);
}

// ----- exception -----
const char * Intern::FormNotFoundException::what(void) const throw()
{
    return "Form not found...";
}
