#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include "Shape.h"
#include "Point.h"

class Circle : public Shape {
public:
	Circle(double x, double y, double r) : radius(r) {
		p.x = x;
		p.y = y;
	}
	Circle(Point p, double radius) : p(p), radius(radius) {}
	virtual double calculate() const override {
		return PI * radius * radius;		// 圆形面积为PI*r^2
	}
private:
	const double PI = 3.14159;
	Point p;
	double radius;
};

#endif // !_CIRCLE_H_