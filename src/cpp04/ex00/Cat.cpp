# include "Cat.hpp"
# include <iostream>

Cat::Cat(void) {
    type_ = "Cat";
    std::cout << "Cat created" << std::endl;
}

Cat::Cat(const Cat &o) {
    std::cout << "Cat created by copying" << std::endl;
    *this = o;
}

Cat &Cat::operator=(const Cat &o) {
    std::cout << "Cat assigned" << std::endl;
    type_ = o.type_;
    return *this;
}

Cat::~Cat(void) {std::cout << "Cat destroyed" << std::endl;}

void Cat::makeSound(void) const {std::cout << "Meow" << std::endl;}
