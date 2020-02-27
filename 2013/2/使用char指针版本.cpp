#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 20;

void encrypt(char* str) {
	int len = strlen(str);
	for (int i = 0; i < len; ++i) {
		if (islower(str[i]))
			str[i] = (str[i] - 'a' + 1) % 26 + 'a';
		else
			str[i] = (str[i] - 'A' + 1) % 26 + 'A';
	}
}

void decrypt(char* str) {
	int len = strlen(str);
	for (int i = 0; i < len; ++i) {
		if (islower(str[i]))
			str[i] = (str[i] - 'a' + 26 - 1) % 26 + 'a';
		else
			str[i] = (str[i] - 'A' + 26 - 1) % 26 + 'A';
	}
}

int main() {
	char str[MAXN] = { 0 };
	cin >> str;
	cout << "Before encrpying:" << str << endl;
	encrypt(str);
	cout << "After encrpying: " << str << endl;
	decrypt(str);
	cout << "After decrpying: " << str << endl;

	return 0;
}