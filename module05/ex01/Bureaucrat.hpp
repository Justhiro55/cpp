#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <cstdlib>
#include "Form.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

class Form;

class Bureaucrat
{
    public:
        // Orthodox Canonical Form,
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
    	Bureaucrat(const Bureaucrat& obj);
        virtual ~Bureaucrat();
        Bureaucrat &operator=(const Bureaucrat &obj);

        // getter
        int getGrade() const;
        std::string getName() const;

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

        // bureaucrat functions
        void signForm(Form &obj);
        void incrementGrade();
        void decrementGrade();

    private:
        std::string _name;
        int _grade;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj);

#endif
