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
Function Title: Shape
Summary: This file will construct the shape class, get the id and return a copy,
and have a printInformation function which will print the id, area, and perimeter
in the main file.
Inputs: None
Outputs: id
**********************
PSEUDOCODE
Begin
	Initialize the shape constructor
	Initialize the deconstructor
	Initialize the getId function that returns a copy of id
	Initialize the printInformation functions that prints id, area, and perimeter
End
*/

int Shape::staticvariable = 0;

Shape::Shape()
	: id(staticvariable++)
{
}

Shape::~Shape()
{
}

int Shape::getId()
{
	return id;
}

void Shape::printInformation()
{
	std::cout << "id: " << id << std::endl;
	std::cout << "Area: " << calculateArea() << std::endl;
	std::cout << "Perimeter: " << calculatePerimeter() << std::endl;
}
