#include "Polynomial.h"
using namespace std;

Polynomial::Polynomial(const vector<double>& coe) {
	coeficient = coe;
}
Polynomial::Polynomial(const Polynomial& p) {
	coeficient = p.coeficient;
}
void Polynomial::setCoeficient(size_t pos, double val) {
	if (pos < coeficient.size())			// 如果系数在范围内则进行设置
		coeficient[pos] = val;
	else
		cerr << "The index is out of range.";
}
double Polynomial::getCoeficient(size_t pos) {
	if (pos < coeficient.size())
		return coeficient[pos];
	else
		cerr << "The index is out of range.";
}
Polynomial& Polynomial::operator=(const Polynomial& p) {
	coeficient = p.coeficient;
	return *this;
}
Polynomial Polynomial::operator+(const Polynomial& p) {
	size_t i, j;
	i = j = 0;
	vector<double> temp;		// 暂存计算结果
	while (i < coeficient.size() && j < p.coeficient.size()) {	// 系数逐个相加
		temp.push_back(coeficient[i] + p.coeficient[j]);
		++i;
		++j;
	}
	while (i < coeficient.size()) {		// 第一个式子中有剩余系数
		temp.push_back(coeficient[i]);
		++i;
	}
	while (j < p.coeficient.size()) {	// 第二个式子中有剩余系数
		temp.push_back(p.coeficient[j]);
		++j;
	}
	return Polynomial(temp);
}

ostream& operator<<(ostream& output, const Polynomial& p) {
	output << noshowpos << p.coeficient[0];			// 第一个系数单独输出
	for (size_t i = 1; i < p.coeficient.size(); ++i) {
		if (p.coeficient[i] == 0)		// 如果系数为0则跳过
			continue;
		output << showpos << p.coeficient[i] << "x";	// 显示系数符号
		if (i > 1)						// 大于1才显示指数
			output << "^" << i;
	}
	return output;
}