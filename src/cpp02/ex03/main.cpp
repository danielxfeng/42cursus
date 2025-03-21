#include "Point.hpp"
#include <iostream> 

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void ) { 
	Point testCases[] = {
		Point(Fixed(2), Fixed(1)), // inside
		Point(Fixed(2), Fixed(0)), // on edge AB
		Point(Fixed(2), Fixed(-1)), // outside
		Point(Fixed(0), Fixed(0)), // vertex A
	};
	
	Point a = Point(Fixed(0), Fixed(0));
	Point b = Point(Fixed(4), Fixed(0));
	Point c = Point(Fixed(2), Fixed(4));
	for (int i = 0; i < 4; i++) {
		Point p = testCases[i];
		bool result = bsp(a, b, c, p);
		std::cout << "Point " << (result ? "inside" : "outside") << std::endl;
	}
}
