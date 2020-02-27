#include <iostream>
using namespace std;

int ack(int m, int n) {
	if (m == 0)
		return n + 1;
	else if (n == 0)
		return m + 1;
	else
		return ack(m - 1, n - 1);
}

int main() {
	cout << ack(1, 2) << endl;
	cout << ack(9, 3) << endl;
	cout << ack(6, 4) << endl;
	cout << ack(1, 49) << endl;
	cout << ack(34, 41) << endl;
	
	return 0;
}