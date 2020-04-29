#include <iostream>
#include <algorithm>
using namespace std;

class Polynomial {
    friend istream& operator>>(istream&, Polynomial&);
    friend ostream& operator<<(ostream&, const Polynomial&);
public:
    Polynomial();   // 默认构造函数
    Polynomial(const Polynomial&);  // 复制构造函数
    Polynomial& operator=(const Polynomial&);   // 赋值运算符
    const Polynomial operator+(const Polynomial&) const;
    const Polynomial operator-(const Polynomial&) const;
    const Polynomial operator*(const Polynomial&) const;
    const Polynomial& operator+=(const Polynomial&);
    const Polynomial& operator-=(const Polynomial&);
    const Polynomial& operator*=(const Polynomial&);
    ~Polynomial() = default;    // 使用默认的析构函数
private:
    static const int MAXSIZE = 100; // 类设计能够支持运算的最大指数
    int coefficients[MAXSIZE];  // 存放系数
    int maxExponent;    // 当前对象的最大指数
};
istream& operator>>(istream& is, Polynomial& rhs) {
    is >> rhs.maxExponent;  // 读入最大指数
    for (int i = 0; i <= rhs.maxExponent; ++i)  // 读入系数
        is >> rhs.coefficients[i];
    return is;
}
ostream& operator<<(ostream& os, const Polynomial& rhs) {
    os << rhs.coefficients[0];  // 输出常数项系数
    for (int i = 1; i <= rhs.maxExponent; ++i) {
        if (rhs.coefficients[i]) {  // 如果系数不为0才输出
            os << (rhs.coefficients[i] > 0 ? " +" : " -");  // 符号位
            if (abs(rhs.coefficients[i]) == 1)  // 系数为1输出系数数字
                os << " ";
            else
                os << " " << abs(rhs.coefficients[i]);
            os << "x";
            if (i > 1)  // 指数大于1才输出指数
                os << "^" << i;
        }
    }
    return os;
}
Polynomial::Polynomial() : maxExponent(0), coefficients{ 0 } {}
Polynomial::Polynomial(const Polynomial& p) : maxExponent(p.maxExponent), coefficients{ 0 } {
    for (int i = 0; i <= maxExponent; ++i)  // 逐个复制系数值
        coefficients[i] = p.coefficients[i];
}
Polynomial& Polynomial::operator=(const Polynomial& rhs) {
    maxExponent = rhs.maxExponent;
    fill(begin(coefficients), end(coefficients), 0);    // 清零
    for (int i = 0; i <= maxExponent; ++i)
        coefficients[i] = rhs.coefficients[i];
    return *this;
}
const Polynomial Polynomial::operator+(const Polynomial& rhs) const {
    Polynomial result;
    result.maxExponent = (maxExponent > rhs.maxExponent ?
        maxExponent : rhs.maxExponent); // 取较大的指数
    int noZeroPos = 0;  // 标记最高的系数不为0的位置
    for (int i = 0; i <= result.maxExponent; ++i) {
        result.coefficients[i] = coefficients[i] + rhs.coefficients[i]; // 逐位相加
        if (result.coefficients[i])
            noZeroPos = i;
    }
    result.maxExponent = noZeroPos; // 更新最大指数位置
    return result;
}
const Polynomial Polynomial::operator-(const Polynomial& rhs) const {
    Polynomial result;
    result.maxExponent = (maxExponent > rhs.maxExponent ?
        maxExponent : rhs.maxExponent);
    int noZeroPos = 0;
    for (int i = 0; i <= result.maxExponent; ++i) {
        result.coefficients[i] = coefficients[i] - rhs.coefficients[i]; // 逐位相减
        if (result.coefficients[i])
            noZeroPos = i;
    }
    result.maxExponent = noZeroPos;
    return result;
}
const Polynomial Polynomial::operator*(const Polynomial& rhs) const {
    Polynomial result;
    for (int i = 0; i <= maxExponent; ++i) {
        for (int j = 0; j <= rhs.maxExponent; ++j) {
            // 多项式相乘，指数相加，系数相乘
            result.coefficients[i + j] += coefficients[i] * rhs.coefficients[j];
            if (result.coefficients[i + j] && result.maxExponent < i + j)
                result.maxExponent = i + j;
        }
    }
    return result;
}
const Polynomial& Polynomial::operator+=(const Polynomial& rhs) {
    *this = *this + rhs;
    return *this;
}
const Polynomial& Polynomial::operator-=(const Polynomial& rhs) {
    *this = *this - rhs;
    return *this;
}
const Polynomial& Polynomial::operator*=(const Polynomial& rhs) {
    *this = *this * rhs;
    return *this;
}

/*****
input:
5
6 -7 0 0 0 3
5
2 7 2 0 0 -4
******/
int main() {
    Polynomial p1, p2;
    cin >> p1 >> p2;    // 输入两个多项式

    cout << "Polynomial 1:\n" << p1 << endl;
    cout << "Polynomial 2:\n" << p2 << endl;
    cout << "p1 + p2:  " << (p1 + p2) << endl;
    cout << "p1 - p2:  " << (p1 - p2) << endl;
    cout << "p1 * p2:  " << (p1 * p2) << endl;

    return 0;
}