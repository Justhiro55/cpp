#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : virtual public Animal
{
    public:
        Dog();
        Dog(std::string name);
    	Dog(const Dog& obj);
        ~Dog();
        Dog &operator=(const Dog &obj);
        void makeSound() const;
};

#endif