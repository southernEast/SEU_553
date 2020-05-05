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
	} while (tem2 > acc);		
	/*
	按题源应该是while(fabs(tem1 - tem2) <= acc)，但是这样计算精确度很低，偏差大
	精度低的原因：试考虑取x=3，当n=3时，x^n/x! 与 x^(n-1)/(n-1)! 的值相同
	*/
	return ans;
}

int main() {
	cout << fixed << setprecision(10) << myExp(10) << endl;

	return 0;
}