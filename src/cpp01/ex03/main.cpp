#include "Zombie.hpp"

int main(void)
{
    auto zs = zombieHorde(3, "no name");
    for (auto i = 0; i < 3; ++i)
        zs[i].announce();
    delete []zs;
    return (EXIT_SUCCESS);
}
