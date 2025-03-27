# include "Ice.hpp"
# include <iostream>

Ice::Ice(void) { type_ = "ice"; }

Ice::Ice(const Ice &o) { *this = o; }

Ice &Ice::operator=(const Ice &o) {
    type_ = o.type_;
    return *this;
}

Ice::~Ice(void) {}

AMateria* Ice::clone() const {
    return new Ice(*this);
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
