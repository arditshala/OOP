/*
    CH08-320142
    A4_P4.cpp(Creature.cpp)
    Ardit Shala
    a.shala@jacobs-university.de
*/

#include <iostream>
#include "Creature.h"

using namespace std;

Creature::Creature(): distance(10) //constructor for creature
{
    cout << "Creature default constructor is being called" << endl;
}

void Creature::run() const // method for run
{
    cout << "running " << distance << " meters!\n";
}

Wizard::Wizard() : distFactor(3) // constructor
{
    cout << "Wizard constructor is being called " << endl;
}

void Wizard::hover() const // method
{
    cout << "hovering " << (distFactor * distance) << " meters!\n";
}

Creature1::Creature1() : length(5) //constructer
{
    cout << "The Creature1 constructor is being called " << endl; //messeges being called
}

Creature1::~Creature1() //destructor
{
    cout << "Destructor of Creature1 is being called" << endl;
}

void Creature1::body() const //method body
{
    cout << "body " << (length * 5) << "centimeters!\n" << endl;
}

Creature2::Creature2() : year(4) //constructor of creature2
{
    cout << "The Creature2 constructor is being called" << endl;
}

Creature2::~Creature2() // destructor of creature2
{
    cout << "The Creature2 destructor is being called" << endl;
}

void Creature2::life() const // method life of creature 2
{
    cout << "life " << (year * distance) << "idk!\n" << endl;
}
