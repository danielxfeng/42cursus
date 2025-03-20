#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void) {};

Zombie::Zombie(std::string name) : name_(name) {};

Zombie::~Zombie(void) {
    std::cout << name_ << " is gone." << std::endl;
};

void Zombie::announce(void) {
    std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) {
    name_ = name;
}
