/*
	CH08-320142
	a6_p4.cpp
	Ardit Shala
	a.shala@jacobs-university.de
*/
#include <iostream>
#include "Circle.h"

Circle::Circle(const char *n, double a) : Area(n) {
	radius = a;
}

Circle::~Circle() {
}

double Circle::calcArea() const {
	std::cout << "calcArea of Circle...";
	return radius * radius * 3.141593;
}

double Circle::calcPerimeter() const {
	std::cout << "calcPerimeter of Circle...";
	return 2 * radius*3.14; //we can declare pi as a global var since is a const 
}
