#include "Form.hpp"

// ----- orthodox canonical form -----
Form::Form() : _name("default_form"), _status(false), _grade_required_sign(150), _grade_required_execute(150)
{
    std::cout << "Form Default Constructor called" << std::endl;
}

Form::Form(std::string name, bool status, int grade_required_sign, int grade_required_execute)
    : _name(name), _status(status), _grade_required_sign(grade_required_sign), _grade_required_execute(grade_required_execute)
{
    if (grade_required_execute < 1 || grade_required_sign < 1)
        throw Form::GradeTooHighException();
    if (grade_required_execute > 150 || grade_required_sign > 150)
        throw Form::GradeTooLowException();
    std::cout << "Form Constructor called" << std::endl;
}

Form::Form(const Form &obj) : _name(obj._name + "_copy"), _status(obj._status), _grade_required_sign(obj._grade_required_sign), _grade_required_execute(obj._grade_required_execute)
{
    std::cout << "Form Copy Constructor called" << std::endl;
}

Form::~Form()
{
    std::cout << "Form Destructor called" << std::endl;
}

Form &Form::operator=(const Form &obj) {
    if (this != &obj)
    {
        this->_status = obj._status;
    }
    return *this;
}

// ----- Form functions -----
void Form::beSigned(Bureaucrat const &bureaucrat)
{
    if (bureaucrat.getGrade() <= this->_grade_required_sign)
    {
        if (this->_status == true)
        {
            std::cout << bureaucrat.getName() << " couldn't sign " << this->getName()
                      << " because form is already signed" << std::endl;
            return ;
        }
        this->_status = true;
        std::cout << bureaucrat.getName() << " signed " << this->getName() << std::endl;
    }
    else
    {
        std::cout << bureaucrat.getName() << " couldn't sign " << this->getName()
                  << " because grade is too low" << std::endl;
        throw Form::GradeTooLowException();
    }
}

// ----- exception -----
const char * Form::GradeTooLowException::what(void) const throw()
{
	return "Grade too low...";
}

const char * Form::GradeTooHighException::what(void) const throw()
{
	return "Grade too high...";
}

// ----- getter -----
std::string Form::getName() const {
    return this->_name;
}

bool Form::getSigned() const {
    return this->_status;
}

int Form::getGradeRequiredToSign() const {
    return this->_grade_required_sign;
}

int Form::getGradeRequiredToExecute() const {
    return this->_grade_required_execute;
}

// ----- overload -----
std::ostream &operator<<(std::ostream &out, const Form &obj)
{
    std::string is_signed;
    if (obj.getSigned() == false) {
        is_signed = "false";
    } else {
        is_signed = "true";
    }
    out << "Form name: " << obj.getName() << std::endl
    << "sign grade: " << obj.getGradeRequiredToSign()
    << ", execute grade: " << obj.getGradeRequiredToExecute() <<
    ", signed: " << is_signed << std::endl;

    return out;
}
