/*
    CH08-320142
    A4_P4.cpp(dyncreature.cpp)
    Ardit Shala
    a.shala@jacobs-university.de
*/

#include <iostream>
#include "Creature.h"

using namespace std;

int main()
{
    char g;

    while ( g != 'q') //the loop goes infinitely if q is not pressed
     { // there are some others ways to do this also
         //by letting the loop to rotate itself and then terminate using getchar()
         //from stdio.h library
         cout << "Enter the character: " << endl; // asking the user for input
         cin >> g; // storing it

         if(g == 'w') // if the character is g then do this
         {
            Wizard *ptr1; // pointer to wizard
            ptr1 = new Wizard; // assigning a new object to pointer
            ptr1->run(); // calling the methods
            ptr1->hover();

         }else if(g == '1') //same for this one
         {
             Creature1 *ptr2;
             ptr2 = new Creature1;
             ptr2->body();
             ptr2->run();
         }else if(g == '2') //same for this one
         {
             Creature2 *ptr3;
             ptr3 = new Creature2;
             ptr3->life();
             ptr3->run();
         }else
         cout << "Please enter 'w', '1' or '2'." << endl;
    }

    return 0;
}
