#ifndef _ARRAY_H_
#define _ARRAY_H_

/*****
	有几个问题需要注意：
	1、类模板不能将成员函数的声明与定义分别放在.h与.cpp文件中，然后在主函数中#include头文件，
	这样，主函数会报错，找不到函数定义，解决方法有两种，一是分别放于类内与类外，二是进行内联
	函数的定义。
	2、类模板的友元函数不能将声明和定义分别放在类声明内与类声明外，同样会报错，解决方法是放于
	类内定义，或者不使用友元。
*****/

#include <iostream>

template<typename T>
class Array {
	friend std::ostream& operator<< (std::ostream& out, const Array<T>& a) {
		for (int i = 0; i < a.row; ++i) {
			for (int j = 0; j < a.col; ++j)
				out << *(a.ptr + i * a.col + j) << " ";
			out << std::endl;
		}
		return out;
	}
public:
	Array(int r = 0, int c = 0);
	~Array();
	Array(const Array<T>& a);
	T& operator()(int r, int c);
private:
	T* ptr;
	int row, col;
};

template<typename T>
Array<T>::Array(int r, int c) {
	row = r;
	col = c;
	if (row * col == 0)
		ptr = nullptr;
	else
		ptr = new T[row * col]();
}
template<typename T>
Array<T>::~Array() {
	delete[] ptr;
}
template<typename T>
Array<T>::Array(const Array<T>& a) {
	row = a.row;
	col = a.col;
	ptr = new T[row * col]();
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j)
			*(ptr + i * col + j) = *(a.ptr + i * col + j);	// 注意是乘col而不是row
	}
}
template<typename T>
T& Array<T>::operator()(int r, int c) {
	if (r >= row || c >= col) {
		std::cerr << "Out of range" << std::endl;
		exit(EXIT_FAILURE);
	}
	return *(ptr + r * col + c);		// 注意是乘col而不是row
}

#endif // !_ARRAY_H_