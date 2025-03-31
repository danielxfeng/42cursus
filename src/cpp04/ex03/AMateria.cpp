# include "AMateria.hpp"

AMateria::AMateria(void) {}

AMateria::AMateria(const AMateria &o) { *this = o; }

AMateria &AMateria::operator=(const AMateria &o) {
    type_ = o.type_;
    return *this;
}

AMateria::~AMateria(void) {}

AMateria::AMateria(std::string const & type) : type_(type) {}

std::string const & AMateria::getType() const { return type_; }

void AMateria::use(ICharacter& target) {(void)target;}
