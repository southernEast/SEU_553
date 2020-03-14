#include <iostream>
#include <fstream>
#include "Shape.h"
#include "Circle.h"
#include "Tri.h"
#include "Rec.h"
#include "Point.h"
using namespace std;

int main() {
	ifstream input("file.txt", ios::in);
	if (!input) {
		cerr << "The file cannot be opened";
		exit(EXIT_FAILURE);
	}
	Point p1, p2, p3;
	double radius;
	Shape* shapes[3];	// 基类指针数组，用于多态性调用函数
	string outInfo[3] = { "Circle: ", "Triangle: ", "Rectangle: " };	// 用于输出信息

	char ch;		// 用于过滤不需要的字符
	while (input >> ch) {
		// 读取圆形的参数
		input >> ch;
		input >> p1.x >> ch >> p1.y >> ch >> radius >> ch;
		Circle c(p1, radius);
		shapes[0] = &c;
		// 读取三角形的参数
		input >> ch >> ch;
		input >> p1.x >> ch >> p1.y >> ch >> p2.x >> ch
			>> p2.y >> ch >> p3.x >> ch >> p3.y >> ch;
		Tri t(p1, p2, p3);
		shapes[1] = &t;
		// 读取矩形的参数
		input >> ch >> ch;
		input >> p1.x >> ch >> p1.y >> ch >> p2.x >> ch
			>> p2.y >> ch;
		Rec r(p1, p2);
		shapes[2] = &r;

		// 输出计算面积
		for (int i = 0; i < 3; ++i) {
			cout << outInfo[i] << shapes[i]->calculate() << endl;
		}
		cout << endl;
	}

	return 0;
}