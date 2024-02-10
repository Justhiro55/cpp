#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : virtual public Animal {
    public:
        Dog();
        Dog(std::string name);
        Dog(const Dog& obj);
        ~Dog();
        Dog &operator=(const Dog &obj);
        void makeSound() const;
        std::string getBrainIdea(int index) const;
        void setBrainIdea(int index, const std::string& idea);
    private:
        Brain* brain;
};

#endif