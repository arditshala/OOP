/*
	CH08-320142
	a6_p4.cpp
	Ardit Shala
	a.shala@jacobs-university.de
*/
#ifndef _SQUARE_H
#define _SQUARE_H
#include "Area.h"

class Square : public virtual Area{
public:
	Square(const char *n, double a);
	~Square();
	double calcArea() const;
	double calcPerimeter() const;
private:
	double side;
};

#endif
