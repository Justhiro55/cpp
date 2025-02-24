// AForm.cpp
#include "AForm.hpp"

// ----- orthodox canonical form -----
AForm::AForm()
    : _name("default_form"), _status(false), _grade_required_sign(150), _grade_required_execute(150)
{
    std::cout << "AForm Default Constructor called" << std::endl;
}

AForm::AForm(std::string name, bool status, int grade_required_sign, int grade_required_execute)
    : _name(name), _status(status), _grade_required_sign(grade_required_sign), _grade_required_execute(grade_required_execute)
{
    if (grade_required_execute < 1 || grade_required_sign < 1)
        throw AForm::GradeTooHighException();
    if (grade_required_execute > 150 || grade_required_sign > 150)
        throw AForm::GradeTooLowException();
    std::cout << "AForm Constructor called" << std::endl;
}

AForm::AForm(const AForm &obj)
    : _name(obj._name), _status(obj._status),
    _grade_required_sign(obj._grade_required_sign),
    _grade_required_execute(obj._grade_required_execute)
{
    std::cout << "AForm Copy Constructor called" << std::endl;
}

AForm::~AForm()
{
    std::cout << "AForm Destructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &obj)
{
    if (this != &obj)
    {
        this->_status = obj._status;
    }
    return *this;
}

// ----- AForm functions -----
void AForm::beSigned(Bureaucrat const &bureaucrat)
{
    if (bureaucrat.getGrade() <= this->_grade_required_sign)
    {
        if (this->_status == true)
            return ;
        this->_status = true;
    }
    else
    {
        throw AForm::GradeTooLowException();
    }
}

// ----- exception -----
const char * AForm::GradeTooLowException::what(void) const throw()
{
    return "Grade too low...";
}

const char * AForm::GradeTooHighException::what(void) const throw()
{
    return "Grade too high...";
}

const char * AForm::FormNotSignedException::what(void) const throw()
{
    return "Form not signed...";
}

// ----- getter -----
std::string AForm::getName() const {
    return this->_name;
}

bool AForm::getSigned() const {
    return this->_status;
}

int AForm::getGradeRequiredToSign() const {
    return this->_grade_required_sign;
}

int AForm::getGradeRequiredToExecute() const {
    return this->_grade_required_execute;
}

// ----- overload -----
std::ostream &operator<<(std::ostream &out, const AForm &obj)
{
    std::string is_signed = (obj.getSigned() ? "true" : "false");

    out << "AForm name: " << obj.getName() << std::endl
        << "sign grade: " << obj.getGradeRequiredToSign()
        << ", execute grade: " << obj.getGradeRequiredToExecute()
        << ", signed: " << is_signed << std::endl;

    return out;
}
