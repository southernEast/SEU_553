#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	const double acc = 10e-10;				// 精确到小数点后10位，不是很清楚计算机可表示的最大范围
	double ans = 0;
	double denominator = 1, temp = 1;
	double n = 4.0;

	while (fabs(temp) > acc) {
		temp = n / denominator;
		ans += temp;
		denominator += 2;
		n *= -1;
	}
	cout << fixed << setprecision(20) << ans;

	return 0;
}