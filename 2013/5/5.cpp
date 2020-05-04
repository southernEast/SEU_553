#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char str[50] = { 0 };
	cin.getline(str, 20);

	char* ptr;
	ptr = strtok(str + 1, ")");		//  分割第一段
	cout << ptr << " ";
	ptr = strtok(nullptr, "-");		// 分割第二段

	cout << ptr << " ";
	ptr = strtok(nullptr, "");		// 分割第三段
	cout << ptr;
	/*
	//或者使用这个方法
	int len = strlen(ptr);
	cout << ptr << " " << (ptr + len + 1);	// 第三段以'\0'结束，跨过当前段的'\0'即可输出
	*/

	return 0;
}