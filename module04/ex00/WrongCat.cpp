#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << "WrongCat Constructor called" << std::endl;
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type)
{
    std::cout << "WrongCat " << type << " Constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &obj)
{
    if (this == &obj)
        return;
    this->_type = obj._type;
    std::cout << "WrongCat Copy Constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &obj)
{
    if (this != &obj)
    {
        this->_type = obj._type;
    }
    return *this;
}

void WrongCat::makeSound() const
{
    std::cout << "WrongCat(wrong)" << std::endl;
}
