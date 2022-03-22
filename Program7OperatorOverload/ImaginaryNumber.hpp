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
#include <math.h>

/*
Program Header
Function Title: ImaginaryNumber
Summary: This file performs the overloading for all instances we are required
to do them for.
Inputs: None
Outputs: None
**********************
PSEUDOCODE
Begin
	Create class called ImaginaryNumber
	Make a public section
	Initialize all different constructors and functions
	Overload <<
	Overload +=
	Overload +
	Overload -=
	Overload -
	Overload *=
	Overload *
	Overload /=
	Overload /
	Overload =
	Overload !=
	Overload <
	Overload >
	Overload <=
	Overload >=
	Overload ==
	Make a private section and initialize real and imaginary
End
*/

//Begin
#ifndef IMAGINARY_NUMBER_HPP
#define IMAGINARY_NUMBER_HPP

//Create class
class ImaginaryNumber
{
public:
//Initialize all different constructors and functions
	ImaginaryNumber();
	~ImaginaryNumber();
	ImaginaryNumber(double real, double imaginary);
	double getReal();
	double getImaginary();
//Overload <<
	friend std::ostream& operator<<(std::ostream& os, ImaginaryNumber const& in)
	{
		if (in.imaginary == 0)
		os << in.real;
		else if (in.real == 0)
			os << in.imaginary << "j";
		else
		os << in.real << " + " << in.imaginary << "j";
		return os;
	}
//Overload +=
	ImaginaryNumber& operator+=(const ImaginaryNumber& rhs)
	{
		*this = *this + rhs;
		return *this;
	}
//Overload +
	friend ImaginaryNumber operator+(ImaginaryNumber lhs, const ImaginaryNumber& rhs)
	{
		double a, b;
		a = lhs.real + rhs.real;
		b = lhs.imaginary + rhs.imaginary;
		lhs.real = a;
		lhs.imaginary = b;
		//lhs.real = (lhs.real + rhs.real) + (lhs.imaginary + rhs.imaginary);
		return lhs;
	}
//Overload -=
	ImaginaryNumber& operator-=(const ImaginaryNumber& rhs)
	{
		*this = *this - rhs;
		return *this;
	}
//Overload -
	friend ImaginaryNumber operator-(ImaginaryNumber lhs, const ImaginaryNumber& rhs)
	{
		double a, b;
		a = lhs.real - rhs.real;
		b = lhs.imaginary - rhs.imaginary;
		lhs.real = a;
		lhs.imaginary = b;
		return lhs;
	}
//Overload *=
	ImaginaryNumber& operator*=(const ImaginaryNumber& rhs)
	{
		*this = *this * rhs;
		return *this;
	}
//Overload *
	friend ImaginaryNumber operator*(ImaginaryNumber lhs, const ImaginaryNumber& rhs)
	{
		lhs.real = (lhs.real * rhs.real);
		lhs.imaginary = (lhs.imaginary * rhs.imaginary);
		return lhs;
	}
//Overload /=
	ImaginaryNumber& operator/=(const ImaginaryNumber& rhs)
	{
		*this = *this / rhs;
		return *this;
	}
//Overload /
	friend ImaginaryNumber operator/(ImaginaryNumber lhs, const ImaginaryNumber& rhs)
	{
		double a, b;
		if (rhs.real == 0 && rhs.imaginary == 0) {
			lhs.real = 0;
			lhs.imaginary = 0;
		}
		else {
			a = ((lhs.real * rhs.real) + (lhs.imaginary * rhs.imaginary)) /
				((rhs.real * rhs.real) + (rhs.imaginary * rhs.imaginary));
			b = ((lhs.imaginary * rhs.real) - (lhs.real * rhs.imaginary)) /
				((rhs.real * rhs.real) + (rhs.imaginary * rhs.imaginary));
			lhs.real = a;
			lhs.imaginary = b;
		}
		return lhs;
	}
//Overload =
	ImaginaryNumber& operator=(ImaginaryNumber other) noexcept
	{
		std::swap(real, other.real);
		std::swap(imaginary, other.imaginary);
		return *this;
	}
//Overload !=
	friend inline bool operator!=(ImaginaryNumber const& lhs, ImaginaryNumber const& rhs)
	{
		if (lhs.real == rhs.real) return false;
		static const double delta = .00001;
		return std::abs(lhs.real - rhs.real) < delta;
	}
//Overload <
	friend inline bool operator<(ImaginaryNumber const& lhs, ImaginaryNumber const& rhs)
	{
		if (std::sqrt(std::pow(lhs.real, 2) + std::sqrt(std::pow(lhs.imaginary, 2)))
			< std::sqrt(std::pow(rhs.real, 2)) + std::sqrt(std::pow(rhs.imaginary, 2)))
		{
			return true;
		}
		else
			return false;
	}
//Overload >
	friend inline bool operator>(ImaginaryNumber const& lhs, ImaginaryNumber const& rhs)
	{
		if (std::sqrt(std::pow(lhs.real, 2) + std::sqrt(std::pow(lhs.imaginary, 2)))
			> std::sqrt(std::pow(rhs.real, 2)) + std::sqrt(std::pow(rhs.imaginary, 2)))
		{
			return true;
		}
		else
			return false;

	}
//Overload <=
	friend inline bool operator<=(ImaginaryNumber const& lhs, ImaginaryNumber const& rhs)
	{
		if (std::sqrt(std::pow(lhs.real, 2) + std::sqrt(std::pow(lhs.imaginary, 2)))
			<= std::sqrt(std::pow(rhs.real, 2)) + std::sqrt(std::pow(rhs.imaginary, 2)))
		{
			return true;
		}
		else if (!(std::sqrt(std::pow(lhs.real, 2) + std::sqrt(std::pow(lhs.imaginary, 2)))
			<= std::sqrt(std::pow(rhs.real, 2)) + std::sqrt(std::pow(rhs.imaginary, 2))))
		{
			return false;
		}
		else
			return false;
	}
//Overload >=
	friend inline bool operator>=(ImaginaryNumber const& lhs, ImaginaryNumber const& rhs)
	{
		if (std::sqrt(std::pow(lhs.real, 2) + std::sqrt(std::pow(lhs.imaginary, 2)))
		>= std::sqrt(std::pow(rhs.real, 2)) + std::sqrt(std::pow(rhs.imaginary, 2)))
		{
			return true;
		}
		else if (!(std::sqrt(std::pow(lhs.real, 2) + std::sqrt(std::pow(lhs.imaginary, 2)))
		>= std::sqrt(std::pow(rhs.real, 2)) + std::sqrt(std::pow(rhs.imaginary, 2))))
		{
			return false;
		}
		else
			return false;
	}
//Overload ==
	friend bool operator==(ImaginaryNumber const& lhs, ImaginaryNumber const& rhs)
	{
		static const double delta = .000001;
		return std::abs(lhs.imaginary - rhs.imaginary) < delta 
			&& std::abs(lhs.imaginary - rhs.imaginary) < delta;
	}
//Make a private section and initialize real and imaginary
private:
	double real;
	double imaginary;
};
#endif
//End