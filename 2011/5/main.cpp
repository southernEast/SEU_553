#include <iostream>
#include "Array.h"
using namespace std;

int main() {
	Array<int> chess(4, 3);
	cout << chess << endl << endl;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 3; ++j)
			chess(i, j) = j;
	}
	cout << chess;

	return 0;
}