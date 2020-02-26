#ifndef _SHAPE_H_
#define _SHAPE_H_

class Shape {
public:
	virtual double calculate() const = 0;	// 纯虚函数，用于规范计算
};

#endif // !_SHAPE_H_
