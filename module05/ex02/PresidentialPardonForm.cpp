// PresidentialPardonForm.cpp
#include "PresidentialPardonForm.hpp"

// ----- orthodox canonical form -----
PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", false, 25, 5), _target("default")
{
    std::cout << "PresidentialPardonForm Default Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("PresidentialPardonForm", false, 25, 5), _target(target)
{
    std::cout << "PresidentialPardonForm Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj)
    : AForm(obj), _target(obj._target)
{
    std::cout << "PresidentialPardonForm Copy Constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm Destructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj)
{
    if (this != &obj)
    {
        AForm::operator=(obj);
        this->_target = obj._target;
    }
    return *this;
}

// ----- member functions -----
void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    if (!this->getSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getGradeRequiredToExecute())
        throw AForm::GradeTooLowException();

    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

// ----- exception -----
const char * PresidentialPardonForm::GradeTooLowException::what(void) const throw()
{
    return "Grade too low...";
}

const char * PresidentialPardonForm::GradeTooHighException::what(void) const throw()
{
    return "Grade too high...";
}

// ----- overload -----
std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &obj)
{
    std::string is_signed = (obj.getSigned() ? "true" : "false");

    out << "PresidentialPardonForm name: " << obj.getName() << std::endl
        << "sign grade: " << obj.getGradeRequiredToSign()
        << ", execute grade: " << obj.getGradeRequiredToExecute()
        << ", signed: " << is_signed << std::endl;

    return out;
}
