#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include "Shape.h"
#include "Point.h"

class Circle : public Shape {
public:
	Circle(double x, double y, double r) : p(x, y), radius(r) {}
	Circle(Point p, double radius) : p(p), radius(radius) {}
	virtual double calculate() const override {
		return PI * radius * radius;		// 圆形的面积公式为 PI * r^2
	}
private:
	const double PI = 3.14159;
	Point p;
	double radius;
};

#endif // !_CIRCLE_H_