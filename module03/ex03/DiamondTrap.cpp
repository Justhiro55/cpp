#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void): ClapTrap("default_clap_trap")
{
	this->_name = "default";
	this->_hitPoint = FragTrap::_hitPoint;
	this->_EnergyPoint = ScavTrap::_EnergyPoint;
	this->_AttackDamage = FragTrap::_AttackDamage;
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) {
    this->_name = name;
    this->_hitPoint = FragTrap::_hitPoint;
    this->_EnergyPoint = ScavTrap::_EnergyPoint;
    this->_AttackDamage = FragTrap::_AttackDamage;
    std::cout << "DiamondTrap " << this->_name << " Constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << this->_name << " Destructor called" << std::endl; 
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void) {
    std::cout << "I am " << this->_name << ", also known as " << ClapTrap::_name << " in ClapTrap form." << std::endl;
}
