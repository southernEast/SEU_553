#include <iostream>
#include <vector>
using namespace std;

int main() {
	int sum = 0, half;
	vector<int> numbers;		// 用来保存完数的因子

	for (int i = 1; i < 1000; ++i) {
		sum = 0;
		numbers.clear();
		half = i / 2;			// 初始化准备，每次因子只需要检测一半，后一半不可能取到

		for (int j = 1; j <= half; ++j) {	// 需要包括half本身
			if (i % j == 0) {
				sum += j;
				numbers.push_back(j);
			}
		}
		if (sum == i) {			// 如果是完数则按格式输出
			cout << i << "=" << numbers[0];
			for (size_t j = 1; j < numbers.size(); ++j)
				cout << "+" << numbers[j];
			cout << endl;
		}
	}
	return 0;
}