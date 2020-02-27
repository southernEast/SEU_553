#include <iostream>
#include <array>
#include <ctime>
#include <vector>
using namespace std;

template<typename T, size_t size>
void selectSort(array<T, size>& a) {		// 选择排序
	size_t minPos = 0;
	for (size_t i = 0; i < size; ++i) {
		minPos = i;
		for (size_t j = i + 1; j < size; ++j) {
			if (a[j] < a[minPos])			// 每次从中选择一个最小的元素
				minPos = j;
		}
		swap(a[i], a[minPos]);				// 放置到当前的第一个位置
	}
}

template<size_t size>
void bucketSort(array<int, size>& a) {		// 桶排序或基数排序
	// 选取出数组中最大的元素，并计算其有多少个位，这里的位是个十百千这种
	int maxVal = a[0];
	for (size_t i = 1; i < size; ++i)
		if (maxVal < a[i])
			maxVal = a[i];
	int bitsNum = 0;
	while (maxVal) {
		++bitsNum;
		maxVal /= 10;
	}
	array<vector<int>, 10> buckets;

	// 有多少个位则进行多少趟排序
	for (int i = 0; i < bitsNum; ++i) {
		int divNum = 1;
		for (int n = 0; n < i; ++n)		// 确定除数，用来取相应位置的数字
			divNum *= 10;
		for (size_t j = 0; j < size; ++j) {
			buckets[a[j] / divNum % 10].push_back(a[j]);	// 放入相应的桶中
		}
		int pos = 0;
		for (size_t j = 0; j < 10; ++j) {
			for (size_t k = 0; k < buckets[j].size(); ++k)
				a[pos++] = buckets[j][k];	// 按序收集桶中的数
			buckets[j].clear();				// 桶清空，准备下一次排序
		}
	}
}

int main() {
	srand(time(0));
	array<int, 10> a;
	for (int& elem : a) {		// 注意这里需要使用引用来赋值
		elem = rand() % 1000;
		cout << elem << " ";
	}
	cout << endl;

	//selectSort(a);
	bucketSort(a);
	for (int elem : a) {
		cout << elem << " ";
	}

	return 0;
}