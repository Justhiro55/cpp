#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    this->_name = "default";
    this->_hitPoint = 100;
    this->_energyPoint = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap " << this->_name <<" Constructor called" << std::endl; 
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->_hitPoint = 100;
    this->_energyPoint = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap " << this->_name <<" Constructor called" << std::endl; 
}

ScavTrap::ScavTrap(const ScavTrap& obj)
{
    this->_name = obj._name;
    this->_attackDamage = obj._attackDamage;
    this->_energyPoint = obj._energyPoint;
    this->_hitPoint = obj._hitPoint;
    std::cout << "ScavTrap " << this->_name <<" Constructor called" << std::endl; 
}

ScavTrap& ScavTrap::operator=(const ScavTrap &obj)
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

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << this->_name << " Destructor called" << std::endl; 
}

void ScavTrap::guardGate()
{
	if (this->_hitPoint == 0 || this->_energyPoint == 0)
	{
		std::cout << "ScavTrap " << this->_name << " can not move..." << std::endl;
	}
	else
	{
		std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode" << std::endl;
		this->_energyPoint--;
	}
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_hitPoint == 0 || this->_energyPoint == 0)
	{
		std::cout << "ScavTrap " << this->_name << " can't move..." << std::endl;
	}
	else
	{
		std::cout	<< "ScavTrap " << this->_name << " attacks " << target 
					<< ", causing " << this->_attackDamage << " points of damage!"
					<< std::endl;
		this->_energyPoint--;
	}
}
