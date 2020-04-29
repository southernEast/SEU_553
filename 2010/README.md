## [Problem 1](1/1.cpp)
> 输入 n 个十进制数转换成二进制写到文件，n 是随机得到的，用随机数进行输入n个十进制数，然后再进行转换。
## [Problem 2](2/2.cpp)
> 写两个模板函数:插入排序法的迭代实现与递归实现
## [Problem 3](3/3.cpp)
> 字符串的解析，文件中有类似的一行行字符串“(010)(15012345678)|123|(430070)”，按以下格式输出:

```
区号|电话号码|城市编号|邮编
```

## Problem 4 
## [main函数](4/4.cpp)|[Polynomial.h](4/Polynomial.h)|[Polynomial.cpp](4/Polynomial.cpp)
> 设计一个多项式类 Polynomial(包括构造函数、复制构造函数、析构函数、赋值函数、 实现两个多项式相加)</br>
> 这里为了简化问题，我们将所有的多项式都统一看成：
```
p = a0 + a1*x + a2*x^2 + a3*x^3 + ……… + an*x^n
```
> 拓展问题：实现多项式的加法、减法和乘法运算。 答案见：[此处](4/extend.cpp)

## Problem 5 
## [main函数](5/5.cpp)|[Brake.h](5/Brake.h)|[Car.h](5/Car.h)|[SteeringWheel.h](5/SteeringWheel.h)|[Vehicle.h](5/Vehicle.h)
> 几个类(Vehicle 类 Car 类 SteeringWheel 类 Brake 类)有着必然的联系，设计类与实现
> Vehicle类中需要有速度的成员及相关操作，Car类、teeringWheel类和Brake 类中需要有部分属性名字。
## Problem 6 
## [main函数](6/6.cpp)|[Shape.h](6/Shape.h)|[ThreeDShape.h](6/ThreeDShape.h)|[TwoDShape.h](6/TwoDShape.h)
> 一个基类 Shape，在基类的基础上继承写一个二维图形类，再继承写一个三维图形类，设计与实现相关函数，并实践多态性。


题目参考自：https://blog.csdn.net/qq_32925781/article/details/79377073