#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class SelfString {
	friend ostream& operator<<(ostream&, const SelfString&);
	friend void findCommon(const SelfString&, const SelfString&);
public:
	SelfString(ifstream&);
	SelfString(const SelfString&);
	~SelfString();

private:
	// 设置当前类可以存储的最大字符串长度（类的静态常量是整数类型或枚举类型，可以直接在类定义中
	// 指定常量值，否则应该在类定义之外定义, 而类静态变量只能在类定义外定义）
	static const int MAXSIZE = 1000;
	char* dataStr;
	int length;
};

ostream& operator<<(ostream& os, const SelfString& s) {
	return os << s.dataStr;
}

SelfString::SelfString(ifstream& inFile) {
	// 读入字符串数据
	char inBuf[MAXSIZE] = { 0 };
	length = 0;
	while ((inBuf[length] = inFile.get()) != EOF) {
		if (length < MAXSIZE && inBuf[length] != '\0'
			&& inBuf[length] != '\n')	// 如果非换行符和'\0'才存入缓存中
			++length;
	}
	inBuf[length] = '\0';	// 字符串封口
	dataStr = new char[length + 1]();	// 申请动态数组并初始化
	strcpy(dataStr, inBuf);
}
SelfString::SelfString(const SelfString& s) : length(s.length) {
	dataStr = new char[length + 1]();
	strcpy(dataStr, s.dataStr);
}
SelfString::~SelfString() {
	delete[] dataStr;
}

void findCommon(const SelfString& s1, const SelfString& s2) {
	// 用于存放工作字符串
	char* str1 = new char[s1.length + 1]();
	strcpy(str1, s1.dataStr);
	char* str2 = new char[s2.length + 1]();
	strcpy(str2, s2.dataStr);

	// 对两个字符串按空格分割单词
	char* words1[SelfString::MAXSIZE] = { 0 };
	char* words2[SelfString::MAXSIZE] = { 0 };
	int cnt1 = 0, cnt2 = 0;
	char* ptr;
	ptr = strtok(str1, " ");
	while (ptr) {
		words1[cnt1++] = ptr;
		ptr = strtok(nullptr, " ");
	}
	ptr = strtok(str2, " ");
	while (ptr) {
		words2[cnt2++] = ptr;
		ptr = strtok(nullptr, " ");
	}

	// 穷举法查找
	char* maxStr = nullptr;
	int maxLength = 0;
	for (int i = 0; i < cnt1; ++i) {
		for (int j = 0; j < cnt2; ++j)
			if (strcmp(words1[i], words2[j]) == 0 && maxLength < strlen(words1[i])) {
				maxStr = words1[i];
				maxLength = strlen(words1[i]);
			}
	}

	if (maxStr)		// 如果找到需要的字符串，这里也有可能未找到，未找到则temPtr中为空，不能直接输出，需要判断分支
		cout << maxStr << " " << maxLength;
	else
		cout << "Not Fuound!";

	delete[] str1;	// 删除动态分配的空间
	delete[] str2;
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
	cout << s1 << endl << s2 << endl;
	findCommon(s1, s2);

	return 0;
}