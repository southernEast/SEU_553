#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

void print(ofstream& out, int num) {
	const int SHIFT = sizeof(num) * 8 - 1;
	const int MASK = (1 << SHIFT);				// 掩码

	//out << left << setw(6) << num;			// 方便调试核对
	for (int i = 0; i < SHIFT + 1; ++i) {
		out << (num & MASK ? 1 : 0);
		num <<= 1;
	}
	out << endl;
}

int main() {
	ofstream output("out.dat", ios::out);
	if (!output) {								// 文件打开是否成功判断
		cerr << "File cannot be opened!";
		exit(EXIT_FAILURE);
	}
	int num;
	srand(0);
	for (int i = 0; i < 10; ++i) {
		num = rand();
		print(output, num);
	}

	return 0;
}