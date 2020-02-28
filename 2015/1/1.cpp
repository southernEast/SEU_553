#include <iostream>
#include <iomanip>
using namespace std;

double myExp(double x) {
	const double acc = 10e-7;
	double tem1, tem2, ans, n;
	tem2 = 1;
	n = tem1 = ans = 0;

	do {
		ans += tem2;
		tem1 = tem2;
		tem2 *= x / (++n);
	} while (tem2 > acc);		// 按题源应该是while(fabs(tem1 - tem2) <= acc)，但是这样计算精确度很低，偏差大
	return ans;
}

int main() {
	cout << fixed << setprecision(10) << myExp(10) << endl;

	return 0;
}