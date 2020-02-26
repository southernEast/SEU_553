#include <iostream>
#include <array>
using namespace std;

template<typename T, size_t size>
int findMin(const array<T, size>& a, int nowPos) {
	static int minPos = 0;				// 声明为静态变量，固定存储最小元素的地址
	if (nowPos >= 0) {
		if (a[nowPos] < a[minPos])
			minPos = nowPos;
		return findMin(a, nowPos - 1);
	}
	else
		return minPos;
}

int main() {
	array<int, 10> a = { 1, 2, 3, 4, 5, 6, 7, -1, -10 };
	int temp = 9, pos = findMin(a, 9);
	cout << a[pos];

	return 0;
}