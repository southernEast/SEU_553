#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// 原数出现在平方数的任意位置都算
void find1() {
	string numStr;
	for (int i = 1; i <= 10000; ++i) {
		numStr = to_string(i * i);
		if (numStr.find(to_string(i)) != string::npos)
			cout << i * i << " " << i << endl;
	}
}

// 只有原数出现在平方数末尾的才算
void find2() {
	int dividNum, temp;
	for (int i = 1; i <= 10000; ++i) {
		temp = i;
		dividNum = 1;
		while (temp) {		// 原数有n个数字就取10^n来取余
			dividNum *= 10;
			temp /= 10;
		}
		if (i * i % dividNum == i)
			cout << i * i << " " << i << endl;
	}
}


int main() {
	/*find1();*/
	find2();

	return 0;
}