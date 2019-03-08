/*
    CH08-320142
    a6_p2.cpp(testfraction.cpp)
    Ardit Shala
    a.shala@jacobs-university.de
*/
#include <iostream>
#include "fraction.h"

using namespace std;

int main(void) {

  Fraction first, second;
  cout << "Write the first one: ";
  cin >> first;
  cout << endl;
  cout << "Write the second one: ";
  cin >> second;
  cout << endl;

  Fraction product = first * second;
  Fraction quotient = first / second;
  Fraction sum = first + second;
  Fraction sub = first - second;
  Fraction grd;

    cout << "**************************************" << endl;
  if( (first<second) == 1 )
  {
      cout << "The greatest fraction is: " << second << endl;
  }else
    cout << "The greatest fraction is: " << first << endl;

  cout << "**************************************" << endl;
  cout << "The multiplied result is: " << product << endl;
  cout << "**************************************" << endl;
  cout << "The divided result is: " << quotient << endl;
  cout << "**************************************" << endl;
  cout << "The sum is: " << sum << endl;
  cout << "**************************************" << endl;
  cout << "The substraction is" << sub << endl;
  cout << "**************************************" << endl;
}

