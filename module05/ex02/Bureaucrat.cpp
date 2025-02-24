#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default_bureaucrat"), _grade(150)
{
    std::cout << "Bureaucrat Default Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade = grade;
    std::cout << "Bureaucrat Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj)
    : _name(obj._name), _grade(obj._grade)
{
    if (_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (_grade > 150)
        throw Bureaucrat::GradeTooLowException();
    std::cout << "Bureaucrat Copy Constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat Destructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj) {
    if (this != &obj)
    {
        this->_grade = obj._grade;
    }
    return *this;
}

const char * Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return "Grade too low...";
}

const char * Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return "Grade too high...";
}

int Bureaucrat::getGrade() const {
    return this->_grade;
}

std::string Bureaucrat::getName() const {
    return this->_name;
}

void Bureaucrat::signForm(AForm &obj)
{
    try
    {
        obj.beSigned(*this);
        std::cout << this->getName() << " signed " << obj.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << this->getName() << " couldn't sign " << obj.getName()
                  << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form) const
{
    try
    {
        form.execute(*this);
        std::cout << this->_name << " executed " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << this->_name << " couldn't execute " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::incrementGrade()
{
    if (this->_grade <= 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade--;
}

void Bureaucrat::decrementGrade()
{
    if (this->_grade >= 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade++;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj)
{
    out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "." << std::endl;
    return out;
}
