/*程序功能较简单，直接使用头文件与内联函数完成*/
#include <iostream>
#include "ThreeDShape.h"
#include "TwoDShape.h"
#include "Shape.h"
using namespace std;

int main() {
	Shape* ptr;
	ThreeDShape t3(1, 2, 3); 
	TwoDShape t2(1, 2);
	cout << "2D Shape: " << t2.calculate() << endl;
	cout << "3D Shape: " << t3.calculate() << endl;

	ptr = &t2;			// 使用基类指针，实现多态
	cout << "2D Shape: " << ptr->calculate() << endl;
	ptr = &t3;
	cout << "3D Shape: " << ptr->calculate() << endl;

	return 0;
}