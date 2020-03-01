#include <iostream>
#include <cstring>
using namespace std;

class Circle {
	double radius;
public:
	Circle(double r) : radius(r) {}
	double area() { return 3.14 * radius * radius; }
};
class Rect {
	double width, height;
public:
	Rect(double w, double h) { width = w; height = h; }
	double area() { return height * width; }
};
class RoundRect : public Circle, public Rect {
	char color[5];
public:						// 注意这里需要使用const char*，不然输入常量字符串可能会出错，也需要考虑最小权限原则
	RoundRect(double r, double w, double h, const char* c) : Circle(r), Rect(w, h) {
		strcpy(color, c);
	}
	char* getcolor() { return color; }
};

int main() {
	RoundRect rr(0.8, 1, 0.25, "白色");
	cout << rr.getcolor() << endl;

	return 0;
}