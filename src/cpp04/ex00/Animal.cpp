#include "Animal.hpp"
#include <iostream>

Animal::Animal(void) {std::cout << "Animal created" << std::endl;}

Animal::Animal(const Animal &o) {
    std::cout << "Animal created by copying" << std::endl;
    *this = o;
}

Animal &Animal::operator=(const Animal &o) {
    std::cout << "Animal assigned" << std::endl;
    type_ = o.type_;
    return *this;
}

Animal::~Animal(void) {std::cout << "Animal destroyed" << std::endl;}

const std::string &Animal::getType(void) const {return type_;}

void Animal::makeSound(void) const {std::cout << "Animal sound" << std::endl;}
