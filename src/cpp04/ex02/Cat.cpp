# include "Cat.hpp"
# include <iostream>

Cat::Cat(void) : brain_(new Brain()) {
    type_ = "Cat";
    std::cout << "Cat created" << std::endl;
}

Cat::Cat(const Cat &o) {
    std::cout << "Cat created by copying" << std::endl;
    *this = o;
}

Cat &Cat::operator=(const Cat &o) {
    std::cout << "Cat assigned" << std::endl;
    if (this == &o)
        return *this;
    delete brain_;
    brain_ = new Brain(*o.brain_);
    type_ = o.type_;
    return *this;
}

Cat::~Cat(void) {
    delete brain_;
    std::cout << "Cat destroyed" << std::endl;
}

void Cat::makeSound(void) const {std::cout << "Meow" << std::endl;}
