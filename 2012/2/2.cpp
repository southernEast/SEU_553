#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	/*补充一个C语言的读法
	while (n--) {
        int x;
        scanf(",%d", &x); 
        sum += x;
    }
	*/
	int sum = 0, temp;
	for (int i = 0; i < n; ++i) {
		cin.ignore();	// 忽略逗号
		cin >> temp;
		sum += temp;
	}
	cout << sum;

	return 0;
}