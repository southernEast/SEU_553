#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class SelfString {
	friend void findCommon(const SelfString& s1, const SelfString& s2);
public:
	SelfString(ifstream& input);
	~SelfString();

private:
	// 设置当前类可以存储的最大字符串长度（类的静态常量是整数类型或枚举类型，可以直接在类定义中
	// 指定常量值，否则应该在类定义之外定义, 而类静态变量只能在类定义外定义）
	static const int MAXN = 1000;
	char* dataStr;
	int length;
};

SelfString::SelfString(ifstream& input) {
	// 读入字符串数据
	char inBuf[MAXN] = { 0 }, temp;		// 使用inBuf暂存数据
	length = 0;
	temp = input.get();
	while (length < MAXN - 1 && !input.eof()) {	// 如果还有存储空间且未到达文件尾
		inBuf[length++] = temp;
		if (temp == '\n')				// 遇到'\n'则删除
			--length;
		temp = input.get();
	}
	inBuf[length] = '\0';				// 将字符串尾部封闭，方便后续使用cstring中的函数
	
	dataStr = new char[length + 1];
	strcpy(dataStr, inBuf);
}
SelfString::~SelfString() {
	delete[] dataStr;
}

void findCommon(const SelfString& s1, const SelfString& s2) {
	char* ptrS1[SelfString::MAXN], * ptrS2[SelfString::MAXN];	// 存储分割后的单词
	int cnt1, cnt2;				// 记录分割单词个数
	char* temPtr;
	char workS1[SelfString::MAXN] = { 0 };
	char workS2[SelfString::MAXN] = { 0 };	
	strcpy(workS1, s1.dataStr);	// strtok会改变原始字符串，转存来给strtok函数使用
	strcpy(workS2, s2.dataStr);

	// 将两个字符串的单词分别分割出来
	cnt1 = 0;
	temPtr = strtok(workS1, " ");
	while (temPtr) {
		ptrS1[cnt1++] = temPtr;
		temPtr = strtok(nullptr, " ");
	}
	cnt2 = 0;
	temPtr = strtok(workS2, " ");
	while (temPtr) {
		ptrS2[cnt2++] = temPtr;
		temPtr = strtok(nullptr, " ");
	}

	// 使用穷举法遍历
	size_t maxLen = 0;		// 最长公共字符串长度
	temPtr = nullptr;
	for (int i = 0; i < cnt1; ++i) {
		for (int j = 0; j < cnt2; ++j) {
			if (strcmp(ptrS1[i], ptrS2[j]) == 0) {	// 如果两个字符串相等
				if (maxLen < strlen(ptrS1[i])) {	// 更新最长公共字符串信息
					maxLen = strlen(ptrS1[i]);
					temPtr = ptrS1[i];
				}
			}
		}
	}

	if (temPtr)		// 如果找到需要的字符串，这里也有可能未找到，未找到则temPtr中为空，不能直接输出，需要判断分支
		cout << temPtr << " " << maxLen;
	else	
		cout << "Not Fuound!";
}

int main() {
	// 打开两个字符串文件
	ifstream inS1("s1.dat", ios::in);
	if (!inS1) {
		cerr << "The file can not be opened.";
		exit(EXIT_FAILURE);
	}
	ifstream inS2("s2.dat", ios::in);
	if (!inS2) {
		cerr << "The file can not be opened.";
		exit(EXIT_FAILURE);
	}

	// 字符串处理
	SelfString s1(inS1), s2(inS2);
	findCommon(s1, s2);


	return 0;
}