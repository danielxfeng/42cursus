# include "Cure.hpp"
# include <iostream>

Cure::Cure(void) { type_ = "cure"; }

Cure::Cure(const Cure &o) : AMateria(o) { *this = o; }

Cure &Cure::operator=(const Cure &o) {
    type_ = o.type_;
    return *this;
}

Cure::~Cure(void) {}

AMateria* Cure::clone() const {
    return new Cure(*this);
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
