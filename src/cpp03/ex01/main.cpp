#include "ScavTrap.hpp"

int main( void ) { 
	ScavTrap scavtrap("Scavtrap1");
	ScavTrap scavtrap2(scavtrap);
	ScavTrap scavtrap3 = scavtrap;

	scavtrap.attack("enemy");
	scavtrap.takeDamage(5);
	scavtrap.beRepaired(5);
	
	scavtrap2.attack("enemy");
	scavtrap2.takeDamage(5);
	scavtrap2.beRepaired(5);

	scavtrap3.attack("enemy");
	scavtrap3.takeDamage(5);
	scavtrap3.beRepaired(5);

	scavtrap.guardGate();
	return 0;
}
