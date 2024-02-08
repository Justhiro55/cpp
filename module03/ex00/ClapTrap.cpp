#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("default"), _hitPoint(10), _energyPoint(10), _attackDamage(10)
{
    std::cout << "ClapTrap " << this->_name << " Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoint(10), _energyPoint(10), _attackDamage(10)
{
    std::cout << "ClapTrap " << this->_name << " Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj) : _name(obj._name), _hitPoint(obj._hitPoint), _energyPoint(obj._energyPoint), _attackDamage(obj._attackDamage)
{
    std::cout << "ClapTrap " << this->_name << " Constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << this->_name << " Destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &obj)
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

void ClapTrap::attack(const std::string &target)
{
    if (this->_hitPoint == 0 || this->_energyPoint == 0)
    {
        std::cout << "ClapTrap " << this->_name << " can't move..." << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << this->_name << " attacks " << target
                  << ", causing " << this->_attackDamage << " points of damage!"
                  << std::endl;
        this->_energyPoint--;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (amount > this->_hitPoint)
        this->_hitPoint = 0;
    else
        this->_hitPoint -= amount;
    std::cout << "ClapTrap " << this->_name
              << " has taken " << amount << " damage"
              << std::endl;
    if (this->_hitPoint == 0)
        std::cout << "ClapTrap " << this->_name << " is died" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_hitPoint == 0 || this->_energyPoint == 0)
    {
        std::cout << "ClapTrap " << this->_name << " can't move..." << std::endl;
    }
    else
    {
        this->_hitPoint += amount;
        this->_energyPoint--;
        std::cout << "ClapTrap " << this->_name << " is repaired "
                  << amount << " hit point" << std::endl;
    }
}
