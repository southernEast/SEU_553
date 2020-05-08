#include <iostream>
using namespace std;

bool isRight(int** a, int m, int n, int r, int c) {
	int val = a[r][c];
	for (int i = 0; i < m; ++i)			// 如果不是列最大返回false
		if (val < a[i][c])
			return false;
	for (int j = 0; j < n; ++j)			// 如果不是行最小返回false
		if (val > a[r][j])
			return false;
	return true;
}

int main() {
	int m, n;
	cin >> m >> n;
	int** a = new int* [m];
	for (int i = 0; i < m; ++i)
		a[i] = new int[n];			// 创建一个m*n的动态二维数组或使用动态一维数组表示二维

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j)
			cin >> a[i][j];
	}

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (isRight(a, m, n, i, j))	// 如果是鞍点则输出
				cout << "(" << i + 1 << "," << j + 1
				<< ") " << a[i][j] << endl;
		}
	}

	for (int i = 0; i < m; ++i)		// 先清除单个的一维再清除整个 
		delete[] a[i];
	delete[] a;

	return 0;
}