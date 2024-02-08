#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void): ClapTrap("default_clap_trap")
{
	this->_name = "default";
	this->_hitPoint = FragTrap::_hitPoint;
	this->_energyPoint = ScavTrap::_energyPoint;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) {
    this->_name = name;
    this->_hitPoint = FragTrap::_hitPoint;
    this->_energyPoint = ScavTrap::_energyPoint;
    this->_attackDamage = FragTrap::_attackDamage;
    std::cout << "DiamondTrap " << this->_name << " Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj)
{
    this->_name = obj._name;
    this->_attackDamage = obj._attackDamage;
    this->_energyPoint = obj._energyPoint;
    this->_hitPoint = obj._hitPoint;
    std::cout << "DiamondTrap " << this->_name <<" Constructor called" << std::endl; 
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &obj)
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
