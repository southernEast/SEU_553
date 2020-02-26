#ifndef _POINT_H_
#define _POINT_H_

class Point {
public:
	Point(double xx = 0, double yy = 0) : x(xx), y(yy) {}
	Point(const Point& p) {			// 点的复制构造函数，方便直接将点作为整体进行参数传递
		x = p.x;
		y = p.y;
	}
	Point& operator=(const Point& p) {	
		x = p.x;
		y = p.y;
	}
	double x;
	double y;	
};

#endif // !_POINT_H_