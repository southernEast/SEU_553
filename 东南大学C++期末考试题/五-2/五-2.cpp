#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main() {
	int A[3][3] = { 0 };
	ifstream inFile("in.dat", ios::in);
	if (!inFile) {
		cerr << "The file can not be opened.";
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j)
			inFile >> A[j][i];			// 输入的同时进行转置
	}

	ofstream outFile("out.dat", ios::out);
	if (!outFile) {
		cerr << "The file can not be opened.";
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j)
			outFile << setw(2) << A[i][j];
		outFile << endl;
	}

	return 0;
}