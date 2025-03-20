#include "HumanB.hpp"
#include <iostream>

std::string get_type(Weapon *weapon) {
    if (weapon != nullptr)
        return weapon->getType();
    return "set the weapon first";
}

HumanB::HumanB(std::string name) : name_(name), weapon_(nullptr) {};

void HumanB::setWeapon(Weapon &weapon) {
    weapon_ = &weapon;
}

void HumanB::attack(void) {
    std::cout << name_ << "attacks with their " << get_type(weapon_) << std::endl;
}
