#include "Brain.hpp"

Brain::Brain() {
    this->_ideas = new std::string[100];
    std::cout << "Brain Constructor called" << std::endl;
}

Brain::Brain(const Brain &obj) {
    if (this == &obj)
        return;
    this->_ideas = new std::string[100];
    for (int i = 0; i < 100; i++) {
    this->_ideas[i] = obj._ideas[i];
    }
    std::cout << "Brain Constructor called" << std::endl;
}

Brain::~Brain() {
    if (_ideas)
        delete[] _ideas;
    std::cout << "Brain Destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &obj) {
    if (this != &obj) {
        for (int i = 0; i < 100; i++) {
            this->_ideas[i] = obj._ideas[i];
        }
    }
    return *this;
}

std::string Brain::getIdea(unsigned int index) const {
    if (index > 99) {
    std::cout << "Index out of range..." << std::endl;
    return "";
    }
    return this->_ideas[index];
}

void Brain::setIdea(std::string idea, unsigned int index)
{
    if (index > 99) {
        std::cout << "Index out of range..." << std::endl;
        return;
    }
    this->_ideas[index] = idea;
}