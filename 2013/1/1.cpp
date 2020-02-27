#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

const int MAXN = 20001;				
bool primeFlag[MAXN] = { false };				// 数组较大，置于全局作用域，防止过度占用堆栈内存

void getPrime(vector<int>& prime) {
	for (int i = 2; i < MAXN; ++i) {			// 使用埃氏筛法
		if (!primeFlag[i]) {					// 如果是质数
			prime.push_back(i);
			for (int j = i + i; j < MAXN; j += i) {	// 将该质数所有的倍数筛选出去
				primeFlag[j] = true;
			}
		}
	}
}

int main() {
	vector<int> prime;
	getPrime(prime);

	for (size_t i = 0; i < prime.size(); ++i) {
		cout << setw(6) << prime[i];
		if ((i + 1) % 10 == 0)
			cout << endl;
	}

	return 0;
}