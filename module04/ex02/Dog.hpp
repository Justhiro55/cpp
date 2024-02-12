#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : virtual public Animal {
    public:
        Dog();
        Dog(const Dog& obj);
        ~Dog();
        Dog &operator=(const Dog &obj);
        void makeSound() const;
        std::string getBrainIdea(unsigned int index) const;
        void setBrainIdea(unsigned int index, const std::string& idea);
    private:
        Brain* brain;
};

#endif