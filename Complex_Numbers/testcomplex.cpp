/*
    CH08-320142
    a3_p6.cpp
    Ardit Shala
    a.shala@jacobs-university.de
*/

#include <iostream>
#include "Complex.h"

using namespace std;

int main() {
	Complex c1, c2, c3;  // declaring three new objects
    float a,b,c,d; // declaring the local floats
	cout << "Enter the a: "; // asking the user for a
	cin >> a; // storing the a
	cout << "Enter the b: "; // same for the rest
	cin >> b;
	cout << "Enter the c: ";
	cin >> c;
	cout << "Enter the d: ";
	cin >> d;

    c1.setImag(b); //setting the float b as imaginary part of c1
    c1.setReal(a); //setting the float a as real part of c1
    c2.setImag(d); //same for c2
    c2.setReal(c); //same for c2

	c1.conjugate(); //calling the method conjugate for the first complex number
	c2.conjugate(); // same for the second one

    cout << "The sum is:" << endl;
    c3 = c1.add(c2); //sum
    c3.print(); // printing the sum as z format
    cout << "----------------" <<endl;
    cout << "The multiply is:" << endl;
    c3 = c1.mul(c2); // multiplication
    c3.print(); // printing the multiplication as z format
    cout << "----------------" <<endl;
    cout << "The difference is:" <<endl;
    c3 = c1.diff(c2); // difference c1-c2
    c3.print(); // printing the difference as z format

	return 0;
}
