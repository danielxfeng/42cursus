# pragma once

# ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
    public:
        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed &o);
        ~Fixed();
        bool operator>(const Fixed &o) const;
        bool operator<(const Fixed &o) const;
        bool operator>=(const Fixed &o) const;
        bool operator<=(const Fixed &o) const;
        bool operator==(const Fixed &o) const;
        bool operator!=(const Fixed &o) const;
        Fixed operator+(const Fixed &o) const;
        Fixed operator-(const Fixed &o) const;
        Fixed operator*(const Fixed &o) const;
        Fixed operator/(const Fixed &o) const;
        Fixed &operator++();
        Fixed operator++(int);
        Fixed &operator--();
        Fixed operator--(int);
        Fixed &operator=(const Fixed &o);
        int getRawBits(void) const;
        void setRawBits(int const value);
        float toFloat( void ) const;
        int toInt( void ) const;
        static Fixed &min(Fixed &a, Fixed &b);
        static Fixed const &min(Fixed const &a, Fixed const &b);
        static Fixed &max(Fixed &a, Fixed &b);
        static Fixed const &max(Fixed const &a, Fixed const &b);

    private:
        int value_;
        static const int fractionalBits_ = 8;
};

std::ostream &operator<<(std::ostream &os, Fixed const &n);

# endif
