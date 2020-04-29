#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

// 方法一，针对分隔符下手，处理不同的分隔符
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
	char tag[] = "()()||()";				// 分隔符

	while (in >> str) {
		string::iterator it = str.begin();	// 遍历迭代器
		int tagNum = 0;						// 标记分隔符位置
		bool frontIsChar = false;			// 上一次访问是否是字符

		while (it != str.end()) {
			if (*it == tag[tagNum]) {
				if (frontIsChar && it != str.end() - 1)	// 如果前面访问是字符且不是最后一组数字序列
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

// 方法二，把需要处理输出的数字直接用long long格式输入
void getData(ifstream& inFile) {
	string line;	// 用于读取一行字符串
	long long num;	// 用于处理数字
	while (getline(inFile, line)) {
		line.erase(line.begin());   // 除去第一个'('
		istringstream inString(line);	// 转换成字符串流
		inString >> num;
		cout << setfill('0') << setw(3) << num;	// 第一个区号是三位数且前面的数字可能为0
		for (int i = 0; i < 3; ++i) {	// 处理后面的三种数字
			inString.ignore(2);		// 忽略掉两个分隔符
			inString >> num;
			cout << "|" << num;
		}
		cout << endl;
	}
}

int main() {
	ifstream inFile("info.txt", ios::in);
	if (!inFile)
		return -1;

	getData(inFile);
	//getDataSimple(inFile);
	//getDataComplicated(inFile);

	return 0;
}