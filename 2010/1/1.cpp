#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

// 使用掩码进行转换
void print(int num, ofstream& out) {
    const int SHIFT = sizeof(num) * 8 - 1;
    const int MASK = (1 << SHIFT);				// 掩码

    for (int i = 0; i < SHIFT + 1; ++i) {
        out << (num & MASK ? 1 : 0);        // 逐个取最高位
        num <<= 1;
        if ((i + 1) % 4 == 0)               // 每4位加一个空格，对齐输出
            out << ' ';
    }
    out << endl;
}

// 使用除法和取余转换
void transformBit(int num, ostream& os) {
    if (num) {
        transformBit(num / 2, os);
        os << num % 2;
    }
}

int main() {
    ofstream outFile("data.txt", ofstream::out);
    if (!outFile)
        return -1;      // 文件打开失败

    srand(time(0));
    int n = rand() % 20, num;
    cout << n << endl;
    for (int i = 0; i < n; ++i) {
        num = rand() % 256;
        print(num, outFile);
        transformBit(num, outFile);
        outFile << "\n" << num << "\n\n";
    }

    return 0;
}