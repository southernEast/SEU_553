#include <iostream>
using namespace std;

template <typename T>
int binarySearch(T a[], int left, int right, T elem) {
	if (left <= right) {			// 如果查找范围仍有元素则继续查找
		int mid = (left + right) / 2;	// 二分中点
		if (a[mid] == elem)		// 找到元素
			return mid;
		else if (a[mid] < elem)	// 往右半边递归
			binarySearch(a, mid + 1, right, elem);
		else					// 往左半边递归
			binarySearch(a, left, mid - 1, elem);
	}
	else			// 没有找到
		return -1;
}

int main() {
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int n = sizeof(a) / sizeof(a[0]);
	int pos = binarySearch(a, 0, n - 1, 9);
	cout << "Index: " << pos << "\nElement: " << a[pos];

	return 0;
}