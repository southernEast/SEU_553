#include <iostream>
using namespace std;

// 欧几里得递归求最大公约数
int gcd(int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

// 欧几里得迭代求最大公约数
int gcd2(int a, int b) {
	int temp;
	while (b != 0) {
		temp = a;
		a = b;
		b = temp % b;
	}
	return a;
}

int main() {
	int n1, n2, temp;
	cin >> n1 >> n2;

	temp = gcd(n1, n2);		// 求得最大公约数
	cout << (n1 / temp * n2);	// 先除以最大公约数再乘，避免溢出

	return 0;
}