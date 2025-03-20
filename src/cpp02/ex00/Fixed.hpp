# pragma once

# ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
    public:
        Fixed();
        Fixed(const Fixed &o);
        ~Fixed();
        Fixed &operator=(const Fixed &o);
        int getRawBits(void) const;
        void setRawBits(int const value);

    private:
        int value_;
        //static const int fractionalBits_{8};
};

# endif // FIXED_HPP
