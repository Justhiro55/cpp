#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal Constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
    std::cout << "Animal Constructor called" << std::endl;
}

Animal::Animal(const Animal &obj)
{
    if (this == &obj)
        return;
    *this = obj;
    std::cout << "Animal Copy Constructor called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal Destructor called" << std::endl;
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
    std::cout << "(nothing...)" << std::endl;
}
