#include "Weapon.hpp"

Weapon::Weapon() {};

Weapon::Weapon(std::string type) : type_(type){}; 

const std::string Weapon::getType(void) {
    return type_;
}

void Weapon::setType(std::string type) {
    type_ = type;
}
