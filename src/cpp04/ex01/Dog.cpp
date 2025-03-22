#include "Dog.hpp"

#include <iostream>

Dog::Dog(void) : brain_(new Brain()) {
    type_ = "Dog";
    std::cout << "Dog created" << std::endl;
}

Dog::Dog(const Dog &o) {
    std::cout << "Dog created by copying" << std::endl;
    *this = o;
}

Dog &Dog::operator=(const Dog &o) {
    std::cout << "Dog assigned" << std::endl;
    if (this == &o)
        return *this;
    type_ = o.type_;
    delete brain_;
    brain_ = new Brain(*o.brain_);
    return *this;
}

Dog::~Dog(void) {
    delete brain_;
    std::cout << "Dog destroyed" << std::endl;
}

void Dog::makeSound(void) const {std::cout << "Woof" << std::endl;}
