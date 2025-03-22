#include "ClapTrap.hpp"

int main( void ) { 
	ClapTrap claptrap("Claptrap1");
	ClapTrap claptrap2(claptrap);
	ClapTrap claptrap3 = claptrap;

	claptrap.attack("enemy");
	claptrap.takeDamage(5);
	claptrap.beRepaired(5);
	
	claptrap2.attack("enemy");
	claptrap2.takeDamage(5);
	claptrap2.beRepaired(5);

	claptrap3.attack("enemy");
	claptrap3.takeDamage(5);
	claptrap3.beRepaired(5);
	return 0;
}
