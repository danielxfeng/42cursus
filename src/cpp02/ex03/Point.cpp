# include "Point.hpp"

Point::Point() : x_(Fixed(0)), y_(Fixed(0)) {}
Point::Point(const Fixed &x, const Fixed &y) : x_(x), y_(y) {}
Point::Point(const Point &o) {*this = o;}
Point& Point::operator=(const Point &o) {
    muted = true;
    mx_ = o.getX();
    my_ = o.getY();
    return *this;
}
Point::~Point(){}

const Fixed& Point::getX () const {return muted ? mx_ : x_;}
const Fixed& Point::getY () const {return muted ? my_ : y_;}
