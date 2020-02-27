#include <iostream>
using namespace std;

//void myReverse(int* a, int* b) {	// 在本例中效果与库函数中的reverse()一样，在不能使用STL的情况下备用
//	int temp;
//	while (b - a > 0) {			// 同一个数组中的两个指针可以相减
//		temp = *a;
//		*a = *b;
//		*b = temp;
//		++a;
//		--b;
//	}
//}

void swap(int a[], int m, int n) {
	//myReverse(a, a + m - 1);		// 不使用STL的情况下使用
	//myReverse(a + m, a + m + n - 1);
	//myReverse(a, a + m + n - 1);
	reverse(a, a + m - 1);			// 前面m个元素翻转
	reverse(a + m, a + m + n - 1);	// 后面n个元素翻转
	reverse(a, a + m + n - 1);		// 整体翻转
}

int main() {
	int a[10];
	cout << "Before swap: ";
	for (int i = 0; i < 10; ++i) {
		a[i] = rand() % 10;
		cout << a[i] << " ";
	}
	cout << endl;
	swap(a, 3, 7);
	cout << "After swap:  ";
	for (int elem : a) {
		cout << elem << " ";
	}

	return 0;
}