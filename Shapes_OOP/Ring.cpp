/*
	CH08-320142
	a6_p2.cpp
	Ardit Shala
	a.shala@jacobs-university.de
*/
#include <iostream>
#include "Ring.h"

Ring::Ring(const char *n, double outer, double inner)
					: Area(n), Circle(n, outer) {
	innerradius = inner;
}

Ring::~Ring() {
}

double Ring::calcArea() const {
    std::cout << "calcArea of Ring...";
	return (Circle::calcArea()-
		(innerradius * innerradius * 3.141593));
}

double Ring::calcPerimeter() const { 
	std::cout << "caclPerimeter of Ring...";
	return (Circle::calcPerimeter() - (2 * (innerradius*3.14)));
}
