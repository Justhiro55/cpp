#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat Constructor called" << std::endl;
	this->_type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(std::string type)
{
    std::cout << "Cat Constructor called" << std::endl;
	this->_type = type;
	this->brain = new Brain();
}

Cat::Cat(const Cat &obj)
{
    if(this == &obj)
        return;
    this->_type = obj._type;
	this->brain = new Brain(*obj.brain);
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
        Animal::operator=(obj);
        delete this->brain;
        this->brain = new Brain(*(obj.brain));
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
	// for (int i = 0; i < 100; i++) {
	// 	if (this->brain->getIdea(i) == "") {
	// 		this->brain->setIdea(idea, i);
	// 		return;
	// 	}
	// }
	this->brain->setIdea(idea, index);
	// std::cout << "Brain of cat is full!" << std::endl;
}