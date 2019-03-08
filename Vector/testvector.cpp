#include <iostream>
#include "Vector.h"

using namespace std;

int main()
{
    Vector v1; // default constructor
    double d[2] = {5.6,3.5};
    double *tt = &d[0];
    double g;

    Vector tidra(2,tt); // constructor with 2 parameters
    v1.print();

    Vector t = tidra; // copy constructor

    g = tidra.norm();
    cout << "Norm of v1 is: " << g << endl;
    cout << "---------------------------" << endl;
    (t.diff(tidra)).print();
    cout << "---------------------------" << endl;

    double h;
    cout << "***************************" << endl;
    h = t.mult(tidra); // multiplication of vector "tidra" and vector "t"
    cout << "The scalar product is: " << h << endl;
    cout << "***************************" << endl;

    (v1.add(tidra)).print();

    tidra.print();
    return 0;
}
