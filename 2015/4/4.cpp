#include <iostream>
#include <cstring>
#include <string>
using namespace std;

// 解法一：finStr与replaceStr字符串长度相同的替换
void findRepStr1(char str[], const char findStr[], const char replaceStr[]) {
	int len = strlen(replaceStr), findLen = strlen(findStr);
	char* pos = strstr(str, findStr);
	while (pos) {
		for (int i = 0; i < findLen; ++i)
			*(pos + i) = replaceStr[i];
		pos = strstr(str, findStr);
	}
	cout << str << endl;
}

// 解法二：findStr与replaceStr字符串长度不同的替换
void findRepStr2(char str[], const char findStr[], const char replaceStr[]) {
	string s1(str), s2(findStr), s3(replaceStr);

	size_t pos = s1.find(s2);
	while (pos != string::npos) {
		s1.replace(pos, s2.size(), s3);
		pos = s1.find(s2);
	}
	cout << s1 << endl;
}
// 解法三：不使用STL和string替换不同长度的字符串
void findRepStr3(char str[], const char findStr[], const char replaceStr[]) {
	int strLen = strlen(str);
	int findLen = strlen(findStr);
	int repLen = strlen(replaceStr);
	int newLen = strLen - findLen + repLen + 1;

	char *pos = strstr(str, findStr);
	char *res = new char[newLen];

	//pos-str 为在替换字符串之前原字符串的长度
	//(pos-str)+findLen 为在替换字符串之后原字符串的长度
	//其实原理就是分三段拼接
	int cnt = 0;
	for (int i = 0; i < (pos - str); ++i)
		res[cnt++] = str[i];
	for (int i = 0; i < repLen; ++i)
		res[cnt++] = replaceStr[i];
	for (int i = (pos - str) + findLen; i < strLen; ++i)
		res[cnt++] = str[i];
	res[cnt] = '\0';

	cout << res << endl;
}

int main() {
	char str[] = "Gao m za Enza za";
	char findStr[] = "za";
	char replaceStr[] = "Van";

	findRepStr2(str, findStr, replaceStr);

	return 0;
}
