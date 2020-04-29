#include <iostream>
using namespace std;

// 插入排序思想见 https://www.cnblogs.com/southernEast/p/12713540.html


// 迭代插入排序
template<typename T>
void insertSort(T a[], int n) {
    for (int i = 1; i < n; ++i) {
        int j;
        T num = a[i];      // 取当前位置的待插入的数

        // 往有序数列中插入num
        for (j = i; j > 0 && a[j - 1] > num; --j) {
            a[j] = a[j - 1];
        }
        a[j] = num;
    }
}

// 递归插入排序
template<typename T>
void insertSortRecursive(T a[], int i) {
    if (i > 0) {
        insertSortRecursive(a, i - 1);  // 先把当前位置之前的数排列成有序序列

        // 插入排序中的一趟排序
        int j;
        T num = a[i];
        for (j = i; j > 0 && a[j - 1] > num; --j) {
            a[j] = a[j - 1];
        }
        a[j] = num;
    }
}

int main() {
    const int SIZE = 15;
    int a[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        a[i] = rand() % SIZE;
        cout << a[i] << " ";
    }
    cout << endl;

    insertSort(a, SIZE);
    //insertSortRecursive(a, SIZE - 1);

    for (auto elem : a)
        cout << elem << " ";

    return 0;
}