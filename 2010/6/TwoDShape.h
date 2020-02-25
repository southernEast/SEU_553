#ifndef _TWODSHAPE_H_
#define _TWODSHAPE_H_

#include "Shape.h"

class TwoDShape : public Shape {
public:
	TwoDShape(int a = 0, int b = 0) : x(a), y(b) {}
	virtual int calculate() {
		return x * y;
	}
	int getX() const { return x; }
	int getY() const { return y; }
private:
	int x, y;
};

#endif // !_2DSHAPE_H_