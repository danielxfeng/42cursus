# include "ICharacter.hpp"

ICharacter::ICharacter(void) {}
ICharacter::ICharacter(const ICharacter &o) { *this = o; }
ICharacter &ICharacter::operator=(const ICharacter &o) {
    (void)o;
    return *this;
}

ICharacter::~ICharacter(void) {}
