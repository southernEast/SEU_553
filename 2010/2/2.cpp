#include <iostream>
#include <array>			// 容器不是关键关键在于算法
using namespace std;

template<typename T, size_t size>
void insertSort(array<T, size>& items) {		// 迭代插入排序
	T val;
	for (size_t i = 1; i < size; ++i) {			// 从元素1开始选择，单个元素0默认有序
		val = items[i];							// 需要插入的值
		size_t j;
		for (j = i; j > 0; --j) {				// 另一种方法为有哨兵的循环方法
			if (val < items[j - 1])				// 即将循环与判断大小相结合
				items[j] = items[j - 1];
			else
				break;
		}
		items[j] = val;
	}
}
template<typename T, size_t size>				// 递归插入排序
void recursiveInsertSort(array<T, size>& items, size_t pos) {
	if (pos > 0) {
		recursiveInsertSort(items, pos - 1);	// 不断递归，直至只有一个元素为有序
		T val = items[pos];						// 从元素个数少逐个往上返回排序，待插入元素
		size_t i;
		for (i = pos; i > 0; --i) {
			if (val < items[i - 1])
				items[i] = items[i - 1];
			else
				break;
		}
		items[i] = val;
	}
}

int main() {
	array<int, 10> items = { 1, 1, 2, 5, 3, 0, 6, 7, 0, 2 };
	recursiveInsertSort(items, 9);
	for (size_t i = 0; i < items.size(); ++i) {
		cout << items[i] << " ";
	}

	return 0;
}