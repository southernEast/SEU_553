#include <iostream>
using namespace std;

int f(char* s1, char* s2) {
	char* p = s1, * q = s2;
	
	/*判断当前两个字符是否相等的同时也需要判断是否达到字符串的末
	尾，这里判断结尾只判断其中一个字符串或者两个字符串都判断两种
	方法都可以，因为如果是q先达到末尾，则&&的第二个条件肯定不满足*/
	while (*p != '\0' && *p == *q) {	
		q++;
		p++;
	}

	// 最后再判断一下是否相同，如果是完全相等，即使两个字符串都到达'\0'也会相同，否则不同
	return *p == *q;
}

int main() {
	char s1[100] = { "abc" };		// 也可以使用getline输入，这里小改动
	char s2[100] = { "ab" };
	/*cin.getline(s1, 100);	
	cin.getline(s2, 100);*/
	cout << f(s1, s2);

	return 0;
}