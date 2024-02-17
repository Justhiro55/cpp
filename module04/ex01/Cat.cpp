#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

Cat::Cat() : Animal("Dog"), brain(new Brain())
{
    std::cout << GREEN << "Cat Constructor called" << RESET << std::endl;
}

Cat::Cat(const Cat &obj)
{
    if(this == &obj)
        return;
    this->_type = obj._type;
	this->brain = new Brain(*obj.brain);
    std::cout << GREEN << "Cat Copy Constructor called" << RESET << std::endl;
}

Cat::~Cat()
{
    std::cout << GREEN << "Cat Destructor called" << RESET << std::endl;
    delete this->brain;
}

Cat& Cat::operator=(const Cat &obj)
{
    if(this != &obj)
    {
        Animal::operator=(obj);
        delete this->brain;
        this->brain = new Brain(*(obj.brain));
    }
    return *this;
}

void Cat::makeSound() const
{
    std::cout << GREEN << "meow" << RESET << std::endl;
}

std::string Cat::getBrainIdea(unsigned int index) const 
{
    if(index > 99)
    {
        std::cout << "index out of range" << std::endl;
        return "";
    }
    return brain->getIdea(index);
}

void Cat::setBrainIdea(unsigned int index, const std::string& idea) 
{
    if(index > 99)
    {
        std::cout << "index out of range" <<std::endl;
        return;
    }
	this->brain->setIdea(idea, index);
}