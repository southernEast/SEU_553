#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

// 数组大小可以更改，只需更改数组大小后，掷骰子的次数会随之更改
// 函数功能为：首行与首列为随机掷骰子的点数，中间交叉行列则为两
// 边界线的数的和
void flip1(unsigned val[][2], unsigned row, unsigned col) {
	for (unsigned i = 1; i < col; ++i)			// 初始化首行
		val[0][i] = 1 + rand() % 6;
	for (unsigned j = 1; j < row; ++j)			// 初始化首列
		val[j][0] = 1 + rand() % 6;
	for (unsigned i = 1; i < row; ++i) {		// 计算交叉行列的和
		for (unsigned j = 1; j < col; ++j) {
			val[i][j] = val[0][j] + val[i][0];
		}
	}
}

// 随机掷骰子times次，并将出现的点数的次数记录在数组中
void flip2(unsigned val[7], unsigned times) {
	for (unsigned i = 0; i < times; ++i)
		val[1 + rand() % 6]++;
}

int main() {
	srand(time(0));
	const int row = 2;
	const int col = 2;
	unsigned A[row][col] = { 0 };
	unsigned B[7] = { 0 };
	
	flip1(A, row, col);
	flip2(B, 1000);

	cout << "The array of A:" << endl;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j)
			cout << setw(3) << A[i][j];
		cout << endl;
	}

	cout << sizeof(int) << " " << sizeof(unsigned);
	cout << endl << "The array of B:" << endl;
	for (int i = 1; i < 7; ++i)
		cout << setw(5) << B[i];
	
	return 0;
}