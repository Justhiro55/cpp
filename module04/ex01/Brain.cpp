#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain Constructor called" << std::endl;
}

Brain::Brain(const Brain &obj) {
    if (this == &obj)
        return;
    *this = obj;
    std::cout << "Brain Constructor called" << std::endl;
}

Brain::~Brain() {
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

std::string Brain::getIdea(int index) const {
    return this->_ideas[index];
}

void Brain::setIdea(int index, const std::string& idea) {
    this->_ideas[index] = idea;
}