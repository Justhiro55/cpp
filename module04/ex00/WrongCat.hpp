#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : virtual public WrongAnimal
{
    public:
        WrongCat();
        WrongCat(std::string name);
    	WrongCat(const WrongCat& obj);
        ~WrongCat();
        WrongCat &operator=(const WrongCat &obj);
        void makeSound() const;
};

#endif