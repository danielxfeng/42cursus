#include "DiamondTrap.hpp"

int main( void ) { 
	DiamondTrap diamondtrap("DiamondTrap1");
	DiamondTrap diamondtrap2(diamondtrap);
	DiamondTrap diamondtrap3 = diamondtrap;

	diamondtrap.attack("enemy");
	diamondtrap.takeDamage(5);
	diamondtrap.beRepaired(5);

	diamondtrap2.attack("enemy");
	diamondtrap2.takeDamage(5);
	diamondtrap2.beRepaired(5);

	diamondtrap3.attack("enemy");
	diamondtrap3.takeDamage(5);
	diamondtrap3.beRepaired(5);

	diamondtrap.whoAmI();
	return 0;
}
