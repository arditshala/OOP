#include <iostream>
#include <cmath>
#include "Vector.h"

using namespace std;

Vector::Vector()
{
    size = 2;
    double c[int(size)] = {1.6,2.7};
    ptrdb = &c[0];
    cout << "Constructor 1 is being called" << endl;

}

Vector::Vector(double newsize, double *newptr)
{
    cout << "Constructor 2 is being called" << endl;
    size = newsize;
    ptrdb = newptr;

}

Vector::Vector(const Vector& c)
{
    cout << "Copy constructor is being called" << endl;
    size = c.size;
    ptrdb = c.ptrdb;
}

Vector::~Vector()
{
    cout << "The destructor is being called" << endl;
}

double Vector::norm() const
{
    double norma=0;
    double norma3;

    for(int i=0; i<size; i++)
    {
        norma = norma + pow(*(ptrdb+i),2);
    }
    norma3 = sqrt(norma);

    return norma3;
}

Vector Vector::add(const Vector &v1) const
{
    Vector temp;

    for(int i=0; i < size ; i++)
    {
        *(temp.ptrdb+i) = *(ptrdb+i) + *(v1.ptrdb+i);
    }
    return temp;

}

Vector Vector::diff(const Vector &v1) const
{
     Vector temp;

    for(int i=0; i < size ; i++)
    {
        *(temp.ptrdb+i) = *(ptrdb+i) - *(v1.ptrdb+i);
    }
    return temp;
}

double Vector::mult(const Vector &v1) const
{
    double sum;

    for(int i=0; i<size; i++)
    {
        cout << *(ptrdb+i) << endl;
        sum = sum + (*(ptrdb+i) * *(v1.ptrdb+i));
    }

    return sum;
}

void Vector::print()
{
    cout<< "The array is ";
    for(int i=0; i<size; i++)
    {
        cout << " " << *(ptrdb+i);
    }
    cout << endl;
}

void Vector::setSize(const double size1)
{
    size = size1;
}

double Vector::getSize()
{
    return size;
}

double Vector::getPtrdb()
{
    return *ptrdb;
}


