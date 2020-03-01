#include <iostream>
#include <algorithm>
using namespace std;

// 翻转[first, last)
void myReverse(char* first, char* last) {
	char temp;
	--last;			// 最右端的元素不取
	while (first < last) {
		temp = *first;
		*first = *last;
		*last = temp;
		++first;
		--last;
	}
}

class Str {
public:
	Str(char* p, int n, int k);
	void move();
	void show();
private:
	char* w;
	int m, len;
};

Str::Str(char* p, int n, int k) {
	len = n;
	m = k;
	w = new char[n + 1];
	strcpy(w, p);
}
void Str::move() {
	//reverse(w, w + m);			// 使用库函数reverse的方法，reverse翻转[left, right)之间的元素
	//reverse(w + m, w + len);
	//reverse(w, w + len);
	myReverse(w, w + m);			// 使用简单实现的reverse()函数
	myReverse(w + m, w + len);
	myReverse(w, w + len);
}
void Str::show() {
	for (int i = 0; i < len; ++i)
		cout << w[i];
}

int main() {
	char a[] = "ABCD";
	Str s(a, 4, 4);
	s.show();
	cout << endl;
  	s.move();
	s.show();

	return 0;
}