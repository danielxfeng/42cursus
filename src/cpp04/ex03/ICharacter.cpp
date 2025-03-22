# include "ICharacter.hpp"

ICharacter::ICharacter(void) {}
ICharacter::ICharacter(const ICharacter &o) { *this = o; }
ICharacter &ICharacter::operator=(const ICharacter &o) {
    for (int i = 0; i < 4; i++) {
        if (materias_[i]) {
            delete materias_[i];
            materias_[i] = 0;
        }
    }
    for (int i = 0; i < 4; i++) {
        if (o.materias_[i]) {
            materias_[i] = o.materias_[i]->clone();
        }
    }
    return *this;
}

ICharacter::~ICharacter(void) {
    for (int i = 0; i < 4; i++) {
        if (materias_[i]) {
            delete materias_[i];
            materias_[i] = 0;
        }
    }
}
