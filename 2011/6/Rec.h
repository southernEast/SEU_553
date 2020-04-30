#ifndef _REC_H_
#define _REC_H_

#include "Shape.h"
#include "Point.h"
#include <cmath>

class Rec : public Shape {
public:
	Rec(double x1, double y1, double x2, double y2) :
		p1(x1, y1), p2(x2, y2) {}
	Rec(Point p1, Point p2) : p1(p1), p2(p2) {}
	virtual double calculate() const override {
		double len1 = fabs(p2.y - p1.y);
		double len2 = fabs(p2.x - p1.x);
		return len1 * len2;			// 矩形面积为两边长的乘积
	}
private:
	Point p1, p2;
};

#endif // !_REC_H_