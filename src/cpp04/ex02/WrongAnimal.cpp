# include "WrongAnimal.hpp"
# include <iostream>

WrongAnimal::WrongAnimal(void) {std::cout << "WrongAnimal created" << std::endl;}

WrongAnimal::WrongAnimal(const WrongAnimal &o) {
    std::cout << "WrongAnimal created by copying" << std::endl;
    *this = o;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &o) {
    std::cout << "WrongAnimal assigned" << std::endl;
    type_ = o.type_;
    return *this;
}

WrongAnimal::~WrongAnimal(void) {std::cout << "WrongAnimal destroyed" << std::endl;}

void WrongAnimal::makeSound(void) const {std::cout << "WrongAnimal bark" << std::endl;}

std::string WrongAnimal::getType(void) const {return type_;}
