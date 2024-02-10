#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat Constructor called" << std::endl;
}

Cat::Cat(std::string type) : Animal(type)
{
    std::cout << "Cat Constructor called" << std::endl;
}

Cat::Cat(const Cat &obj)
{
    if(this == &obj)
        return;
    this->_type = obj._type;
    std::cout << "Cat Constructor called" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat Destructor called" << std::endl;
    delete this->brain;
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

std::string Cat::getBrainIdea(int index) const 
{
    return brain->getIdea(index);
}

void Cat::setBrainIdea(int index, const std::string& idea) 
{
    brain->setIdea(idea, index);
}