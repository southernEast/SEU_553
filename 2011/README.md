# 一、简答题（50分）
## 1. 简述你对C++中的数据类型和抽象数据类型（ADTs）的理解。
答：



### 1. 数据类型（Data Types）

#### 1.1 基本概念
数据类型定义了数据的性质、存储方式和可执行的操作。C++中的数据类型可以分为两大类：

#### 1.2 内置数据类型（Built-in Types）
```cpp
// 1. 基本类型
int integerVar = 42;                    // 整型
float floatVar = 3.14f;                 // 单精度浮点型
double doubleVar = 3.14159;             // 双精度浮点型
char charVar = 'A';                     // 字符型
bool boolVar = true;                    // 布尔型

// 2. 修饰类型
unsigned int positiveOnly = 100;        // 无符号整型
long long bigInt = 1234567890LL;        // 长整型
const int constantVar = 100;            // 常量

// 3. 空类型和指针类型
void* genericPointer = nullptr;         // 空指针
int* intPointer = &integerVar;          // 整型指针
```

#### 1.3 派生数据类型
```cpp
// 1. 数组
int numbers[5] = {1, 2, 3, 4, 5};

// 2. 指针
int* ptr = numbers;

// 3. 引用
int& ref = integerVar;

// 4. 函数类型
int add(int a, int b) { return a + b; }
```

### 2. 抽象数据类型（Abstract Data Types, ADT）

#### 2.1 基本概念
抽象数据类型是一种数学模型，它定义了数据对象、数据关系以及一组操作，但隐藏了具体的实现细节。

**核心特征：**
- **数据抽象**：只关心"做什么"，不关心"怎么做"。
- **封装**：将数据和操作封装在一起。
- **信息隐藏**：隐藏内部实现细节。

#### 2.2 C++中的ADT实现
```cpp
// 栈的ADT示例
class Stack {
private:
    // 实现细节被隐藏
    static const int MAX_SIZE = 100;
    int data[MAX_SIZE];
    int topIndex;

public:
    // 抽象接口 - 只声明操作，不暴露实现
    Stack() : topIndex(-1) {}
    
    void push(int value);    // 入栈操作
    int pop();              // 出栈操作
    int top() const;        // 查看栈顶
    bool isEmpty() const;   // 判断空栈
    bool isFull() const;    // 判断满栈
};

// 实现细节在类外定义
void Stack::push(int value) {
    if (!isFull()) {
        data[++topIndex] = value;
    }
}

int Stack::pop() {
    if (!isEmpty()) {
        return data[topIndex--];
    }
    throw std::runtime_error("Stack underflow");
}
```

### 3. 数据类型 vs 抽象数据类型

#### 3.1 对比分析

| 特性 | 数据类型 | 抽象数据类型 |
|------|----------|--------------|
| **关注点** | 数据的存储表示 | 数据的逻辑行为 |
| **实现** | 编译器提供 | 程序员定义 |
| **操作** | 基本运算(+, -, *, /) | 高层次操作 |
| **细节** | 暴露存储细节 | 隐藏实现细节 |
| **例子** | int, float, char | Stack, Queue, List |

#### 3.2 实际示例对比
```cpp
// 使用基本数据类型实现栈（暴露细节）
int stackArray[100];
int top = -1;

void primitivePush(int value) {
    stackArray[++top] = value;  // 直接操作数组
}

int primitivePop() {
    return stackArray[top--];   // 直接访问内部结构
}

// 使用ADT实现栈（隐藏细节）
Stack advancedStack;
advancedStack.push(10);         // 不关心内部如何实现
int value = advancedStack.pop(); // 只关心操作结果
```

### 4. C++中ADT的实现机制

#### 4.1 类（Class）作为ADT的主要载体
```cpp
class Vector {
private:
    double x, y, z;  // 数据隐藏

public:
    // 构造函数
    Vector(double x = 0, double y = 0, double z = 0) 
        : x(x), y(y), z(z) {}
    
    // 抽象操作接口
    Vector operator+(const Vector& other) const;
    double dot(const Vector& other) const;
    double magnitude() const;
    Vector normalize() const;
    
    // 访问器（保持封装性）
    double getX() const { return x; }
    double getY() const { return y; }
    double getZ() const { return z; }
    
    // 修改器（可控的数据访问）
    void setX(double newX) { x = newX; }
};

// 操作实现
Vector Vector::operator+(const Vector& other) const {
    return Vector(x + other.x, y + other.y, z + other.z);
}

double Vector::magnitude() const {
    return std::sqrt(x*x + y*y + z*z);
}
```

#### 4.2 模板实现通用ADT
```cpp
template<typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };
    
    Node* head;
    
public:
    LinkedList() : head(nullptr) {}
    
    // ADT操作接口
    void insertFront(const T& value);
    void insertBack(const T& value);
    bool remove(const T& value);
    bool contains(const T& value) const;
    void clear();
    
    ~LinkedList() { clear(); }
};

// 可以用于任何类型
LinkedList<int> intList;
LinkedList<std::string> stringList;
LinkedList<Vector> vectorList;
```

### 5. ADT的设计原则

#### 5.1 完整性原则
```cpp
class Rational {
private:
    int numerator;
    int denominator;
    
    void normalize();  // 内部实现细节

public:
    Rational(int num = 0, int den = 1);
    
    // 完整的算术操作
    Rational operator+(const Rational& other) const;
    Rational operator-(const Rational& other) const;
    Rational operator*(const Rational& other) const;
    Rational operator/(const Rational& other) const;
    
    // 完整的比较操作
    bool operator==(const Rational& other) const;
    bool operator!=(const Rational& other) const;
    bool operator<(const Rational& other) const;
    
    // 完整的输入输出支持
    friend std::ostream& operator<<(std::ostream& os, const Rational& r);
    friend std::istream& operator>>(std::istream& is, Rational& r);
};
```

#### 5.2 一致性原则
```cpp
class Date {
private:
    int year, month, day;
    bool isValid() const;

public:
    Date(int y, int m, int d);
    
    // 一致的操作命名
    Date addDays(int days) const;
    Date addMonths(int months) const;
    Date addYears(int years) const;
    
    int daysBetween(const Date& other) const;
    bool isLeapYear() const;
    
    // 一致的错误处理
    static bool isValidDate(int y, int m, int d);
};
```

### 6. 实际应用中的ADT

#### 6.1 STL容器作为ADT
```cpp
#include <vector>
#include <queue>
#include <map>

void stl_adt_example() {
    // vector - 动态数组ADT
    std::vector<int> vec = {1, 2, 3};
    vec.push_back(4);  // 不关心内部如何重新分配内存
    
    // queue - 队列ADT  
    std::queue<std::string> messages;
    messages.push("Hello");
    std::string msg = messages.front();  // 不关心内部存储结构
    
    // map - 映射ADT
    std::map<std::string, int> wordCount;
    wordCount["apple"] = 5;  // 不关心内部红黑树实现
}
```

#### 6.2 自定义复杂ADT
```cpp
class BankAccount {
private:
    std::string accountNumber;
    double balance;
    std::vector<Transaction> transactionHistory;
    
    bool validateAmount(double amount) const;
    void logTransaction(const std::string& type, double amount);

public:
    BankAccount(const std::string& accNum, double initialBalance = 0);
    
    // 业务操作接口
    bool deposit(double amount);
    bool withdraw(double amount);
    bool transfer(BankAccount& toAccount, double amount);
    double getBalance() const;
    std::vector<Transaction> getStatement() const;
    
    // 不暴露的内部状态操作方法
    // 比如：没有直接修改balance的方法
};
```

### 7. 总结

#### 数据类型：
- **本质**：数据的存储表示和基本操作
- **关注**：内存布局、字节大小、位模式
- **例子**：int, float, 数组, 指针
- **层次**：较低层次，接近机器

#### 抽象数据类型：
- **本质**：数据的逻辑行为和操作契约
- **关注**：接口规范、操作语义、不变量
- **例子**：Stack, Queue, Matrix, Complex
- **层次**：较高层次，接近问题域

#### 关系：
- ADT建立在数据类型之上
- 数据类型提供ADT的实现基础
- ADT通过封装数据类型来提供更高层次的抽象
- 好的ADT设计可以隐藏数据类型的复杂性，提供简洁易用的接口

在C++中，类（class）是实现ADT的主要工具，通过访问控制（public/private/protected）来实现信息隐藏，通过成员函数来定义操作接口，从而将具体的数据类型提升为抽象的、易于理解和使用的数据类型。


## 2. 请举例并写出相关代码，阐述C++在什么情况下必须进行运算符重载。
答：



在C++中，运算符重载并非总是必需的，但在某些特定情况下，它是实现正确语义、提高代码可用性或与现有框架集成的必要手段。

### 1. 必须进行运算符重载的情况

#### 1.1 与标准库算法和容器集成

当自定义类型需要与STL算法和容器协同工作时，必须重载相关运算符。

```cpp
#include <algorithm>
#include <vector>
#include <set>

class Person {
private:
    std::string name;
    int age;
public:
    Person(const std::string& n, int a) : name(n), age(a) {}
    
    // 必须重载 < 运算符才能用于std::set或std::map的键
    bool operator<(const Person& other) const {
        if (name == other.name) {
            return age < other.age;
        }
        return name < other.name;
    }
    
    // 必须重载 == 运算符才能用于std::find等算法
    bool operator==(const Person& other) const {
        return name == other.name && age == other.age;
    }
};

void example_stl_integration() {
    std::vector<Person> people = {
        Person("Alice", 25),
        Person("Bob", 30),
        Person("Charlie", 28)
    };
    
    // 需要 operator==
    auto it = std::find(people.begin(), people.end(), Person("Bob", 30));
    
    std::set<Person> uniquePeople;  // 需要 operator<
    uniquePeople.insert(Person("Alice", 25));
    uniquePeople.insert(Person("Bob", 30));
}
```

#### 1.2 实现值语义和资源管理

对于管理资源的类（如智能指针、字符串、容器），必须重载赋值运算符和拷贝构造函数。

```cpp
#include <iostream>

class String {
private:
    char* data;
    size_t length;
    
    void copyFrom(const String& other) {
        length = other.length;
        data = new char[length + 1];
        std::copy(other.data, other.data + length + 1, data);
    }
    
    void cleanup() {
        delete[] data;
        data = nullptr;
        length = 0;
    }

public:
    String(const char* str = "") {
        length = std::strlen(str);
        data = new char[length + 1];
        std::copy(str, str + length + 1, data);
    }
    
    // 必须重载拷贝构造函数（Rule of Three）
    String(const String& other) {
        copyFrom(other);
    }
    
    // 必须重载拷贝赋值运算符（Rule of Three）
    String& operator=(const String& other) {
        if (this != &other) {
            cleanup();
            copyFrom(other);
        }
        return *this;
    }
    
    // 必须重载移动构造函数（Rule of Five - C++11）
    String(String&& other) noexcept 
        : data(other.data), length(other.length) {
        other.data = nullptr;
        other.length = 0;
    }
    
    // 必须重载移动赋值运算符（Rule of Five - C++11）
    String& operator=(String&& other) noexcept {
        if (this != &other) {
            cleanup();
            data = other.data;
            length = other.length;
            other.data = nullptr;
            other.length = 0;
        }
        return *this;
    }
    
    // 必须重载析构函数（Rule of Three/Five）
    ~String() {
        cleanup();
    }
    
    // 必须重载下标运算符以支持数组式访问
    char& operator[](size_t index) {
        if (index >= length) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }
    
    const char& operator[](size_t index) const {
        if (index >= length) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }
    
    friend std::ostream& operator<<(std::ostream& os, const String& str);
};

std::ostream& operator<<(std::ostream& os, const String& str) {
    return os << str.data;
}
```

#### 1.3 实现数学概念和代数结构

对于数学对象（向量、矩阵、复数等），必须重载算术运算符以保持数学直觉。

```cpp
class Vector3D {
private:
    double x, y, z;
public:
    Vector3D(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}
    
    // 必须重载算术运算符以支持向量运算
    Vector3D operator+(const Vector3D& other) const {
        return Vector3D(x + other.x, y + other.y, z + other.z);
    }
    
    Vector3D operator-(const Vector3D& other) const {
        return Vector3D(x - other.x, y - other.y, z - other.z);
    }
    
    // 必须重载标量乘法
    Vector3D operator*(double scalar) const {
        return Vector3D(x * scalar, y * scalar, z * scalar);
    }
    
    friend Vector3D operator*(double scalar, const Vector3D& vec);
    
    // 必须重载复合赋值运算符
    Vector3D& operator+=(const Vector3D& other) {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }
    
    // 必须重载相等性比较
    bool operator==(const Vector3D& other) const {
        return x == other.x && y == other.y && z == other.z;
    }
    
    bool operator!=(const Vector3D& other) const {
        return !(*this == other);
    }
    
    // 必须重载点积（可选作为运算符或成员函数）
    double dot(const Vector3D& other) const {
        return x * other.x + y * other.y + z * other.z;
    }
};

Vector3D operator*(double scalar, const Vector3D& vec) {
    return vec * scalar;  // 重用成员运算符
}
```

#### 1.4 实现智能指针和资源句柄

对于智能指针类，必须重载解引用和成员访问运算符。

```cpp
template<typename T>
class UniquePtr {
private:
    T* ptr;
    
public:
    explicit UniquePtr(T* p = nullptr) : ptr(p) {}
    
    // 禁止拷贝
    UniquePtr(const UniquePtr&) = delete;
    UniquePtr& operator=(const UniquePtr&) = delete;
    
    // 必须重载移动语义
    UniquePtr(UniquePtr&& other) noexcept : ptr(other.ptr) {
        other.ptr = nullptr;
    }
    
    UniquePtr& operator=(UniquePtr&& other) noexcept {
        if (this != &other) {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }
    
    // 必须重载解引用运算符
    T& operator*() const {
        if (!ptr) {
            throw std::runtime_error("Dereferencing null pointer");
        }
        return *ptr;
    }
    
    // 必须重载箭头运算符
    T* operator->() const {
        if (!ptr) {
            throw std::runtime_error("Accessing through null pointer");
        }
        return ptr;
    }
    
    // 必须重载布尔转换以支持条件检查
    explicit operator bool() const {
        return ptr != nullptr;
    }
    
    ~UniquePtr() {
        delete ptr;
    }
};

// 使用示例
class MyClass {
public:
    void doSomething() { std::cout << "Doing something\n"; }
};

void smart_pointer_example() {
    UniquePtr<MyClass> ptr(new MyClass());
    
    // 需要 operator* 和 operator->
    (*ptr).doSomething();  // 解引用
    ptr->doSomething();    // 箭头运算符
    
    // 需要 operator bool
    if (ptr) {
        std::cout << "Pointer is valid\n";
    }
}
```

#### 1.5 实现迭代器概念

自定义迭代器必须重载迭代器相关的运算符。

```cpp
template<typename T>
class VectorIterator {
private:
    T* current;
    
public:
    explicit VectorIterator(T* ptr) : current(ptr) {}
    
    // 必须重载解引用运算符
    T& operator*() const {
        return *current;
    }
    
    T* operator->() const {
        return current;
    }
    
    // 必须重载前缀递增
    VectorIterator& operator++() {
        ++current;
        return *this;
    }
    
    // 必须重载后缀递增
    VectorIterator operator++(int) {
        VectorIterator temp = *this;
        ++current;
        return temp;
    }
    
    // 必须重载相等性比较
    bool operator==(const VectorIterator& other) const {
        return current == other.current;
    }
    
    bool operator!=(const VectorIterator& other) const {
        return !(*this == other);
    }
    
    // 必须重载关系运算符（用于随机访问迭代器）
    bool operator<(const VectorIterator& other) const {
        return current < other.current;
    }
    
    // 必须重载算术运算符（用于随机访问迭代器）
    VectorIterator operator+(int n) const {
        return VectorIterator(current + n);
    }
    
    std::ptrdiff_t operator-(const VectorIterator& other) const {
        return current - other.current;
    }
};
```

#### 1.6 实现函数对象

需要重载函数调用运算符来创建可调用对象。

```cpp
class Multiplier {
private:
    int factor;
public:
    explicit Multiplier(int f) : factor(f) {}
    
    // 必须重载函数调用运算符
    int operator()(int value) const {
        return value * factor;
    }
    
    double operator()(double value) const {
        return value * factor;
    }
};

void function_object_example() {
    Multiplier times2(2);
    Multiplier times3(3);
    
    // 需要 operator()
    std::cout << times2(5) << std::endl;   // 输出: 10
    std::cout << times3(2.5) << std::endl; // 输出: 7.5
    
    // 与STL算法一起使用
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::transform(numbers.begin(), numbers.end(), 
                   numbers.begin(), times3);
    // numbers 变为: {3, 6, 9, 12, 15}
}
```

#### 1.7 实现类型转换语义

需要重载类型转换运算符以实现自定义转换。

```cpp
class Rational {
private:
    int numerator;
    int denominator;
    
    void normalize() {
        int gcd = std::gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }
    
public:
    Rational(int num = 0, int den = 1) 
        : numerator(num), denominator(den) {
        normalize();
    }
    
    // 必须重载到double的类型转换
    explicit operator double() const {
        return static_cast<double>(numerator) / denominator;
    }
    
    // 必须重载到bool的类型转换（用于条件检查）
    explicit operator bool() const {
        return numerator != 0;
    }
    
    // 必须重载算术运算符
    Rational operator+(const Rational& other) const {
        return Rational(
            numerator * other.denominator + other.numerator * denominator,
            denominator * other.denominator
        );
    }
};

void conversion_example() {
    Rational r(3, 4);
    
    // 需要 operator double
    double decimal = static_cast<double>(r);  // 0.75
    
    // 需要 operator bool
    if (r) {
        std::cout << "Rational is non-zero\n";
    }
    
    Rational zero(0, 1);
    if (!zero) {
        std::cout << "Rational is zero\n";
    }
}
```

### 2. 总结：必须进行运算符重载的情况

1. **与STL集成**：需要与标准算法和容器配合使用时
2. **资源管理**：实现RAII和值语义时（Rule of Three/Five）
3. **数学对象**：实现代数结构保持数学直觉时
4. **智能指针**：模拟指针行为时
5. **迭代器**：实现迭代器概念时
6. **函数对象**：创建可调用对象时
7. **类型转换**：实现自定义类型转换语义时

在所有这些情况下，运算符重载不是可选的，而是实现正确语义和预期行为的必要条件。正确的运算符重载可以使代码更直观、更安全、更易于使用。


## 3. 为什么说“继承是C++面向对象的一个主要特征之一”，请简要说明。
答：



继承确实是C++面向对象编程的三大核心特征之一（另外两个是封装和多态）。下面从多个角度详细阐述这一观点：

### 1. 继承是面向对象思想的基石

#### 1.1 现实世界的建模能力
继承反映了现实世界中的"是一种"（is-a）关系，这是面向对象分析与设计的核心。

```cpp
// 现实世界中的层次关系建模
class Vehicle {
protected:
    double speed;
    int capacity;
public:
    virtual void move() = 0;
    virtual ~Vehicle() = default;
};

class Car : public Vehicle {  // Car "is-a" Vehicle
private:
    int doors;
public:
    void move() override {
        std::cout << "Driving on roads" << std::endl;
    }
};

class Boat : public Vehicle {  // Boat "is-a" Vehicle
private:
    double draft;  // 吃水深度
public:
    void move() override {
        std::cout << "Sailing on water" << std::endl;
    }
};

class AmphibiousVehicle : public Car, public Boat {  // 多重继承
public:
    void move() override {
        std::cout << "Can travel on land and water" << std::endl;
    }
};
```

### 2. 代码重用的核心机制

#### 2.1 避免重复代码
继承使得公共功能可以在基类中实现，派生类直接重用。

```cpp
class Shape {
protected:
    std::string name;
    std::string color;
public:
    Shape(const std::string& n, const std::string& c) 
        : name(n), color(c) {}
    
    // 公共功能在基类实现
    virtual double area() const = 0;
    
    void displayInfo() const {  // 所有形状共享的功能
        std::cout << name << " (Color: " << color 
                  << ", Area: " << area() << ")" << std::endl;
    }
    
    virtual ~Shape() = default;
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r, const std::string& c = "red") 
        : Shape("Circle", c), radius(r) {}
    
    double area() const override {
        return 3.14159 * radius * radius;
    }
    // 自动获得displayInfo()功能，无需重复实现
};

class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h, const std::string& c = "blue") 
        : Shape("Rectangle", c), width(w), height(h) {}
    
    double area() const override {
        return width * height;
    }
    // 同样自动获得displayInfo()功能
};
```

### 3. 多态的基础

#### 3.1 实现运行时多态
没有继承，就无法实现真正的多态行为。

```cpp
class Employee {
protected:
    std::string name;
    double baseSalary;
public:
    Employee(const std::string& n, double salary) 
        : name(n), baseSalary(salary) {}
    
    virtual double calculatePay() const {
        return baseSalary;
    }
    
    virtual void work() const {
        std::cout << name << " is working" << std::endl;
    }
    
    virtual ~Employee() = default;
};

class Manager : public Employee {
private:
    double bonus;
public:
    Manager(const std::string& n, double salary, double b) 
        : Employee(n, salary), bonus(b) {}
    
    double calculatePay() const override {
        return baseSalary + bonus;
    }
    
    void work() const override {
        std::cout << name << " is managing the team" << std::endl;
    }
};

class Developer : public Employee {
private:
    int overtimeHours;
    double overtimeRate;
public:
    Developer(const std::string& n, double salary, int ot, double rate) 
        : Employee(n, salary), overtimeHours(ot), overtimeRate(rate) {}
    
    double calculatePay() const override {
        return baseSalary + (overtimeHours * overtimeRate);
    }
    
    void work() const override {
        std::cout << name << " is writing code" << std::endl;
    }
};

// 多态的使用
void processEmployees(const std::vector<Employee*>& employees) {
    for (Employee* emp : employees) {
        emp->work();  // 动态绑定到具体的派生类方法
        double pay = emp->calculatePay();
        std::cout << "Pay: $" << pay << std::endl;
    }
}
```

### 4. 软件设计的架构支撑

#### 4.1 构建层次化架构
继承支持从通用到特殊的层次化设计。

```cpp
// 抽象接口层
class ILoggable {
public:
    virtual void log(const std::string& message) = 0;
    virtual ~ILoggable() = default;
};

class ISerializable {
public:
    virtual std::string serialize() const = 0;
    virtual void deserialize(const std::string& data) = 0;
    virtual ~ISerializable() = default;
};

// 基础实现层
class BaseEntity : public ILoggable, public ISerializable {
protected:
    int id;
    std::string createdAt;
public:
    BaseEntity(int id) : id(id) {
        // 设置创建时间...
    }
    
    void log(const std::string& message) override {
        std::cout << "[Entity " << id << "] " << message << std::endl;
    }
    
    virtual ~BaseEntity() = default;
};

// 具体业务层
class User : public BaseEntity {
private:
    std::string username;
    std::string email;
public:
    User(int id, const std::string& user, const std::string& mail) 
        : BaseEntity(id), username(user), email(mail) {}
    
    std::string serialize() const override {
        return "User:" + std::to_string(id) + ":" + username + ":" + email;
    }
    
    void deserialize(const std::string& data) override {
        // 解析逻辑...
    }
};

class Product : public BaseEntity {
private:
    std::string name;
    double price;
public:
    Product(int id, const std::string& n, double p) 
        : BaseEntity(id), name(n), price(p) {}
    
    std::string serialize() const override {
        return "Product:" + std::to_string(id) + ":" + name + ":" + std::to_string(price);
    }
    
    void deserialize(const std::string& data) override {
        // 解析逻辑...
    }
};
```

### 5. 设计模式的实现基础

#### 5.1 模板方法模式
```cpp
class DataProcessor {
protected:
    virtual void loadData() = 0;        // 由子类实现
    virtual void processData() = 0;     // 由子类实现
    virtual void saveResults() = 0;     // 由子类实现
    
    // 公共算法骨架
    void commonPreprocessing() {
        std::cout << "Performing common preprocessing..." << std::endl;
    }
    
    void commonPostprocessing() {
        std::cout << "Performing common postprocessing..." << std::endl;
    }
    
public:
    // 模板方法 - 定义算法骨架
    void process() {
        commonPreprocessing();
        loadData();
        processData();
        saveResults();
        commonPostprocessing();
    }
    
    virtual ~DataProcessor() = default;
};

class CSVProcessor : public DataProcessor {
protected:
    void loadData() override {
        std::cout << "Loading CSV data..." << std::endl;
    }
    
    void processData() override {
        std::cout << "Processing CSV data..." << std::endl;
    }
    
    void saveResults() override {
        std::cout << "Saving CSV results..." << std::endl;
    }
};

class XMLProcessor : public DataProcessor {
protected:
    void loadData() override {
        std::cout << "Loading XML data..." << std::endl;
    }
    
    void processData() override {
        std::cout << "Processing XML data..." << std::endl;
    }
    
    void saveResults() override {
        std::cout << "Saving XML results..." << std::endl;
    }
};
```

### 6. 类型系统的扩展

#### 6.1 接口继承与实现继承
```cpp
// 接口继承（纯抽象类）
class Drawable {
public:
    virtual void draw() const = 0;
    virtual ~Drawable() = default;
};

class Clickable {
public:
    virtual void onClick() = 0;
    virtual bool contains(int x, int y) const = 0;
    virtual ~Clickable() = default;
};

// 实现继承（提供部分实现）
class Widget {
protected:
    int x, y, width, height;
public:
    Widget(int x, int y, int w, int h) 
        : x(x), y(y), width(w), height(h) {}
    
    virtual void update() {
        // 默认更新逻辑
    }
    
    virtual ~Widget() = default;
};

// 多重继承组合功能
class Button : public Widget, public Drawable, public Clickable {
public:
    Button(int x, int y, int w, int h) : Widget(x, y, w, h) {}
    
    void draw() const override {
        std::cout << "Drawing button at (" << x << "," << y << ")" << std::endl;
    }
    
    void onClick() override {
        std::cout << "Button clicked!" << std::endl;
    }
    
    bool contains(int px, int py) const override {
        return px >= x && px <= x + width && py >= y && py <= y + height;
    }
};
```

### 7. 软件工程的实践价值

#### 7.1 可维护性和可扩展性
```cpp
// 现有系统
class PaymentProcessor {
public:
    virtual bool processPayment(double amount) = 0;
    virtual ~PaymentProcessor() = default;
};

class CreditCardProcessor : public PaymentProcessor {
public:
    bool processPayment(double amount) override {
        std::cout << "Processing credit card payment: $" << amount << std::endl;
        return true;
    }
};

// 新增支付方式时，只需扩展，无需修改现有代码
class PayPalProcessor : public PaymentProcessor {
public:
    bool processPayment(double amount) override {
        std::cout << "Processing PayPal payment: $" << amount << std::endl;
        return true;
    }
};

class CryptoProcessor : public PaymentProcessor {
public:
    bool processPayment(double amount) override {
        std::cout << "Processing cryptocurrency payment: $" << amount << std::endl;
        return true;
    }
};
```

### 总结：继承作为主要特征的原因

1. **概念完整性**：继承完整实现了面向对象的"is-a"关系
2. **代码重用**：显著减少代码重复，提高开发效率
3. **多态基础**：为实现运行时多态提供必要机制
4. **架构支撑**：支持构建层次化、模块化的软件架构
5. **设计模式实现**：众多设计模式依赖继承机制
6. **类型扩展**：支持接口和实现的灵活组合
7. **工程实践**：提高代码的可维护性、可扩展性和可读性

正是由于继承在概念建模、代码组织、系统架构和软件工程实践中的核心作用，它才被视为C++面向对象编程的主要特征之一。没有继承，面向对象编程就失去了其最重要的抽象和层次化表达能力。


## 4. 如何声明和使用虚函数，说明它在多态性中的作用和意义。
答：



### 1. 虚函数的基本声明和使用

#### 1.1 虚函数的声明

在C++中，使用`virtual`关键字声明虚函数：

```cpp
class Base {
public:
    // 虚函数声明
    virtual void display() {
        std::cout << "Base class display" << std::endl;
    }
    
    // 纯虚函数声明（抽象类）
    virtual void pureVirtual() = 0;
    
    // 虚析构函数
    virtual ~Base() {
        std::cout << "Base destructor" << std::endl;
    }
};
```

#### 1.2 派生类中的虚函数重写

```cpp
class Derived : public Base {
public:
    // 重写虚函数（override关键字可选但推荐）
    void display() override {
        std::cout << "Derived class display" << std::endl;
    }
    
    // 必须实现纯虚函数
    void pureVirtual() override {
        std::cout << "Implemented pure virtual function" << std::endl;
    }
    
    ~Derived() override {
        std::cout << "Derived destructor" << std::endl;
    }
};
```

#### 1.3 虚函数的使用示例

```cpp
#include <iostream>
#include <vector>

void demonstrate_basic_usage() {
    // 1. 直接对象调用 - 静态绑定
    Base base;
    Derived derived;
    
    base.display();      // 输出: Base class display
    derived.display();   // 输出: Derived class display
    
    std::cout << "--- 多态演示 ---" << std::endl;
    
    // 2. 通过基类指针调用 - 动态绑定
    Base* basePtr = &derived;
    basePtr->display();  // 输出: Derived class display（多态！）
    
    // 3. 通过基类引用调用 - 动态绑定
    Base& baseRef = derived;
    baseRef.display();   // 输出: Derived class display（多态！）
}
```

### 2. 虚函数在多态性中的核心作用

#### 2.1 实现运行时多态

```cpp
class Animal {
public:
    virtual void speak() const {
        std::cout << "Animal speaks" << std::endl;
    }
    
    virtual ~Animal() = default;
};

class Dog : public Animal {
public:
    void speak() const override {
        std::cout << "Woof! Woof!" << std::endl;
    }
};

class Cat : public Animal {
public:
    void speak() const override {
        std::cout << "Meow! Meow!" << std::endl;
    }
};

class Bird : public Animal {
public:
    void speak() const override {
        std::cout << "Chirp! Chirp!" << std::endl;
    }
};

void demonstrate_polymorphism() {
    std::vector<Animal*> animals = {
        new Dog(),
        new Cat(), 
        new Bird(),
        new Dog()
    };
    
    std::cout << "=== 多态性演示 ===" << std::endl;
    
    // 相同的接口，不同的行为 - 这就是多态！
    for (Animal* animal : animals) {
        animal->speak();  // 根据实际对象类型调用相应的speak()
    }
    
    // 清理内存
    for (Animal* animal : animals) {
        delete animal;
    }
}
```

**输出：**
```
=== 多态性演示 ===
Woof! Woof!
Meow! Meow!
Chirp! Chirp!
Woof! Woof!
```

#### 2.2 多态在框架设计中的应用

```cpp
// 图形绘制框架示例
class Shape {
protected:
    std::string name;
public:
    Shape(const std::string& n) : name(n) {}
    
    // 纯虚函数 - 定义接口契约
    virtual double area() const = 0;
    virtual void draw() const = 0;
    virtual void scale(double factor) = 0;
    
    // 虚函数 - 提供默认实现但允许重写
    virtual void printInfo() const {
        std::cout << "Shape: " << name 
                  << ", Area: " << area() << std::endl;
    }
    
    virtual ~Shape() = default;
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : Shape("Circle"), radius(r) {}
    
    double area() const override {
        return 3.14159 * radius * radius;
    }
    
    void draw() const override {
        std::cout << "Drawing a circle with radius " << radius << std::endl;
    }
    
    void scale(double factor) override {
        radius *= factor;
        std::cout << "Circle scaled by " << factor << std::endl;
    }
};

class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : Shape("Rectangle"), width(w), height(h) {}
    
    double area() const override {
        return width * height;
    }
    
    void draw() const override {
        std::cout << "Drawing a rectangle " << width 
                  << "x" << height << std::endl;
    }
    
    void scale(double factor) override {
        width *= factor;
        height *= factor;
        std::cout << "Rectangle scaled by " << factor << std::endl;
    }
};

// 使用多态的图形处理器
class GraphicsProcessor {
public:
    void processShapes(const std::vector<Shape*>& shapes) {
        std::cout << "\n=== 图形处理开始 ===" << std::endl;
        
        for (Shape* shape : shapes) {
            shape->printInfo();  // 多态调用
            shape->draw();       // 多态调用
            shape->scale(1.5);   // 多态调用
            shape->printInfo();  // 缩放后的信息
            
            std::cout << "---" << std::endl;
        }
    }
};
```

### 3. 虚函数的高级用法

#### 3.1 虚函数与访问控制

```cpp
class AccessControlBase {
private:
    virtual void privateVirtual() {
        std::cout << "Base private virtual" << std::endl;
    }
    
protected:
    virtual void protectedVirtual() {
        std::cout << "Base protected virtual" << std::endl;
    }

public:
    void testAccess() {
        privateVirtual();    // OK - 在类内可以调用
        protectedVirtual();  // OK - 在类内可以调用
    }
    
    virtual ~AccessControlBase() = default;
};

class AccessControlDerived : public AccessControlBase {
private:
    // 可以重写基类的protected虚函数，并改为private
    void protectedVirtual() override {
        std::cout << "Derived private override of protected virtual" << std::endl;
    }
    
    // 不能重写基类的private虚函数
    // void privateVirtual() override { } // 错误！
};
```

#### 3.2 协变返回类型

```cpp
class BaseCloneable {
public:
    virtual BaseCloneable* clone() const {
        return new BaseCloneable(*this);
    }
    
    virtual ~BaseCloneable() = default;
};

class DerivedCloneable : public BaseCloneable {
public:
    // 协变返回类型：返回派生类指针
    DerivedCloneable* clone() const override {
        return new DerivedCloneable(*this);
    }
};

void demonstrate_covariance() {
    DerivedCloneable original;
    
    // 可以赋值给基类指针
    BaseCloneable* baseCopy = original.clone();
    
    // 也可以直接赋值给派生类指针
    DerivedCloneable* derivedCopy = original.clone();
    
    delete baseCopy;
    delete derivedCopy;
}
```

#### 3.3 虚析构函数的重要性

```cpp
class WithoutVirtualDestructor {
public:
    ~WithoutVirtualDestructor() {
        std::cout << "WithoutVirtualDestructor destroyed" << std::endl;
    }
};

class DerivedWithoutVirtual : public WithoutVirtualDestructor {
public:
    ~DerivedWithoutVirtual() {
        std::cout << "DerivedWithoutVirtual destroyed" << std::endl;
    }
};

class WithVirtualDestructor {
public:
    virtual ~WithVirtualDestructor() {
        std::cout << "WithVirtualDestructor destroyed" << std::endl;
    }
};

class DerivedWithVirtual : public WithVirtualDestructor {
public:
    ~DerivedWithVirtual() override {
        std::cout << "DerivedWithVirtual destroyed" << std::endl;
    }
};

void demonstrate_virtual_destructor() {
    std::cout << "=== 无虚析构函数 ===" << std::endl;
    WithoutVirtualDestructor* ptr1 = new DerivedWithoutVirtual();
    delete ptr1;  // 只调用基类析构函数！
    
    std::cout << "\n=== 有虚析构函数 ===" << std::endl;
    WithVirtualDestructor* ptr2 = new DerivedWithVirtual();
    delete ptr2;  // 正确调用派生类和基类析构函数
}
```

**输出：**
```
=== 无虚析构函数 ===
WithoutVirtualDestructor destroyed

=== 有虚析构函数 ===
DerivedWithVirtual destroyed
WithVirtualDestructor destroyed
```

### 4. 虚函数的实现机制和性能考虑

#### 4.1 虚函数表（vtable）机制

```cpp
class VTableDemo {
public:
    virtual void func1() { std::cout << "func1" << std::endl; }
    virtual void func2() { std::cout << "func2" << std::endl; }
    void nonVirtual() { std::cout << "nonVirtual" << std::endl; }
    
    int data = 42;
};

void demonstrate_vtable_concept() {
    VTableDemo obj;
    
    std::cout << "对象大小: " << sizeof(obj) << " 字节" << std::endl;
    std::cout << "数据大小: " << sizeof(obj.data) << " 字节" << std::endl;
    // 额外的空间用于存储vptr（虚函数表指针）
}
```

#### 4.2 性能考虑和最佳实践

```cpp
// 性能优化的虚函数使用
class OptimizedBase {
public:
    // 将频繁调用的小函数声明为inline virtual
    virtual inline int getValue() const { return 0; }
    
    // 避免在虚函数中进行复杂操作
    virtual void process() {
        // 将非虚部分提取出来
        preProcess();
        doProcess();  // 真正的虚操作
        postProcess();
    }

protected:
    virtual void doProcess() = 0;  // 由派生类实现

private:
    void preProcess() { /* 通用预处理 */ }
    void postProcess() { /* 通用后处理 */ }
};
```

### 5. 虚函数在多态性中的意义总结

#### 5.1 核心意义

1. **接口统一**：通过基类接口操作各种派生类对象
2. **运行时绑定**：在运行时根据实际对象类型确定调用哪个函数
3. **可扩展性**：新增派生类无需修改现有代码
4. **框架设计**：支持回调、插件架构等高级设计模式

#### 5.2 实际应用场景

```cpp
// 事件处理框架
class Event {
public:
    virtual void handle() = 0;
    virtual ~Event() = default;
};

class ButtonClickEvent : public Event {
public:
    void handle() override {
        std::cout << "Handling button click" << std::endl;
    }
};

class KeyPressEvent : public Event {
public:
    void handle() override {
        std::cout << "Handling key press" << std::endl;
    }
};

class EventDispatcher {
private:
    std::vector<Event*> events;
public:
    void addEvent(Event* event) {
        events.push_back(event);
    }
    
    void processEvents() {
        for (Event* event : events) {
            event->handle();  // 多态处理各种事件
        }
    }
};
```

### 6. 虚函数使用的最佳实践

1. 多态基类声明虚析构函数
2. 使用override关键字明确重写意图
3. 考虑将非虚接口模式（NVI）
4. 避免在构造函数和析构函数中调用虚函数
5. 合理使用final限制进一步重写

```cpp
class BestPracticesBase {
public:
    virtual ~BestPracticesBase() = default;
    
    // 非虚接口模式
    void execute() {
        preExecute();
        doExecute();  // 模板方法
        postExecute();
    }

protected:
    virtual void doExecute() = 0;  // 由派生类实现

private:
    void preExecute() { /* 通用前置处理 */ }
    void postExecute() { /* 通用后置处理 */ }
};

class BestPracticesDerived final : public BestPracticesBase {  // 禁止进一步继承
protected:
    void doExecute() override final {  // 禁止进一步重写
        std::cout << "Specific execution logic" << std::endl;
    }
};
```

虚函数是C++实现运行时多态的基石，正确理解和使用虚函数对于编写高质量、可维护的面向对象代码至关重要。


## 5. 请说明函数模板和模板函数的区别与联系。
答：



在C++模板编程中，"函数模板"和"模板函数"这两个术语经常被混淆，但它们有着明确的区别。

### 1. 基本概念定义

#### 1.1 函数模板（Function Template）
**函数模板**是一个蓝图或配方，用于生成函数的模板。它本身不是具体的函数，而是一个可以产生多个具体函数的模式。

```cpp
// 这是一个函数模板
template<typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}
```

#### 1.2 模板函数（Template Function）
**模板函数**是由函数模板实例化产生的具体函数。它是编译器根据函数模板和具体的模板参数生成的实实在在的函数。

```cpp
// 这些是模板函数（由编译器生成）
int max<int>(int a, int b);        // 显式实例化
double max<double>(double a, double b); // 显式实例化
// 还有隐式实例化的模板函数
```

### 2. 详细区别分析

#### 2.1 本质区别

| 特性 | 函数模板 | 模板函数 |
|------|----------|----------|
| **本质** | 函数的蓝图/配方 | 具体的函数实体 |
| **编译阶段** | 编译时存在为模板定义 | 编译时或链接时生成具体代码 |
| **内存占用** | 不占用运行时内存 | 占用代码段内存 |
| **数量** | 一个模板定义 | 多个具体实例 |

#### 2.2 代码示例说明

```cpp
#include <iostream>
#include <string>

// 函数模板定义 - 这是一个函数模板
template<typename T>
void print(const T& value) {
    std::cout << "Value: " << value << std::endl;
}

// 函数模板特化 - 仍然是函数模板
template<>
void print<bool>(const bool& value) {
    std::cout << "Boolean: " << (value ? "true" : "false") << std::endl;
}

int main() {
    int num = 42;
    double pi = 3.14159;
    std::string text = "Hello";
    bool flag = true;
    
    // 调用时编译器生成模板函数
    print(num);    // 生成模板函数: void print<int>(const int&)
    print(pi);     // 生成模板函数: void print<double>(const double&)
    print(text);   // 生成模板函数: void print<std::string>(const std::string&)
    print(flag);   // 使用特化的模板函数: void print<bool>(const bool&)
    
    return 0;
}
```

在这个例子中：
- `template<typename T> void print(const T& value)` 是**函数模板**
- `print<int>(num)` 调用时生成的 `void print<int>(const int&)` 是**模板函数**

### 3. 实例化过程

#### 3.1 隐式实例化
```cpp
template<typename T>
T add(T a, T b) {
    return a + b;
}

void demo_implicit_instantiation() {
    // 隐式实例化 - 编译器自动推导类型并生成模板函数
    auto result1 = add(5, 3);      // 生成 add<int>(5, 3)
    auto result2 = add(2.5, 3.7);  // 生成 add<double>(2.5, 3.7)
    
    // 编译器实际上生成了：
    // int add<int>(int a, int b) { return a + b; }
    // double add<double>(double a, double b) { return a + b; }
}
```

#### 3.2 显式实例化
```cpp
template<typename T>
T multiply(T a, T b) {
    return a * b;
}

// 显式实例化声明 - 告诉编译器生成这些模板函数
template int multiply<int>(int, int);
template double multiply<double>(double, double);

void demo_explicit_instantiation() {
    // 使用显式实例化的模板函数
    auto result1 = multiply(4, 5);     // 使用已实例化的 multiply<int>
    auto result2 = multiply(1.5, 2.5); // 使用已实例化的 multiply<double>
}
```

### 4. 高级特性和区别

#### 4.1 函数模板的重载
```cpp
// 函数模板1
template<typename T>
void process(T value) {
    std::cout << "Generic process: " << value << std::endl;
}

// 函数模板2 - 重载版本
template<typename T>
void process(T* ptr) {
    std::cout << "Pointer process: " << *ptr << std::endl;
}

// 普通函数 - 也可以重载
void process(const std::string& str) {
    std::cout << "String process: " << str << std::endl;
}

void demo_overloading() {
    int x = 10;
    std::string text = "test";
    
    process(x);        // 调用 process<int> 模板函数
    process(&x);       // 调用 process<int*> 模板函数
    process(text);     // 调用普通函数 process(const std::string&)
}
```

#### 4.2 模板特化与偏特化
```cpp
// 主函数模板
template<typename T, typename U>
bool is_same_type() {
    return false;
}

// 全特化 - 生成特定的模板函数
template<>
bool is_same_type<int, int>() {
    return true;
}

// 对于函数模板，C++不支持偏特化，但可以通过重载模拟
template<typename T>
bool is_same_type<T, T>() {  // 这实际上是重载，不是真正的偏特化
    return true;
}

void demo_specialization() {
    std::cout << std::boolalpha;
    std::cout << is_same_type<int, double>() << std::endl;  // false
    std::cout << is_same_type<int, int>() << std::endl;     // true
}
```

### 5. 编译器和链接器视角

#### 5.1 编译过程分析
```cpp
// math_utils.h
template<typename T>
T square(T x) {  // 函数模板定义
    return x * x;
}

// main.cpp
#include "math_utils.h"

void test_compilation() {
    auto result1 = square(5);     // 实例化 square<int>
    auto result2 = square(2.5);   // 实例化 square<double>
    
    // 编译器生成：
    // int square<int>(int x) { return x * x; }
    // double square<double>(double x) { return x * x; }
}
```

#### 5.2 显式实例化控制
```cpp
// 在头文件中声明函数模板
template<typename T>
T compute(T input);

// 在源文件中定义和显式实例化
template<typename T>
T compute(T input) {
    return input * 2 + 1;
}

// 显式实例化定义
template int compute<int>(int);
template double compute<double>(double);

// 这样其他文件使用 compute<int> 或 compute<double> 时
// 不会产生重复的模板函数定义
```

### 6. 实际应用中的区别

#### 6.1 调试和错误信息
```cpp
template<typename Container>
typename Container::value_type get_first(const Container& cont) {
    if (cont.empty()) {
        throw std::runtime_error("Container is empty");
    }
    return cont[0];
}

void demo_debugging() {
    std::vector<int> vec = {1, 2, 3};
    std::list<std::string> lst = {"a", "b", "c"};
    
    auto first_vec = get_first(vec);  // 模板函数: int get_first<vector<int>>(...)
    auto first_lst = get_first(lst);  // 模板函数: string get_first<list<string>>(...)
    
    // 如果出现错误，编译器会指出具体的模板函数实例化问题
    // std::vector<int> empty_vec;
    // auto bad = get_first(empty_vec);  // 错误在具体的模板函数中
}
```

#### 6.2 性能考虑
```cpp
template<typename T>
class TypeInfo {
public:
    static void print() {
        std::cout << "Unknown type" << std::endl;
    }
};

// 函数模板使用特化
template<typename T>
void print_type_info() {
    TypeInfo<T>::print();
}

// 特化版本
template<>
void print_type_info<int>() {
    std::cout << "Integer type" << std::endl;
}

void demo_performance() {
    // 每个调用使用不同的模板函数，可能内联优化
    print_type_info<int>();     // 可能内联特化版本
    print_type_info<double>();  // 可能内联通用版本
}
```

### 7. 总结：区别与联系

#### 核心区别：
1. **函数模板**是模板定义，是生成函数的蓝图
2. **模板函数**是具体实例，是编译生成的实体函数

#### 相互关系：
- 函数模板是"工厂"，模板函数是"产品"
- 一个函数模板可以生成多个模板函数
- 模板函数是函数模板的具体化表现

#### 类比理解：
```cpp
// 类比：类模板 vs 模板类
template<typename T> class Vector { };  // 类模板
Vector<int> intVector;                   // 模板类

template<typename T> T max(T a, T b) { } // 函数模板
max<int>(5, 3);                         // 模板函数
```

#### 实际编程意义：
- 编写代码时，我们定义**函数模板**
- 编译器在背后生成**模板函数**
- 调试时，我们面对的是具体的**模板函数**实例
- 优化时，编译器对每个**模板函数**单独优化

理解这个区别有助于：
- 更好地理解编译错误信息
- 更有效地进行模板元编程
- 更合理地设计模板代码结构
- 更准确地分析代码性能和大小

在日常讨论中，虽然这两个术语有时被混用，但在严谨的C++编程中，区分它们对于深入理解模板机制非常重要。



# 二、编程题（100分）
## [Problem 1](1/1.cpp)
> 编写一个程序，利用下面的公式计算e^x的值，要求精确到10^-10。

 ![image](images/1.gif)
## [Problem 2](2/2.cpp)
> 编写一个程序，利用下面的公式计算pi的值，要求小数点后的位数为计算机可表达的最大范围。

![image](images/2.gif)
## [Problem 3](3/3.cpp) 
> 编写一个递归函数模板，从一个数组中找出最小值，并返回该值的数组下标元素。
## [Problem 4](4/4.cpp)
> 编写两个函数SortOne和SortTwo分别对字符串数组实现插入排序和选择排序。
## Problem 5 [main函数](5/5.cpp)|[Array.h](5/Array.h)
> 自定义数组Array的operator()访问，对于一个数组 Array 类的 chess 对象通过调用运算符重载函数()，实现 chess(row,column)代替 chess[row][column]。</br>
> 请完成:</br>
> （1）Array 类的基本定义，包括构造函数、析构函数、拷贝构造函数和基本数据成员;</br>
> （2）运算符重载函数()的定义。
## Problem 6
## [main函数](6/6.cpp)|[Shape.h](6/Shape.h)|[Point.h](6/Point.h)|[Circle.h](6/Circle.h)|[Rec.h](6/Rec.h)|[Tri.h](6/Tri.h)
> 定义一个具有多态性的基类Shape，派生出三个类：圆 Circle 类(圆心坐标和半径)，矩形 Rec 类(对角线两点不同坐标)，三角形 Tri 类(三个不同坐标)，每个类中至少有一个计算面积的函数。编写程序，从文件 [file.txt](6/file.txt) 中读取数据来创建各类的对象，并放在 Shape 指针向量中，最后循环处理每个对象并输出面积。

题目参考自：https://blog.csdn.net/qq_32925781/article/details/79389350