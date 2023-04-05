#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double myExp(double x) {
	const double acc = 10e-10;		// 精确到10^-10
	double ans = 0, temp = 1;
	double n = 0;
	
	while (fabs(temp) > acc) {		// 使用fabs 指数可以为负
		ans += temp;
		temp *= x / (++n);
	}

	return ans;
}

int main() {
	double x;
	cin >> x;
	cout << fixed << setprecision(10) << myExp(x) << endl;

	return 0;
}