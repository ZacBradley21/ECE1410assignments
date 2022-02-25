#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "Shape.hpp"

class Rectangle : public Shape
{
public:
	Rectangle();
	~Rectangle();
	Rectangle(double width, double height);
	virtual double calculateArea() const override final;
	virtual double calculatePerimeter() const override final;

private:
	double w;
	double h;
};

#endif