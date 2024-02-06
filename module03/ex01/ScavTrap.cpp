#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    this->_name = "default";
    this->_HitPoint = 100;
    this->_EnergyPoint = 50;
    this->_AttackDamage = 20;
    std::cout << "ScavTrap " << this->_name <<" Constructor called" << std::endl; 
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->_HitPoint = 100;
    this->_EnergyPoint = 50;
    this->_AttackDamage = 20;
    std::cout << "ScavTrap " << this->_name <<" Constructor called" << std::endl; 
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << this->_name << " Destructor called" << std::endl; 
}

void ScavTrap::guardGate()
{
	if (this->_HitPoint == 0 || this->_EnergyPoint == 0)
	{
		std::cout << "ScavTrap " << this->_name << " can not move..." << std::endl;
	}
	else
	{
		std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode" << std::endl;
		this->_EnergyPoint--;
	}
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_HitPoint == 0 || this->_EnergyPoint == 0)
	{
		std::cout << "ScavTrap " << this->_name << " can't move..." << std::endl;
	}
	else
	{
		std::cout	<< "ScavTrap " << this->_name << " attacks " << target 
					<< ", causing " << this->_AttackDamage << " points of damage!"
					<< std::endl;
		this->_EnergyPoint--;
	}
}
