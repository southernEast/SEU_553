#ifndef _TRI_H_
#define _TRI_H_

#include "Shape.h"
#include "Point.h"
#include <cmath>

/**
此处用到的三角形面积公式：
根据三个点A(x1, y1), B(x2, y2), C(x3, y3)
				|x1 y1 1|
	S = 0.5  *	|x2 y2 1|  再行列式展开得公式
				|x3 y3 1|
**/

class Tri : public Shape {
public:
	Tri(double x1, double y1, double x2, double y2, double x3, double y3) {
		p1.x = x1;
		p1.y = y1;
		p2.x = x2;
		p2.y = y2;
		p3.x = x3;
		p3.y = y3;
	}
	Tri(Point p1, Point p2, Point p3) : p1(p1), p2(p2), p3(p3) {}
	virtual double calculate() const override {
		return fabs(p1.x * p2.y + p2.x * p3.y + p3.x * p1.y
			- p1.x * p3.y - p2.x * p1.y - p3.x * p2.y) * 0.5;
	}
private:
	Point p1, p2, p3;
};

#endif // !_TRI_H_