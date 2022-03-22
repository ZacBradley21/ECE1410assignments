#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <thread>
#include <vector>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <ostream>

#include "ImaginaryNumber.hpp"

/*
Program Header
Function Title: ImaginaryNumber
Summary: This file holds the function titles and different constructors
Inputs: None
Outputs: None
**********************
PSEUDOCODE
Begin
	Create default constructor
	Create deconstructor
	Create parameter constructor
	Create getReal function
	Create getImaginary function
End
*/

ImaginaryNumber::ImaginaryNumber() //Default Constructor
	:imaginary(0), real(0)
{

}

ImaginaryNumber::~ImaginaryNumber() //Deconstructor
{

}

ImaginaryNumber::ImaginaryNumber(double real, double imaginary) //Parameter Constructor
	:imaginary(imaginary), real(real)
{

}

double ImaginaryNumber::getReal() //getReal Function
{
	return real;
}

double ImaginaryNumber::getImaginary() //getImaginary Function
{
	return imaginary;
}
