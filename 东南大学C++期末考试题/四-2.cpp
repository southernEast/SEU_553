#include <iostream>
using namespace std;

class A {
	int x[10];
public:
	A() { for (int i = 0; i < 10; i++) x[i] = 0; }
	A(int* p) {
		for (int i = 0; i < 10; i++)
			x[i] = p[i];
	}
	A operator* (A a) {
		A t;
		for (int i = 0; i < 10; i++)
			t.x[i] = x[i] * a.x[i];
		return t;
	}
	A operator= (A a) {
		for (int i = 0; i < 10; i++)
			x[i] = a.x[i];
		return *this;
	}
	void show() { for (int i = 0; i < 10; i++) cout << x[i] << '\t'; }
};

int main() {
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int b[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	A a1(a), a2(b), a3;
	a3 = a1 * a2;
	a3.show();

	return 0;
}