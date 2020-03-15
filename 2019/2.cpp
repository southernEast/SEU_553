#include <iostream>
using namespace std;

template<typename T>
int findMin(T a[], int last) {
	static int minPos = last;		// 记录最小元素位置
	if (last >= 0) {				// 如果还有元素，则递归查找
		if (a[minPos] > a[last])
			minPos = last;
		findMin(a, last - 1);
	}
	return minPos;
}

int main() {
	int a[10] = { 2, 1, 0, 9, 8, 4, 6, -5 };
	int pos = findMin(a, 9);
	cout << a[pos];

	return 0;
}