#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	ifstream input("data.dat", ios::in);
	if (!input) {
		cerr << "The file can not be opened";
		exit(EXIT_FAILURE);
	}		// 打开文件

	string inBuf;		// 输入缓存
	enum Type {
		UPPER, BLANK, PUNCTUATION,	// 大写字母、空格、标点符号
		WORD, NUMBER, OTHERS		// 单词、数字、其他
	};						// 分类进行统计
	int cnt[7] = { 0 };
	bool alphaFlag = false;		// 记录前面是否为字母
	bool numberFlag = false;	// 记录前面是否为数字
	bool needJudge = false;		// 是否需要进行判断完整单词或数字

	while (getline(input, inBuf)) {	// 每次读取一行
		for (size_t i = 0; i < inBuf.size(); ++i) {
			if (isupper((unsigned char)inBuf[i])) {
				cnt[UPPER]++;
				alphaFlag = true;
			}
			else if (inBuf[i] == ' ') {
				cnt[BLANK]++;
				needJudge = true;
			}
			else if (inBuf[i] == ',' || inBuf[i] == '.' || inBuf[i] == '?') {
				cnt[PUNCTUATION]++;
				needJudge = true;
			}
			else if (isdigit(inBuf[i]))
				numberFlag = true;
			else if (isalpha(inBuf[i]))
				alphaFlag = true;
			else {
				cnt[OTHERS]++;
				needJudge = true;
			}

			if (needJudge || i == inBuf.size() - 1) {	// 如果标志位置1或者到达行末则进行判断
				if (alphaFlag)
					cnt[WORD]++;
				if (numberFlag)
					cnt[NUMBER]++;
				alphaFlag = false;
				numberFlag = false;
				needJudge = false;
			}
		}
	}
	cout << "upper: " << cnt[UPPER] << endl
		<< "blank: " << cnt[BLANK] << endl
		<< "punctuation: " << cnt[PUNCTUATION] << endl
		<< "word: " << cnt[WORD] << endl
		<< "number: " << cnt[NUMBER] << endl
		<< "others: " << cnt[OTHERS];

	return 0;
}