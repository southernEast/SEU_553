#include <iostream>
using namespace std;

void sortOne(string str[], int n) {		// 插入排序
	string val;
	for (int i = 1; i < n; ++i) {
		val = str[i];

		// 往有序序列中插入一个新的值
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

		// 选出一个当前无序序列中的最小值放在有序序列最后面
		for (int j = i + 1; j < n; ++j) {
			if (str[j] < str[minPos])
				minPos = j;
		}
		swap(str[minPos], str[i]);
	}
}

/**
如果将string换成char*，则将比较操作换为strcmp函数，
并将暂存字符串的变量换成char*，具体例子如下：

void insertSort(const char* str[], int n) {
	const char* val;
	for (int i = 1; i < n; ++i) {
		val = str[i];

		// 往有序序列中插入一个新的值
		int j = i;
		while (j > 0 && strcmp(val, str[j - 1]) < 0) {
			str[j] = str[j - 1];
			--j;
		}
		str[j] = val;
	}
}
void selectSort(const char* str[], int n) {
	int minPos;
	for (int i = 0; i < n; ++i) {
		minPos = i;

		// 选出一个当前无序序列中的最小值放在有序序列最后面
		for (int j = i + 1; j < n; ++j) {
			if (strcmp(str[j], str[minPos]) < 0)
				minPos = j;
		}
		swap(str[minPos], str[i]);
	}
}
**/

int main() {
	string str[] = { "dsahiubaoas" , "asa", "cbasi", "zsaioj" };
	sortOne(str, sizeof(str) / sizeof(str[0]));
	/*sortTwo(str, sizeof(str) / sizeof(str[0]));*/
	for (auto& elem : str) {
		cout << elem << endl;
	}

	/*const char* str[] = { "dsahiubaoas" , "asa", "cbasi", "zsaioj" };
	insertSort(str, sizeof(str) / sizeof(str[0]));
	selectSort(str, sizeof(str) / sizeof(str[0]));
	for (auto elem : str) {
		cout << elem << endl;
	}*/

	return 0;
}