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

int main() {
	char str[] = "Gao m za Enza za";
	char findStr[] = "za";
	char replaceStr[] = "Van";

	findRepStr2(str, findStr, replaceStr);

	return 0;
}