#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

class Animal
{
    public:
        Animal();
        Animal(std::string name);
    	Animal(const Animal& obj);
        virtual ~Animal();
        Animal &operator=(const Animal &obj);
        std::string getType() const;
        void setType(std::string type);
        virtual void makeSound() const = 0;
    protected:
        std::string _type;
};

#endif