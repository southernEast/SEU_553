#include <iostream>
using namespace std;

void sortOne(string str[], int n) {		// 插入排序
	string val;
	for (int i = 1; i < n; ++i) {
		val = str[i];
		int j = i;
		while (j > 0 && val < str[j - 1]) {
			str[j] = str[j - 1];
			--j;
		}
		str[j] = val;
	}
}

void sortTwo(string str[], int n) {		// 选择排序
	int minPos;
	for (int i = 0; i < n; ++i) {
		minPos = i;
		for (int j = i + 1; j < n; ++j) {
			if (str[j] < str[minPos])
				minPos = j;
		}
		swap(str[minPos], str[i]);
	}
}

int main() {
	string str[] = { "dsahiubaoas" , "asa", "cbasi", "zsaioj"};
	sortTwo(str, sizeof(str) / sizeof(str[0]));
	for (auto elem : str) {
		cout << elem << endl;
	}

	return 0;
}