#include "Point.hpp"
#include <iostream> 

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void ) { 
	Point testCases[] = {
		Point(2.0f, 1.0f), // inside
		Point(2.0f, 0.0f), // on edge AB
		Point(2.0f, -1.0f), // outside
		Point(0.0f, 0.0f), // vertex A
	};
	
	Point a = Point(0.0f, 0.0f);
	Point b = Point(4.0f, 0.0f);
	Point c = Point(2.0f, 4.0f);
	for (int i = 0; i < 4; i++) {
		Point p = testCases[i];
		bool result = bsp(a, b, c, p);
		std::cout << "Point " << (result ? "inside" : "outside") << std::endl;
	}
}
