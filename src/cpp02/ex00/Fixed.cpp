# include "Fixed.hpp"
# include <iostream>

Fixed::Fixed() : value_(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &o) {
    std::cout << "Copy constructor called" << std::endl;
    *this = o;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &o) {
    std::cout << "Copy assignment operator called" << std::endl;
    value_ = o.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return value_;
}

void Fixed::setRawBits(int const value) {
    std::cout << "setRawBits member function called" << std::endl;
    value_ = value;
}
