/*
	CH08-320142
	a6_p4.cpp
	Ardit Shala
	a.shala@jacobs-university.de
*/
#include <iostream>
#include "Square.h"

Square::Square(const char *n, double a) : Area(n) {
	side = a;
}

Square::~Square() {
}

double Square::calcArea() const {
	std::cout << "calcArea of Square...";
	return (side*side);
}

double Square::calcPerimeter() const {
	std::cout << "calcPerimeter of Square...";
	return (4*side);
}