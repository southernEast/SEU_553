#include <iostream>
#include <cstring>
#include <string>
using namespace std;

// 解法一：不能延长原字符串的做法，保留初始字符串长度
void findRepStr1(char str[], const char findStr[], const char replaceStr[]) {
	int len = strlen(replaceStr), originLen = strlen(str);
	char* pos = strstr(str, findStr);
	while (pos) {
		for (int i = 0; i < len; ++i) {			// 替换字符串
			if (pos - str + i < originLen) {	// 在不超过原始长度的情况下替换
				str[pos - str + i] = replaceStr[i];
			}
		}
		pos = strstr(str, findStr);
	}
	cout << str << endl;
}

// 解法二：无条件替换字符串，即使超出范围
void findRepStr2(char str[], const char findStr[], const char replaceStr[]) {
	string s1(str), s2(findStr), s3(replaceStr);

	size_t pos = s1.find(s2);
	while (pos != string::npos) {
		s1.replace(pos, s2.size(), s3);
		pos = s1.find(s2);
	}
	cout << s1 << endl;
}

int main() {
	char str[] = "Gao m za Enza za";
	char findStr[] = "za";
	char replaceStr[] = "Van";

	findRepStr2(str, findStr, replaceStr);

	return 0;
}