#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int sum = 0, temp;
	for (int i = 0; i < n; ++i) {
		cin.ignore();	// 忽略逗号
		cin >> temp;
		sum += temp;
	}
	cout << sum;

	return 0;
}