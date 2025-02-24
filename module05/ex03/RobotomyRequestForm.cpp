// RobotomyRequestForm.cpp
#include "RobotomyRequestForm.hpp"

// ----- orthodox canonical form -----
RobotomyRequestForm::RobotomyRequestForm()
    : Form("RobotomyRequestForm", false, 72, 45), _target("default")
{
    std::cout << "RobotomyRequestForm Default Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : Form("RobotomyRequestForm", false, 72, 45), _target(target)
{
    std::cout << "RobotomyRequestForm Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj)
    : Form(obj), _target(obj._target)
{
    std::cout << "RobotomyRequestForm Copy Constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
    if (this != &obj)
    {
        Form::operator=(obj);
        this->_target = obj._target;
    }
    return *this;
}

// ----- member functions -----
void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    if (!this->getSigned())
        throw Form::FormNotSignedException();
    if (executor.getGrade() > this->getGradeRequiredToExecute())
        throw Form::GradeTooLowException();

    std::cout << "* drilling noises *" << std::endl;

    std::srand(std::time(NULL));
    if (std::rand() % 2)
        std::cout << this->_target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomization of " << this->_target << " failed." << std::endl;
}

// ----- exception -----
const char * RobotomyRequestForm::GradeTooLowException::what(void) const throw()
{
    return "Grade too low...";
}

const char * RobotomyRequestForm::GradeTooHighException::what(void) const throw()
{
    return "Grade too high...";
}

// ----- overload -----
std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &obj)
{
    std::string is_signed = (obj.getSigned() ? "true" : "false");

    out << "RobotomyRequestForm name: " << obj.getName() << std::endl
        << "sign grade: " << obj.getGradeRequiredToSign()
        << ", execute grade: " << obj.getGradeRequiredToExecute()
        << ", signed: " << is_signed << std::endl;

    return out;
}
