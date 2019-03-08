/*
    CH08-320142
    a3_p6.cpp
    Ardit Shala
    a.shala@jacobs-university.de
*/

#include <iostream>
#include "Complex.h"

using namespace std;

Complex::Complex(){  // default constructor
    real = 0;
    imag = 0;
    cout << "Constructor 1 is being called" << endl;
}

Complex::Complex(float a, float b) {  //constructor with 2(all) parameters
    real = a;
    imag = b;
    cout << "Constructor 2 is being called" << endl;
}

Complex::~Complex() // destructor
{
    cout << "Destructor is being called" << endl;
}

void Complex::setImag(float imag1) // setting the imaginary part
{
    imag = imag1;
}

void Complex::setReal(float real1) // setting the real part
{
    real = real1;
}

float Complex::getImag() // getting imaginary part
{
    return imag;
}

float Complex::getReal() // getting real part
{
    return real;
}

void Complex::conjugate() // "calculating" and printing the conjugate of a complex number
{
    cout << real << "-" << imag << "i" <<endl;
}

Complex Complex::add(Complex a) // adding two complex numbers and returning the value
{
   // cout << real + a.real << "+" << imag + a.imag << "i" << endl;
    Complex temp;
    temp.real = real + a.real;
    temp.imag = imag + a.imag;
    return temp;
}

Complex Complex::diff(Complex a) // the difference of two comp. number z1-z2
{
    //cout << real - a.real << "+(" << imag - a.imag << ")i" << endl;
    Complex temp;
    temp.real = real - a.real;
    temp.real = imag - a.imag;
    return temp;
}

Complex Complex::mul(Complex a) // multiplication of two numbers
{
   // cout << ((real * a.real) - (imag * a.imag))  << "+" << ((imag * a.real) - (real * a.imag)) << "i" << endl;
    Complex temp;
    temp.real = ((real * a.real) - (imag * a.imag));
    temp.imag = ((imag * a.real) + (real * a.imag));
    return temp;
}


void Complex::print() // simple printing method
{
    cout << " " << real << "+(" << imag << ")i";
}




