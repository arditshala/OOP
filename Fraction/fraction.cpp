/*
    CH08-320142
    a6_p2.cpp(fraction.cpp)
    Ardit Shala
    a.shala@jacobs-university.de
*/
#include <iostream>
#include "fraction.h"

using namespace std;

Fraction Fraction::operator*(Fraction f) {
  int number, denominator;
  number = this->number * f.number;
  denominator = this->denominator * f.denominator;
  Fraction result(number, denominator);
  return result;
}

Fraction Fraction::operator/(Fraction f) {
  int number, denominator;
  number = this->number * f.denominator;
  denominator = this->denominator * f.number;
  Fraction result(number, denominator);
  return result;
}


Fraction::Fraction() {  //default constructor 1,1
  number = 1;
  denominator = 1;
}

Fraction::Fraction(int n, int d) { //constructor with two parameters
  int tmp_gcd = gcd(n, d);

  number = n / tmp_gcd;
  denominator = d / tmp_gcd;
}

Fraction::~Fraction()
{
    cout << "The destructor is being called" << endl;
}

int Fraction::getnumber() { //getter for nominator
  return number;
}

int Fraction::getdenominator() { //getter for denominator
  return denominator;
}

void Fraction::setnumber(int number) { // setter for numerator
  this->number = number;
}

void Fraction::setdenominator(int denominator) { //setter for denominator
  this->denominator = denominator;
}

int Fraction::gcd(int a, int b) { //calculates the gdc
  if (b == 0) {
    return a;
  }
  return gcd(b, a%b);
}


int Fraction::lcm(int a, int b) { //calculates the  lmc
  return (a * b) / gcd(a, b);
}

Fraction Fraction::operator+(Fraction f) {
    int number, denominator;
    number = (this->number*(lcm(this->denominator, f.denominator)))/this->denominator + (f.number*(lcm(this->denominator, f.denominator)))/f.denominator;
    denominator = lcm(this->denominator, f.denominator);
    Fraction result(number, denominator);
    return result;
}

Fraction Fraction::operator-(Fraction f) {
    int number, denominator;
    number = (this->number*(lcm(this->denominator, f.denominator)))/this->denominator - (f.number*(lcm(this->denominator, f.denominator)))/f.denominator;
    denominator = lcm(this->denominator, f.denominator);
    Fraction result(number, denominator);
    return result;
}

Fraction Fraction::operator=(Fraction f) {
    int number, denominator;
    number = f.number;
    denominator = f.denominator;
    Fraction result(number, denominator);
    return result;
}



