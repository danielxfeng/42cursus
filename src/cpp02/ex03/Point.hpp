# pragma once

# ifndef POINT_H
# define POINT_H

# include "Fixed.hpp"

class Point {
    public:
        Point();
        Point(const float x, const float y);
        Point(const Point &o);
        Point &operator=(const Point &o);
        ~Point();

        const Fixed &getX() const;
        const Fixed &getY() const;
        

    private:
        const Fixed x_;
        const Fixed y_;
        
        bool muted{false};
        Fixed mx_;
        Fixed my_;
};

# endif // POINT_H