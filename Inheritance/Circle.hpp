#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "Shape.hpp"

class Circle : public Shape
{
public:
	Circle();
	~Circle();
	Circle(int radius);
	virtual double calculateArea() const override final;
	virtual double calculatePerimeter() const override final;

private:
	int r;
};

#endif