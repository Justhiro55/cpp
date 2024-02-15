#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

Dog::Dog() : Animal("Dog"), brain(new Brain())
{
    std::cout << BLUE << "Dog Constructor called" << RESET << std::endl;
}

Dog::Dog(const Dog &obj)
{
    if(this == &obj)
        return;
    this->brain = new Brain(*(obj.brain));
    std::cout << BLUE << "Dog Copy Constructor called" << RESET << std::endl;
}

Dog::~Dog()
{
    std::cout << BLUE << "Dog Destructor called" << RESET << std::endl;
    delete this->brain;
}

Dog& Dog::operator=(const Dog &obj) {
    if (this != &obj) {
        Animal::operator=(obj);
        delete this->brain;
        this->brain = new Brain(*(obj.brain));
    }
    std::cout << BLUE << "Dog Assignment Operator called" << RESET << std::endl;
    return *this;
}

void Dog::makeSound() const
{
    std::cout << BLUE << "bow wow" << RESET << std::endl;
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