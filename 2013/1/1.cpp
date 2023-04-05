#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
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

//改进的埃氏筛法: 要找到直到 n 为止的所有素数，仅对不超过 sqrt(n) 的素数进行筛选就足够了。
bool is_prime[MAXN+1];
int get_prime(vector<int>& prime) {
	int p = 0;
	long long sq = sqrt(MAXN);
	for (int i = 0; i <= MAXN; ++i)
		is_prime[i] = 1;
	is_prime[0] = is_prime[1] = 0;
	for (int i = 2; i <= MAXN; ++i) {
		if (is_prime[i]) {
			prime.push_back(i);
			if ((long long)i <= sq)
				for (int j = i * i; j <= MAXN; j += i)
					is_prime[j] = 0;			// 因为从 2 到 i - 1 的倍数之前筛过了，这里直接从 i的倍数开始，提高了运行速度
		}
	}
	return p;									//p是素数个数
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
