#include "Dog.hpp"

#include <iostream>

Dog::Dog(void) {
    type_ = "Dog";
    std::cout << "Dog created" << std::endl;
}

Dog::Dog(const Dog &o) {
    std::cout << "Dog created by copying" << std::endl;
    *this = o;
}

Dog &Dog::operator=(const Dog &o) {
    std::cout << "Dog assigned" << std::endl;
    type_ = o.type_;
    return *this;
}

Dog::~Dog(void) {std::cout << "Dog destroyed" << std::endl;}

void Dog::makeSound(void) const {std::cout << "Woof" << std::endl;}
