# include "Character.hpp"

Character::Character(void) {}

Character::Character(std::string name) : name_(name) {
    for (int i = 0; i < 4; ++i)
        inventory_[i] = nullptr;
}

Character::Character(const Character &o) {
    name_ = o.name_;
    for (int i = 0; i < 4; ++i) {
        if (o.inventory_[i])
            inventory_[i] = o.inventory_[i]->clone();
        else
            inventory_[i] = nullptr;
    }
}

Character &Character::operator=(const Character &o) {
    if (this == &o)
        return *this;
    for (int i = 0; i < 4; ++i) {
        if (inventory_[i])
            delete inventory_[i];
        if (o.inventory_[i])
            inventory_[i] = o.inventory_[i]->clone();
        else
            inventory_[i] = nullptr;
    }
    name_ = o.name_;
    return *this;
}

Character::~Character(void) {
    for (int i = 0; i < 4; ++i) {
        if (inventory_[i])
            delete inventory_[i];
        inventory_[i] = nullptr;
    }
}

std::string const & Character::getName() const {
    return name_;
}

void Character::equip(AMateria* m) {
    if (!m)
        return;
    for (int i = 0; i < 4; ++i) {
        if (inventory_[i] == m) {
            return;
        }
    }
    for (int i = 0; i < 4; ++i) {
        if (!inventory_[i]) {
            inventory_[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx) {
    if (idx >= 4 || idx < 0 || !inventory_[idx])
        return;
    inventory_[idx] = nullptr;
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 4 || idx < 0 || !inventory_[idx])
        return;
    inventory_[idx]->use(target);
}
