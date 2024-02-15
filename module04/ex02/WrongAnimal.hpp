#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
    public:
        WrongAnimal();
        WrongAnimal(std::string name);
    	WrongAnimal(const WrongAnimal& obj);
        virtual ~WrongAnimal();
        WrongAnimal &operator=(const WrongAnimal &obj);
        std::string getType() const;
        void setType(std::string type);
        void makeSound() const;
    protected:
        std::string _type;
};

#endif