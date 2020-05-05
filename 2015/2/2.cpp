#include <iostream>
#include <string>
using namespace std;

// 方法一 使用cout直接输出
void getInt(const string& str) {
	if (str.size() != 0) {		// 如果当前字符串长度不为零，说明可以继续递归
		getInt(str.substr(1, str.size() - 1));	// 去除当前字符串第一个字符继续递归
		if (isdigit(str[0]))	// 如果是数字则输出，在递归之后，为反序输出
			cout << str[0];
	}
}

// 方法二 转换成int型再输出，pos初始传入0
int change(string s, int pos) {
	if (pos < s.size() - 1 && isdigit(s[pos]))	// 如果还有字符且当前字符是数字
		return change(s, pos + 1) * 10 + s[pos] - '0';	// 将当前之后的数字乘10再加当前数字
	else if (pos < s.size() - 1)
		return change(s, pos + 1);	// 如果当前不是数字直接返回
	else	// 是最后一个数字，直接返回
		return s[pos] - '0';
}

int main() {
	string str;
	getline(cin, str);
	getInt(str);
	/*cout << change(str, 0);*/
	
	return 0;
}