#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat Constructor called" << std::endl;
}

Cat::Cat(const Cat &obj)
{
    if(this == &obj)
        return;
    this->_type = obj._type;
    std::cout << "Cat Copy Constructor called" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat Destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &obj)
{
    if(this != &obj)
    {
        this->_type = obj._type;
    }
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "meow" << std::endl;
}

