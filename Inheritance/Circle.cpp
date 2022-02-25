#include "Circle.hpp"
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
Function Title: Circle
Summary: This file will construct an empty circle, take the radius and
make calculations on it to get the area and perimeter.
Inputs: Radius
Outputs: Area and perimeter
**********************
PSEUDOCODE
Begin
	Initialize an empty circle
	Initialize the deconstructor
	Initialize a circle that takes in a radius
	Use the radius to calculate the area of the circle and return a double
	Use the radius again to calculate the perimeter of the circle and return a double
End
*/

Circle::Circle()
	: Shape(), r(0)
{
}

Circle::~Circle()
{
}

Circle::Circle(int radius)
	: Shape(), r(radius)
{
}

double Circle::calculateArea() const
{
	double pi = 3.14;
	double circA = pi * (r * r);
	return circA;
}

double Circle::calculatePerimeter() const
{
	double pi = 3.14;
	double circP = 2 * pi * r;
	return circP;
}