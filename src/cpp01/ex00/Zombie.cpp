#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name) : name_(name) {};

Zombie::~Zombie(void) {
    std::cout << name_ << " is gone." << std::endl;
};

void Zombie::announce(void) {
    std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
