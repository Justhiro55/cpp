#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog Constructor called" << std::endl;
}

Dog::Dog(std::string type) : Animal(type)
{
    std::cout << "Dog Constructor called" << std::endl;
}

Dog::Dog(const Dog &obj)
{
    if(this == &obj)
        return;
    this->_type = obj._type;
    std::cout << "Dog Constructor called" << std::endl;
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

std::string Dog::getBrainIdea(int index) const 
{
    return brain->getIdea(index);
}

void Dog::setBrainIdea(int index, const std::string& idea) 
{
    brain->setIdea(index, idea);
}