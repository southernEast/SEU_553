#include <iostream>
using namespace std;

// 方法一 假设最大位数
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

//// 方法二 不假设最大位数
//char* intToStr(int a) {
//	int num = a, cnt = 0;
//	while (num) {	// 去a的位数
//		++cnt;
//		num /= 10;
//	}
//
//	num = a;
//	char* ptr = new char[cnt + 1]();// 多分配一个单位的空间给'\0' 同时数组初始化为0
//	--cnt;		// 略过最后一个'\0'的位置
//	while (cnt >= 0) {	// 取数字
//		ptr[cnt--] = num % 10 + '0';
//		num /= 10;
//	}
//	return ptr;
//}

int main() {
	int a;
	char* str;
	cin >> a;
	str = intToStr(a);
	cout << str;
	delete[] str;

	return 0;
}