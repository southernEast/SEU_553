#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main() {
	ifstream input("Date.txt", ios::in);
	if (!input) {
		cerr << "The file can not be opened." << endl;
		exit(EXIT_FAILURE);
	}			// 文件处理操作

	int day, month, year;
	const char* monthStr[] = {
		"", "January", "February", "March", "April", "May", "June", "July",
		"August", "September", "October", "November", "December"
	};
	while (input >> month) {	// 一直读取直到EOF
		input.ignore();			// 忽略'/'
		input >> day;
		input.ignore();
		input >> year;
		input.ignore();

		cout << monthStr[month] << " " << setw(2)	// 注意这个要填充字符0
			<< setfill('0') << day << "," << year << endl;
	}

	input.close();

	return 0;
}