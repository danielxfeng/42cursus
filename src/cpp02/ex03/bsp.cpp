# include "Point.hpp"

float cross(const Point a, const Point b, const Point p) {
    Fixed r = (b.getX() - a.getX()) * (p.getY() - a.getY())
     - (b.getY() - a.getY()) * (p.getX() - a.getX());
    return r.toFloat();
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
    auto f1 = cross(a, b, point);
    auto f2 = cross(b, c, point);
    auto f3 = cross(c, a, point);
    return (f1 < 0 && f2 < 0 && f3 < 0) || (f1 > 0 && f2 > 0 && f3 > 0);
}
