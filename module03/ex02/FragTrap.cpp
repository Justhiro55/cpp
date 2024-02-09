#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    this->_name = "default";
    this->_hitPoint = 100;
    this->_energyPoint = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap " << this->_name <<" Constructor called" << std::endl; 
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->_hitPoint = 100;
    this->_energyPoint = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap " << this->_name <<" Constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& obj)
{
    this->_name = obj._name;
    this->_attackDamage = obj._attackDamage;
    this->_energyPoint = obj._energyPoint;
    this->_hitPoint = obj._hitPoint;
    std::cout << "FragTrap " << this->_name <<" Constructor called" << std::endl; 
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << this->_name << " Destructor called" << std::endl; 
}

FragTrap& FragTrap::operator=(const FragTrap &obj)
{
    if(this != &obj)
    {
        this->_name = obj._name;
        this->_attackDamage = obj._attackDamage;
        this->_energyPoint = obj._energyPoint;
        this->_hitPoint = obj._hitPoint;
    }
    return *this;
}

void FragTrap::highFivesGuys(void)
{
    if (this->_energyPoint != 0 && this->_hitPoint != 0)
        std::cout << "FragTrap " << this->_name << " high five!" << std::endl;  
    else
		std::cout << "FragTrap " << this->_name << " can not move..." << std::endl;
}