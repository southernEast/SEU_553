#include <iostream>
#include <string>
using namespace std;

// 方法一 使用string类的成员函数
void split1(const string& inStr) {
	int pos = 0;	// 记录上次分割的位置
	for (size_t i = 0; i < inStr.size(); ++i) {
		if (inStr[i] == ' ') {	// 找到分割记号
			cout << inStr.substr(pos, i - pos) << ":  " << i - pos << endl;
			pos = i + 1;		// 更新下一次开始的地方，需要跳过一个' '
		}
		else if (i == inStr.size() - 1)	// 处理最后一个单词
			cout << inStr.substr(pos, i - pos + 1) << ":  " << i - pos + 1 << endl;
	}
}

// 方法二 使用C语言类型的字符串处理函数
void split2(const string& inStr) {
	char str[100] = { 0 };
	char* temPtr;

	inStr.copy(str, inStr.size());	// 转换成char*类型
	temPtr = strtok(str, " ");		// 不断按照分隔符取一段单词
	while (temPtr) {
		cout << temPtr << ": " << strlen(temPtr) << endl;	// 输出单词及其长度
		temPtr = strtok(nullptr, " ");
	}
}

int main() {
	string inStr;
	getline(cin, inStr);

	split1(inStr);
	cout << endl << endl;
	split1(inStr);

	return 0;
}