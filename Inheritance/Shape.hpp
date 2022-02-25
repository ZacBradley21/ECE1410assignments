#ifndef SHAPE_HPP
#define SHAPE_HPP

class Shape {
	static int staticvariable;
public:
	Shape();
	~Shape();
	virtual double calculateArea() const = 0;
	virtual double calculatePerimeter() const = 0;
	int getId();
	void printInformation();

private:
	const int id;
};

#endif