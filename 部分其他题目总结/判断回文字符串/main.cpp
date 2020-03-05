#include <iostream>
#include <cstring>
using namespace std;

bool judege(char str[]) {
	int len = strlen(str);
	int left = 0, right = len - 1;

	while (left < right) {
		if (str[left] == ' ') {		// 遇到空格则跳过
			++left;
			continue;
		}
		if (str[right] == ' ') {
			--right;
			continue;
		}
		if (str[left] != str[right])	// 如果左右字符出现不等的情况则返回false
			return false;
		++left;
		--right;
	}

	return true;
}

int main() {
	const int MAXN = 100;
	char str[MAXN] = { 0 };
	cin.getline(str, MAXN);

	cout << boolalpha << judege(str);		

	return 0;
}