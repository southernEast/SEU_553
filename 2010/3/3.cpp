#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void getDataSimple(ifstream& in) {			// 如果输入是简单的固定长度的数字序列
	string str;								// 可以使用这样的方法
	while (in >> str) {
		cout << str.substr(1, 3) << "|"
			<< str.substr(6, 11) << "|"
			<< str.substr(19, 3) << "|"
			<< str.substr(24, 6) << endl;
	}
}
void getDataComplicated(ifstream& in) {		// 如果是不定长度的数字序列
	string str;
	char tag[] = "()()||()";				// 分割符
	
	while (in >> str) {
		string::iterator it = str.begin();	// 遍历迭代器
		int tagNum = 0;						// 标记分隔符
		bool frontIsChar = false;			// 上一次访问是否是字符

		while (it != str.end()) {
			if (*it == tag[tagNum]) {
				if (frontIsChar && it != str.end() - 1)	// 如果上一次访问是字符且不是最后一组数字序列
					cout << '|';			// 则输出新的分隔符
				++tagNum;
				frontIsChar = false;
			}
			else {
				cout << *it;				// 输出字符序列
				frontIsChar = true;
			}
			++it;
		}
		cout << endl;
	}
}

int main() {
	ifstream input("info.txt", ios::in);
	//getDataSimple(input);
	getDataComplicated(input);
	
	return 0;
}