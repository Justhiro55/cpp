#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    this->_name = "default";
    this->_hitPoint = 100;
    this->_EnergyPoint = 100;
    this->_AttackDamage = 30;
    std::cout << "FragTrap " << this->_name <<" Constructor called" << std::endl; 
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->_hitPoint = 100;
    this->_EnergyPoint = 100;
    this->_AttackDamage = 30;
    std::cout << "FragTrap " << this->_name <<" Constructor called" << std::endl; 
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << this->_name << " Destructor called" << std::endl; 
}

void FragTrap::highFivesGuys(void)
{
    if (this->_EnergyPoint != 0 && this->_hitPoint != 0)
        std::cout << "FragTrap " << this->_name << " high five!" << std::endl;  
    else
		std::cout << "FragTrap " << this->_name << " can not move..." << std::endl;
}