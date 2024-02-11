#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

Dog::Dog() : Animal("Dog"), brain(new Brain())
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
    this->brain = new Brain(*(obj.brain));
    std::cout << "Dog Constructor called" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog Destructor called" << std::endl;
    delete this->brain;
}

Dog& Dog::operator=(const Dog &obj)
{
    if(this != &obj)
    {
        this->_type = obj._type;
        delete this->brain;
        this->brain = new Brain(*(obj.brain));
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
	// for (int i = 0; i < 100; i++) {
	// 	if (this->brain->getIdea(i) == "") {
	// 		this->brain->setIdea(idea, i);
	// 		return;
	// 	}
	// }
	this->brain->setIdea(idea, index);
	std::cout << "Brain of cat is full!" << std::endl;
}