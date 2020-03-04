#include <iostream>
#include <iomanip>
using namespace std;

/*
    使用牛顿迭代法求解x^3 + 2x^2 + 3x + 4 = 0在1附近的根
*/
double fun(double x1) {
	double x2 = 0;          // 第二次取近似根的值，不为1的任意值都可以
    double acc = 10e-5;     // 精度
	while (fabs(x1 - x2) > acc) {   // 对比两次根的跨度，看是否收敛
		x2 = x1;
		x1 = x1 - (x1 * x1 * x1 + 2 * x1 * x1 + 3 * x1 + 4)
            / (3 * x1 * x1 + 4 * x1 + 3);   // 牛顿迭代法迭代
	}
	return x1;
}

/*
    使用牛顿迭代法求三次根号的解 -> y = x^3 -> x^3 - y = 0 求解x
*/
double cubeRoot(double x)                   //牛顿迭代法  f(x[n]) + f'(x[n])(x - x[n]) = 0
{                                           //          ->f(x[n]) + f'(x[n])(x[n+1] - x[n]) = 0
    double yn = 1, yp = x;
    double acc = 10e-5;
    while (fabs(yp - yn) > acc)
    {
        yn = yp;
        yp = yp - (yp * yp * yp - x) / (3 * yp * yp);
    }
    return yp;
}

int main() {
    cout << fixed << setprecision(10);
	cout << cubeRoot(3) << endl;
    cout << fun(1) << endl;

	return 0;
}