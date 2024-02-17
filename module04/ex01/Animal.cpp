#include "Animal.hpp"

Animal::Animal()
{
    std::cout << YELLOW << "Animal Default Constructor called" << RESET << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
    std::cout << YELLOW << "Animal Constructor called" << RESET << std::endl;
}

Animal::Animal(const Animal &obj)
{
    if (this == &obj)
        return;
    this->_type = obj._type;
    std::cout << YELLOW << "Animal Copy Constructor called" << RESET << std::endl;
}

Animal::~Animal()
{
    std::cout << YELLOW << "Animal Destructor called" << RESET << std::endl;
}

Animal &Animal::operator=(const Animal &obj)
{
    if (this != &obj)
    {
        this->_type = obj._type;
    }
    return *this;
}

std::string Animal::getType() const
{
    return this->_type;
}

void Animal::setType(std::string type)
{
    this->_type = type;
}

void Animal::makeSound() const
{
    std::cout << YELLOW << "(nothing...)" << RESET << std::endl;
}
