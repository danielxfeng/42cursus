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
    value_ = (int)(value * (1 << fractionalBits_));
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

bool Fixed::operator>(const Fixed &o) const {
    return value_ > o.getRawBits();
}

bool Fixed::operator<(const Fixed &o) const {
    return value_ < o.getRawBits();
}

bool Fixed::operator>=(const Fixed &o) const {
    return value_ >= o.getRawBits();
}

bool Fixed::operator<=(const Fixed &o) const {
    return value_ <= o.getRawBits();
}

bool Fixed::operator==(const Fixed &o) const {
    return value_ == o.getRawBits();
}

bool Fixed::operator!=(const Fixed &o) const {
    return value_ != o.getRawBits();
}

Fixed Fixed::operator+(const Fixed &o) const {
    return Fixed(toFloat() + o.toFloat());
}

Fixed Fixed::operator-(const Fixed &o) const {
    return Fixed(toFloat() - o.toFloat());
}

Fixed Fixed::operator*(const Fixed &o) const {
    return Fixed(toFloat() * o.toFloat());
}

Fixed Fixed::operator/(const Fixed &o) const {
    return Fixed(toFloat() / o.toFloat());
}

Fixed &Fixed::operator++() {
    ++value_;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    ++value_;
    return tmp;
}

Fixed &Fixed::operator--() {
    --value_;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    --value_;
    return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return a < b ? a : b;
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b) {
    return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return a > b ? a : b;
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b) {
    return a > b ? a : b;
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