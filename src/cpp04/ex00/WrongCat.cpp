#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(void) {
    type_ = "WrongCat";
    std::cout << "WrongCat created" << std::endl;
}

WrongCat::WrongCat(const WrongCat &o) {
    std::cout << "WrongCat created by copying" << std::endl;
    *this = o;
}

WrongCat &WrongCat::operator=(const WrongCat &o) {
    std::cout << "WrongCat assigned" << std::endl;
    type_ = o.type_;
    return *this;
}

WrongCat::~WrongCat(void) {std::cout << "WrongCat destroyed" << std::endl;}

void WrongCat::makeSound(void) const {std::cout << "Wrong Cat Meow" << std::endl;}