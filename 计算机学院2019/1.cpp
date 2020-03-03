#include <iostream>
using namespace std;

bool isRight(int a[][4], int m, int n) {
	int val = a[m][n];

	for (int i = 0; i < 3; ++i)	// 扫描第n列，如果有元素比val小说明val不是列最小
		if (val > a[i][n])
			return false;
	for (int j = 0; j < 4; ++j)	// 扫描第m行，如果有元素比val大说明val不是行最大
		if (val < a[m][j])
			return false;
	return true;
}

int main() {
	int a[3][4];
	srand(3);			// 初始化随机种子，选取其他的随机种子不一定会有鞍点
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 4; ++j) {
			a[i][j] = 1 + rand() % 9;
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	cout << "\nThe points:\n";
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 4; ++j)
			if (isRight(a, i, j))
				cout << "(" << i << ","
				<< j << ") " << a[i][j] << endl;
	}

	return 0;
}