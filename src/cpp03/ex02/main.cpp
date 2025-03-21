#include "FragTrap.hpp"

int main( void ) { 
	FragTrap fragtrap("Fragtrap1");
	FragTrap fragtrap2(fragtrap);
	FragTrap fragtrap3 = fragtrap;

	fragtrap.attack("enemy");
	fragtrap.takeDamage(5);
	fragtrap.beRepaired(5);
	
	fragtrap2.attack("enemy");
	fragtrap2.takeDamage(5);
	fragtrap2.beRepaired(5);

	fragtrap3.attack("enemy");
	fragtrap3.takeDamage(5);
	fragtrap3.beRepaired(5);

	fragtrap.highFivesGuys();
	return 0;
}
