#include "Zombie.hpp"

int main(void)
{
    auto z1 = newZombie("alaaaa on heap");
    z1->announce();
    delete z1;

    randomChump("blaaaa on stack");

    return (EXIT_SUCCESS);
}
