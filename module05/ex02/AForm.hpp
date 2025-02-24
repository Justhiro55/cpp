// AForm.hpp
#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

class Bureaucrat;

class AForm
{
    public:
        // Orthodox Canonical Form
        AForm();
        AForm(std::string name, bool status, int grade_required_sign, int grade_required_execute);
        AForm(const AForm& obj);
        virtual ~AForm();
        AForm &operator=(const AForm &obj);

        // getter
        std::string getName() const;
        bool getSigned() const;
        int getGradeRequiredToSign() const;
        int getGradeRequiredToExecute() const;

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
        class FormNotSignedException : public std::exception
        {
            public:
                const char* what(void) const throw();
        };

        // AForm functions
        void beSigned(const Bureaucrat &bureaucrat);
        virtual void execute(Bureaucrat const &executor) const = 0;

    protected:
        const std::string _name;
        bool _status;
        const int _grade_required_sign;
        const int _grade_required_execute;
};

std::ostream &operator<<(std::ostream &out, const AForm &obj);

#endif
