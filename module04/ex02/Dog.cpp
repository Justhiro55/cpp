#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

Dog::Dog() : Animal("Dog"), brain(new Brain())
{
    std::cout << "Dog Constructor called" << std::endl;
}

Dog::Dog(const Dog &obj)
{
    if(this == &obj)
        return;
    this->brain = new Brain(*(obj.brain));
    std::cout << "Dog Copy Constructor called" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog Destructor called" << std::endl;
    delete this->brain;
}

Dog& Dog::operator=(const Dog &obj) {
    if (this != &obj) {
        Animal::operator=(obj);
        delete this->brain;
        this->brain = new Brain(*(obj.brain));
    }
    std::cout << "Dog Assignment Operator called" << std::endl;
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "bow wow" << std::endl;
}

std::string Dog::getBrainIdea(unsigned int index) const 
{
    if(index > 99)
    {
        std::cout << "index out of range" << std::endl;
        return "";
    }
    return brain->getIdea(index);
}

void Dog::setBrainIdea(unsigned int index, const std::string& idea) 
{
    if(index > 99)
    {
        std::cout << "index out of range" << std::endl;
        return;
    }
	this->brain->setIdea(idea, index);
}