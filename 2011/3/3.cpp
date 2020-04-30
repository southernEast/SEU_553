#include <iostream>
#include <ctime>
using namespace std;

template <typename T>
int findMin(T a[], int left, int right) {
	if (left == right)	// 如果只剩一个元素，直接返回
		return left;
	int mid = (left + right) / 2, leftIndex, rightIndex;
	leftIndex = rightIndex = left;	// 初始化
	if (left <= mid)	// 区间正确才递归
		leftIndex = findMin(a, left, mid);
	if (right >= mid + 1)
		rightIndex = findMin(a, mid + 1, right);

	return (a[leftIndex] < a[rightIndex] ? leftIndex : rightIndex);	// 返回值较小的下标
}

//！！错误解法！！
//试考虑如果先后调用一个int [20]和一个int [10]的数组
//如果第一次的minPos大于9，则第二次调用会造成越界访问
//template<typename T>
//int findMin(T a[], int nowPos) {
//	static int minPos = 0;	// 声明为静态变量，固定存储最小元素的地址
//	if (nowPos >= 0) {
//		cout << a[minPos] << endl;
//		if (a[nowPos] < a[minPos])
//			minPos = nowPos;
//		return findMin(a, nowPos - 1);
//	}
//	else
//		return minPos;
//}

int main() {
	const int SIZE = 20;
	srand(time(0));
	int a[SIZE];
	for (int i = 0; i < SIZE; ++i) {
		a[i] = rand() % SIZE;
		cout << a[i] << " ";
	}
	cout << endl;

	int minIndex = findMin(a, 0, SIZE - 1);
	cout << "\nmin index: " << minIndex << "\nmin value: " << a[minIndex] << endl;

	return 0;
}