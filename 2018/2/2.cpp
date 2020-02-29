#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;

int main() {
	srand(time(0));
	ofstream outFile("data.txt", ios::out);
	if (!outFile) {
		cerr << "The file can not be opened.";
		exit(EXIT_FAILURE);
	}

	// 取[10, 100000]之间的数，总共有100000 - 10 + 1 = 99991个数
	for (int i = 0; i < 10; ++i) {
		outFile << to_string(10 + rand() % 99991) << endl;
	}

	return 0;
}