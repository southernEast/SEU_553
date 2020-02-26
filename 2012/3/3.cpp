#include <iostream>
#include <string>
#include <sstream>
#include <map>
using namespace std;

bool isPunctuation(char ch) {		// 判断是否是需要转换的符号
	return (ch == ',' || ch == '.' || ch == '!' 
		|| ch == '\n' || ch == '?' );
}

int main() {
	string inStr, temp;
	map<string, int> strMap;		// 统计结果

	while (getline(cin, inStr)) {	// 每次读取一行
		// 遍历读入的一行字符，修改其中符号和大小写
		for (string::iterator it = inStr.begin(); it != inStr.end(); ++it) {
			if (isPunctuation(*it))
				*it = ' ';
			*it = (isupper(*it) ? tolower(*it) : *it);
		}
	
		istringstream strStream(inStr);	// 将读入的字符串转换成字符串流，再逐个提取其中的单词
		while(strStream >> temp)
			strMap[temp]++;
	}

	for (pair<string, int> items : strMap) {
		cout << items.first << ":  " << items.second << endl;
	}
	
	return 0;
}