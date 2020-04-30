#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	const double acc = 10e-10;	// 精确到小数点后10位，不清楚计算机可表示的最大范围，请指教
	double denomintor = 1, ans = 0, temp = 4;

	while (fabs(temp) > acc) {
		ans += temp;
		denomintor = (denomintor > 0 ? denomintor + 2 :		// 分两种情况处理
			denomintor - 2);
		denomintor *= -1;		// 改变符号
		temp = 4 / denomintor;
	}
	cout << setprecision(10) << ans;

	return 0;
}