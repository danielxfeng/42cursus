# include "Fixed.hpp"
# include <iostream>
# include <cmath>

Fixed::Fixed() : value_(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    int64_t overflow_killer = (int64_t)value << fractionalBits_;
    if (int(overflow_killer) != overflow_killer) 
        throw std::overflow_error("The number can not be converted to a Fixed number safely.");
    value_ = int(overflow_killer);
}

Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    int64_t overflow_killer = (int64_t)(roundf(value * (1 << fractionalBits_)));
    if (int(overflow_killer) != overflow_killer) 
        throw std::overflow_error("The number can not be converted to a Fixed number safely.");
    value_ = (int)overflow_killer;
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
    int64_t overflow_killer = value_ + o.getRawBits();
    if (int(overflow_killer) != overflow_killer)
        throw std::overflow_error("The number can not be converted to a Fixed number safely.");
    Fixed f;
    f.setRawBits(int(overflow_killer));
    return f;
}

Fixed Fixed::operator-(const Fixed &o) const {
    int64_t overflow_killer = value_ - o.getRawBits();
    if (int(overflow_killer) != overflow_killer)
        throw std::overflow_error("The number can not be converted to a Fixed number safely.");
    Fixed f;
    f.setRawBits(int(overflow_killer));
    return f;
}

Fixed Fixed::operator*(const Fixed &o) const {
    int64_t overflow_killer  = (int64_t)value_ * o.getRawBits() / (1 << fractionalBits_);
    if (int(overflow_killer) != overflow_killer)
        throw std::overflow_error("The number can not be converted to a Fixed number safely.");
    Fixed f;
    f.setRawBits(int(overflow_killer));
    return f;
}

Fixed Fixed::operator/(const Fixed &o) const {
    int64_t overflow_killer = ((int64_t)value_ << fractionalBits_) / o.getRawBits();
    if (int(overflow_killer) != overflow_killer)
        throw std::overflow_error("The number can not be converted to a Fixed number safely.");
    Fixed f;
    f.setRawBits(int(overflow_killer));
    return f;
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

void Fixed::setRawBits(int const raw) {
    value_ = raw;
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