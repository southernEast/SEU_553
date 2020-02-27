#include <iostream>
using namespace std;

char* intToStr(int a) {			// 将整型转换成字符串
	char temp[30] = { 0 };		// 暂存
	int cnt = 0;
	while (a) {					// 从后往前逐个取数字
		temp[cnt++] = a % 10 + '0'; 
		a /= 10;
	}
	char* ans = new char[cnt + 1];	// 多分一个字节给'\0'，之后需要手动删除动态分配的内存
	for (int i = 0; i < cnt; ++i)	// 反序存数字
		ans[i] = temp[cnt - i - 1];
	ans[cnt] = '\0';
	return ans;
}

int main() {
	int a;
	char* str;
	cin >> a;
	str = intToStr(a);
	cout << str;
	delete[] str;

	return 0;
}