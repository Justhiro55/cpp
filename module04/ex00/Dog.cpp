#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog Constructor called" << std::endl;
}

Dog::Dog(const Dog &obj)
{
    if(this == &obj)
        return;
    this->_type = obj._type;
    std::cout << "Dog Copy Constructor called" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog Destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog &obj)
{
    if(this != &obj)
    {
        this->_type = obj._type;
    }
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "bow wow" << std::endl;
}
