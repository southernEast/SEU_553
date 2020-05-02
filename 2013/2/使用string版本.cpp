#include <iostream>
#include <string>
using namespace std;

void encrypt(string& str) {			// 加密，将所有的字母上增1
	for (string::iterator it = str.begin(); it != str.end(); ++it) {
		if (islower(*it))		// 大小写字母分开判断
			*it = (*it - 'a' + 1) % 26 + 'a';	// 先获取当前字符在字母表中顺序，再进行运算取余
		else				// 最后再恢复字符形式
			*it = (*it - 'A' + 1) % 26 + 'A';
	}
}

void decrypt(string& str) {			// 解密，将所有的字母下减1
	for (string::iterator it = str.begin(); it != str.end(); ++it) {
		if (islower(*it))
			*it = (*it - 'a' + 26 - 1) % 26 + 'a';	// 减法要注意序号为负的情况，故先加上一个基数再运算
		else
			*it = (*it - 'A' + 26 - 1) % 26 + 'A';
	}
}

int main() {
	string str;
	cin >> str;
	cout << "Before encrpying:" << str << endl;
	encrypt(str);
	cout << "After encrpying: " << str << endl;
	decrypt(str);
	cout << "After decrpying: " << str << endl;

	return 0;
}