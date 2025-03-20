#include "Weapon.hpp"

const std::string Weapon::getType(void) {
    return type_;
}

void Weapon::setType(std::string type) {
    type_ = type;
}
