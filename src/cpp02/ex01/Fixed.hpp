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
        Fixed &operator=(const Fixed &o);
        int getRawBits(void) const;
        void setRawBits(int const value);
        float toFloat( void ) const;
        int toInt( void ) const;

    private:
        int value_;
        static const int fractionalBits_ = 8;
};

std::ostream &operator<<(std::ostream &os, Fixed const &n);

# endif
