# 一、简答题
## 1. 编写语句说明枚举类型是如何定义和使用的。
答：
## 2. 程序改错
### 第一题
```C++
#include <iostream>
using namespace std;
int main()
{
    for (int i = 0; i < 8; i++)
    {
        if (i % 2 == 0)
            cout << i + 1 << endl;
        if (i % 3 == 0)
            continue;
        if (i % 5 == 0)
            break;
        cout << "End of programming\n";
    }
    cout << "End of programming\n";
    return 0;
}
```

### 第二题
```C++
#include <iostream>
using namespace std;

int main()
{
    int c;
    if ((c = cin.get()) != EOF) {
        main();
        cout << c;
    }
    return 0;
}
```

### 第三题
```C++
#include <iostream>
using namespace std;

void fun(int a[], int cur, int s)
{
    {
        if (cur < s)
            fun(a, cur + 1, s);
        cour << a[cur] << ',';
    }
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    fun(a, 0, 10);
    return 0;
}
```

## 3. 函数模板和模板函数的区别。
答：
## 4. 为什么说“继承是面向对象的主要特征之一”？请简要说明。
答：
## 5. 如何声明和使用虚函数？说明它在多态性中的作用和意义。
答：

# 二、编程题

## [Problem 1](1/1.cpp)
> 编写程序，求最小公倍数。
## [Problem 2](2/2.cpp)
> 编写程序，计算一系列整数之和。</br>
> 假定:输入的第一个整数为继续输入整数的个数。（要求每条输入语句仅读取一个整数）

> 样例输入：

```
5,101,213,325,437,549
```

> 样例输出：

```
1625
```

## [Problem 3](3/3.cpp)
> 编写程序，读入几行文本，并打印一个表格，显示每个不同单词在文本中出现的次数。

> 样例输入：

```
Welcome to C++ world ! Happy birthday to you .This is the weather report across the world for tomorrow , talk about it in pairs following the model below.
```
> 样例输出：

```
about: 1
across: 1
below: 1
birthday: 1
c++: 1
following: 1
for: 1
happy: 1
in: 1
is: 1
it: 1
model: 1
pairs: 1
report: 1
talk: 1
the: 3
this: 1
to: 2
tomorrow: 1
weather: 1
welcome: 1
world: 2
you: 1
```

> 样例输入：
```
Life is full of confusing and disordering Particular time,a particular location,Do the arranged thing of ten million time in the brain,
Step by step ,the life is hard to avoid delicacy and stiffness No enthusiasm forever,No unexpected happening of surprising and pleasing So,
only silently ask myself in mind Next happiness,when will come?
```

> 样例输出：
```
a: 1
and: 3
arranged: 1
ask: 1
avoid: 1
brain: 1
by: 1
come: 1
confusing: 1
delicacy: 1
disordering: 1
do: 1
enthusiasm: 1
forever: 1
full: 1
happening: 1
happiness: 1
hard: 1
in: 2
is: 2
life: 2
location: 1
million: 1
mind: 1
myself: 1
next: 1
no: 2
of: 3
only: 1
particular: 2
pleasing: 1
silently: 1
so: 1
step: 2
stiffness: 1
surprising: 1
ten: 1
the: 3
thing: 1
time: 2
to: 1
unexpected: 1
when: 1
will: 1
```

## Problem 4 
## [main函数](4/4.cpp)|[Name.h](4/Name.h)|[Person.h](4/Person.h)
> Person类包含3个数据成员，已知:</br>
> 1. Person 类包含 3 个数据成员（name，nationality 和 sex）和三个成员函数（构造函数，printName 函数和 printNationality 函数）;</br>
> 2. 其中name的数据类型为Name类。Name 类包含三个数据成员（first，middle和last）和两个成员函数（构造函数和printName函数）;</br>
> 3. 定义Person类和Name 类，并编写程序测试这两个类的所有接口。


题目参考自：https://blog.csdn.net/qq_32925781/article/details/79399352