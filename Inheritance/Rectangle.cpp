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
Function Title: Rectangle
Summary: This file will initialize a blank rectangle, then get width and height,
calculate the area and perimeter using width and height, and return those values
Inputs: Width, height
Outputs: Area and perimeter
**********************
PSEUDOCODE
Begin
	Initialize an empty rectangle
	Initialize the deconstructor
	Intialize a rectangle that passes in width and height
	Use width and height to calculate the area of the rectangle and return a double
	Use width and height to calculate the perimeter of the rectangle and return a double
End
*/

Rectangle::Rectangle()
	: Shape(), w(0), h(0)
{
}

Rectangle::~Rectangle()
{
}

Rectangle::Rectangle(int width, int height)
	: Shape(), w(width), h(height)
{
}

double Rectangle::calculateArea() const
{
	double rectA = h * w;
	return rectA;
}

double Rectangle::calculatePerimeter() const
{
	double rectP = 2 * h + 2 * w;
	return rectP;
}