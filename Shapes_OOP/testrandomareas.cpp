/*
	CH08-320142
	a6_p4.cpp(random areas)
	Ardit Shala
	a.shala@jacobs-university.de
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "Area.h"
#include "Circle.h"
#include "Ring.h"
#include "Rectangle.h"
#include "Square.h"

double funksioni2()
{
	int generator;
	generator = rand();
	return (generator % 50 + 1);
}

int main() {
	const int size = 20;
	Area *list[size];
	char *rcolor[] = { "RED","GREEN","BLUE","YELLOW" };
	int generator2;
	generator2 = rand();
	srand(time(NULL));
		
	Circle c1(rcolor[rand() % 4], funksioni2()); //creating a circle with random color and radius
	Square s1(rcolor[rand() % 4], funksioni2()); //creating a square with random color and side
	Rectangle r1(rcolor[rand() % 4], funksioni2(), funksioni2()); //creating a square with random color and 2 sides
	Ring r2(rcolor[rand() % 4], funksioni2(), funksioni2());//creating a ring with random color, radius and innerradius

	Area *a1[4] = { &c1, &s1, &r1, &r2 }; //creataing an array of objects 

	for (int j = 0; j < 20; j++) // the loop that creates 20 random objects
	{
		list[j] = a1[rand() % 3 + 1]; //create a random object and store that to list
	}
	

	int index = 0;
	double sum_area = 0.0;
	double sum_perimeter = 0.0;
	
	while (index < size) {					
		(list[index])->getColor();				
		sum_area += (list[index++])->calcArea();
		sum_perimeter += (list[index++])->calcPerimeter();
	}
	
	cout << "\nThe total area is "
			<< sum_area << " units " << endl;	

	cout << "\nThe total perimeter is "
		<< sum_perimeter << " units " << endl;

	return 0;
}
