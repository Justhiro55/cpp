#include "DiamondTrap.hpp"

int main() {
    // Creating DiamondTrap instances
    DiamondTrap dt1("DiamondBoy");
    DiamondTrap dt2("DiamondGirl");

    // Displaying who they are using whoAmI
    dt1.whoAmI();
    dt2.whoAmI();

    // Testing attack
    dt1.attack("DiamondGirl"); // This should use ScavTrap's attack method
    dt2.takeDamage(30); // Taking damage

    // Testing repair
    dt2.beRepaired(20);

    // Testing special abilities from both FragTrap and ScavTrap
    dt1.highFivesGuys(); // From FragTrap
    dt2.guardGate(); // From ScavTrap

    // Additional tests to demonstrate energy point and hit point management
    dt1.takeDamage(100); // Trying to over-damage to see if it caps at 0
    dt1.beRepaired(10); // Repairing when possible

    // Showcasing destruction
    return 0;
}
