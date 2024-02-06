#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    this->_name = "default";
    this->_HitPoint = 10;
    this->_EnergyPoint = 10;
    this->_AttackDamage = 10;
    std::cout << "ClapTrap " << this->_name <<" Constructor called" << std::endl; 
}

ClapTrap::ClapTrap(std::string name)
{
    this->_name = name;
    this->_HitPoint = 10;
    this->_EnergyPoint = 10;
    this->_AttackDamage = 10;
    std::cout << "ClapTrap " << this->_name <<" Constructor called" << std::endl; 
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << this->_name << " Destructor called" << std::endl; 
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_HitPoint == 0 || this->_EnergyPoint == 0)
	{
		std::cout << "ClapTrap " << this->_name << " can't move..." << std::endl;
	}
	else
	{
		std::cout	<< "ClapTrap " << this->_name << " attacks " << target 
					<< ", causing " << this->_AttackDamage << " points of damage!"
					<< std::endl;
		this->_EnergyPoint--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if ( amount > this->_HitPoint)
        this->_HitPoint = 0;
    else
        this->_HitPoint -= amount;
    std::cout << "ClapTrap " << this->_name \
        << " has taken " << amount << " damage"
        << std::endl; 
    if ( this -> _HitPoint == 0 )
        std::cout << "ClapTrap " << this->_name << " is died" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_HitPoint == 0 || this->_EnergyPoint == 0)
    {
		std::cout << "ClapTrap " << this->_name << " can't move..." << std::endl;
    }
    else
    {
        this->_HitPoint += amount;
        this->_EnergyPoint--;
		std::cout << "ClapTrap " << this->_name << " is repaired " \
            << amount << " hit point" << std::endl;
    }
}

