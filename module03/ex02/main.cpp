#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    ClapTrap claptrap("Clappy");
    ScavTrap scavtrap("Scavvy");

    claptrap.attack("Enemy");
    scavtrap.attack("Enemy");

    claptrap.takeDamage(8);
    scavtrap.takeDamage(8);

    claptrap.beRepaired(5);
    scavtrap.beRepaired(5);

    scavtrap.guardGate();

    return 0;
}
