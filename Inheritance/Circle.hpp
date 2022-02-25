#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "Shape.hpp"

class Circle : public Shape
{
public:
	Circle();
	~Circle();
	Circle(double radius);
	virtual double calculateArea() const override final;
	virtual double calculatePerimeter() const override final;

private:
	double r;
};

#endif