#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Shape.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <thread>
#include <vector>
#include <sstream>
#include <stack>

/*
Program Header
Function Title: main
Summary: This file will pass perameters for two rectangles and two circles
and then print the information that the other files will manipulate.
Inputs: None
Outputs: None
**********************
PSEUDOCODE
Begin
	Create a pointer called r0 that points to rectangle and set
	it equal to a new rectangle and pass in parameters
	Repeat once using different pointer name and different parameters
	Create a pointer called c0 that points to circle and set
	it equal to a new circle and pass in parameters
	Repeat once using different pointer name and different parameters
	Print the information for 2 circles and 2 rectangles
	For every new, there shall be a delete, so delete the new pointers
End
*/

int main(void) {
	Rectangle* r0 = new Rectangle(15, 20);
	Rectangle* r1 = new Rectangle(30, 50);
	Circle* c2 = new Circle(50);
	Circle* c3 = new Circle(10);
	r0->printInformation();
	r1->printInformation();
	c2->printInformation();
	c3->printInformation();
	delete r0;
	delete r1;
	delete c2;
	delete c3;
	return 0;
}