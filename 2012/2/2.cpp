#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	cin.ignore();		// 忽略逗号

	int sum = 0, temp;
	for (int i = 0; i < n; ++i) {
		cin >> temp;
		cin.ignore();	// 忽略逗号
		sum += temp;
	}
	cout << sum;
	
	return 0;
}