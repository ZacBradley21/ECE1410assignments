#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "Shape.hpp"

class Rectangle : public Shape
{
public:
	Rectangle();
	~Rectangle();
	Rectangle(int width, int height);
	virtual double calculateArea() const override final;
	virtual double calculatePerimeter() const override final;

private:
	int w;
	int h;
};

#endif