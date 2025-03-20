# include "Fixed.hpp"
# include <iostream>

Fixed::Fixed() : value_(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    value_ = value << fractionalBits_;
}

Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    value_ = std::roundf(value * (1 << fractionalBits_));
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
    return value_;
}

void Fixed::setRawBits(int const value) {
    value_ = value;
}

float Fixed::toFloat( void ) const {
    return (float)value_ / (1 << fractionalBits_);
}

int Fixed::toInt( void ) const {
    return value_ >> fractionalBits_;
}

std::ostream &operator<<(std::ostream &os, Fixed const &n) {
    os << n.toFloat();
    return os;
}