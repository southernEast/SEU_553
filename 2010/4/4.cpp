#include <iostream>
#include <vector>
#include "Polynomial.h"
using namespace std;

int main() {
	vector<double> coe1{ 1, -2, 3, -4.4, -3 };
	vector<double> coe2{ -3.6, 1, -6, 5, 3, 2.2, -7.6 };
	Polynomial p1(coe1), p2(coe2);
	cout << "p1:    " << p1 << endl;
	cout << "p2:    " << p2 << endl;
	cout << "p1+p2: " << (p1 + p2) << endl;
	p1.setCoeficient(0, 4);
	cout << "p1:    " << p1;

	return 0;
}