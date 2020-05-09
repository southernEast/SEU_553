#include <iostream>
using namespace std;

// 基于二分查找递归
template <typename T>
int findMin1(T a[], int left, int right) {
	if (left == right)	// 如果只剩一个元素，直接返回
		return left;
	int mid = (left + right) / 2, leftIndex, rightIndex;
	leftIndex = rightIndex = left;	// 初始化
	if (left <= mid)	// 区间正确才递归
		leftIndex = findMin1(a, left, mid);
	if (right >= mid + 1)
		rightIndex = findMin1(a, mid + 1, right);

	return (a[leftIndex] < a[rightIndex] ? leftIndex : rightIndex);	// 返回值较小的下标
}

// 简单递归
template<typename T>
int findMin2(T a[], int n) {
	if (n > 0) {
		int minIndex = findMin2(a, n - 1);
		return (a[minIndex] < a[n] ? minIndex : n);
	}
	else
		return n;
}

//！！错误解法！！
//试考虑如果先后调用一个int [20]和一个int [10]的数组
//如果第一次的minPos大于9，则第二次调用会造成越界访问
//template<typename T>
//int findMin(T a[], int last) {
//	static int minPos = last;		// 记录最小元素位置
//	if (last >= 0) {				// 如果还有元素，则递归查找
//		if (a[minPos] > a[last])
//			minPos = last;
//		return findMin(a, last - 1);
//	}
//	return minPos;
//}

int main() {
	int a[10] = { 2, 1, 0, 9, 8, 4, 6, -5 };
	int pos = findMin1(a, 0, sizeof(a) / sizeof(a[0]) - 1);
	//int pos = findMin2(a, sizeof(a) / sizeof(a[0]) - 1);
	cout << a[pos];

	return 0;
}