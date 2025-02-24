// ShrubberyCreationForm.cpp
#include "ShrubberyCreationForm.hpp"

// ----- orthodox canonical form -----
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", false, 145, 137), _target("default")
{
    std::cout << "ShrubberyCreationForm Default Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("ShrubberyCreationForm", false, 145, 137), _target(target)
{
    std::cout << "ShrubberyCreationForm Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj)
    : AForm(obj), _target(obj._target)
{
    std::cout << "ShrubberyCreationForm Copy Constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
    if (this != &obj)
    {
        AForm::operator=(obj);
        this->_target = obj._target;
    }
    return *this;
}

// ----- member functions -----
void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    if (!this->getSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getGradeRequiredToExecute())
        throw AForm::GradeTooLowException();

    std::ofstream ofs((this->_target + "_shrubbery").c_str());
    if (!ofs.is_open())
        throw std::runtime_error("Cannot create file");

    ofs << "       _-_" << std::endl;
    ofs << "    /~~   ~~\\" << std::endl;
    ofs << " /~~         ~~\\" << std::endl;
    ofs << "{               }" << std::endl;
    ofs << " \\  _-     -_  /" << std::endl;
    ofs << "   ~  \\ //  ~" << std::endl;
    ofs << "_- -   | | _- _" << std::endl;
    ofs << "  _ -  | |   -_" << std::endl;
    ofs << "      // \\" << std::endl;

    ofs.close();
}

// ----- exception -----
const char * ShrubberyCreationForm::GradeTooLowException::what(void) const throw()
{
    return "Grade too low...";
}

const char * ShrubberyCreationForm::GradeTooHighException::what(void) const throw()
{
    return "Grade too high...";
}

// ----- overload -----
std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &obj)
{
    std::string is_signed = (obj.getSigned() ? "true" : "false");

    out << "ShrubberyCreationForm name: " << obj.getName() << std::endl
        << "sign grade: " << obj.getGradeRequiredToSign()
        << ", execute grade: " << obj.getGradeRequiredToExecute()
        << ", signed: " << is_signed << std::endl;

    return out;
}
