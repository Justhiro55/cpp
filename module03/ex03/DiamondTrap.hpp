#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
    public:
        DiamondTrap();
        DiamondTrap(std::string name);
        virtual ~DiamondTrap();
        void whoAmI(void);
        void printStatus(void);
        void attack(const std::string &target);
    private:
        std::string _name;
};

#endif