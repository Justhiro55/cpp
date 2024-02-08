#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap();
        FragTrap(std::string name);
    	FragTrap(const FragTrap& obj);
        virtual ~FragTrap();
        FragTrap &operator=(const FragTrap &obj);
        void highFivesGuys(void);
    private:
};

#endif