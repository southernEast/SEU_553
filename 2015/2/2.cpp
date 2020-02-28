#include <iostream>
#include <string>
using namespace std;

void getInt(const string& str) {
	if (str.size() != 0) {		// 如果当前字符串长度不为零，说明可以继续递归
		getInt(str.substr(1, str.size() - 1));	// 去除当前字符串第一个字符继续递归
		if (isdigit(str[0]))	// 如果是数字则输出，在递归之后，为反序输出
			cout << str[0];
	}
}

int main() {
	string str;
	getline(cin, str);
	getInt(str);

	return 0;
}