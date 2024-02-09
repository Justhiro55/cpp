#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : virtual public Animal
{
    public:
        Cat();
        Cat(std::string name);
    	Cat(const Cat& obj);
        ~Cat();
        Cat &operator=(const Cat &obj);
        void makeSound() const;
};

#endif