# 一、简答题（60分）
## 1. 简述你对“面向过程”和“面向对象”编程思想的认识与思考。
答：

1. 面向过程是将解决问题的重点放在如何实现过程的细节方面，把数据和对数据进行操作的函数分开，以数据结构为核心，围绕着功能的实现或操作流程来设计程序，安全性较低，扩展升级麻烦，当问题的规模变大时，编程将很复杂；
2. 面向对象将客观事物看作具有属性和行为的对象，通过抽象找出同一类对象的共同属性（静态特征）和行为（动态特征），形成类。通过继承与多态可以很方便地实现代码复用，缩短软件开发周期，并使软件风格统一。



### 面向过程（POP）

以函数驱动为核心，通过算法流程分解问题。
典型场景：数学计算、底层系统开发。  

```c++
// 过程式数组处理
void sortArray(int arr[], int size) {
    std::sort(arr, arr + size);
}
```

### 面向对象（OOP）

以对象交互为核心，通过类抽象实体。
通过class关键字实现封装（数据+方法绑定）。
典型场景：GUI开发、游戏引擎。 

```C++
class BankAccount {
private:
    double balance;
public:
    void deposit(double amount) { 
        balance += amount; 
    }
    // 封装保证了数据操作的安全性
};
```

### C++特性对OOP的增强

- 访问控制 
实现信息隐藏，如STL容器隐藏内部迭代器实现细节。  
- 继承体系 
通过class Derived : public Base构建层次结构。
- 多态机制 
虚函数表（vtable）支持动态绑定，实现运行时类型识别（RTTI）。

```C++
class Shape {
public:
    virtual double area() const = 0; // 纯虚函数
};
class Circle : public Shape {
    double radius;
public:
    double area() const override { 
        return 3.14 * radius * radius; 
    }
};
```

## 2. ADT是什么？简述你对“数据抽象”和“信息隐藏”的认识。
答：

ADT是指抽象数据类型，是基于已有类型组合生成的复合数据类型，类是抽象数据类型的描述形式。

数据抽象：以数据为中心，把数据与对数据的操作作为一个整体进行描述；

信息隐藏：通过封装，实现信息隐藏，将类外部的接口放在类的公有部分，数据放在类的私有部分，防止用户在类外直接访问数据，屏蔽了类的实现细节。



### ADT（抽象数据类型）

ADT（Abstract Data Type）是一种逻辑模型，描述数据的操作集合及其行为规范，而非具体实现。例如，栈的ADT定义为push（入栈）、pop（出栈）、top（查看栈顶）等操作，不涉及数组或链表等物理实现。
关键特性：

1.  接口与实现分离：用户只需关注操作语义（如std::vector的push_back），无需了解动态数组扩容策略。
2.  多态性：同一ADT可多种实现（如C++中std::stack可用std::deque或std::list作为底层容器）。
3.  契约编程：通过前置条件、后置条件定义行为约束（如调用pop时栈不可为空）。

C++中的体现：通过类（class）或模板（如STL容器）实现ADT，例如：
```C++
template<typename T>
class Stack {
public:
    virtual void push(const T& item) = 0;  // 纯虚函数定义接口
    virtual T pop() = 0;
    // 隐藏底层数据结构（可能是数组/链表）
};
```

### 数据抽象（Data Abstraction）

核心思想：聚焦“做什么”（What）而非“怎么做”（How），通过分层抽象简化复杂度。
实现方式：

1.  逻辑视图与物理存储解耦：如数据库表结构对用户隐藏存储引擎细节。
2.  操作封装：将数据与其关联的方法绑定（如std::string的方法隐藏字符计数逻辑）。
3.  约束封装：在抽象层定义数据有效性规则（如std::vector的方法进行边界检查）。

### 信息隐藏（Information Hiding）

定义：通过访问控制限制对内部实现的直接访问，是数据抽象的技术手段。
关键作用：

1.  防止误操作：私有成员（private）禁止外部直接修改，如禁止用户直接操作std::vector的容量指针。
2.  降低耦合度：修改内部实现（如将链表改为数组）不影响用户代码。
3.  提升安全性：隐藏敏感数据（如加密算法中的密钥存储）。


## 3. const和static有什么作用？
答：

在C++中，`const`和`static`是两个非常重要的关键字，它们在不同的上下文中有着不同的作用和含义。

### const 关键字

#### 1. 基本作用：定义常量
```cpp
const int MAX_SIZE = 100;
const double PI = 3.14159;
```

#### 2. 指针与 const
```cpp
const int* ptr1;        // 指向常量的指针，不能通过ptr1修改指向的值
int* const ptr2;        // 常量指针，指针本身不能指向其他地址
const int* const ptr3;  // 指向常量的常量指针
```

#### 3. 函数中的 const
```cpp
// const 参数：函数内不能修改参数值
void printValue(const int value) {
    // value = 10; // 错误！不能修改const参数
}

// const 返回值：返回的值不能被修改
const int& getReference(const int& value) {
    return value;
}

// const 成员函数：承诺不修改对象状态
class MyClass {
private:
    int data;
public:
    int getData() const {  // 不能修改成员变量
        return data;
    }
    void setData(int val) {  // 非const函数可以修改成员
        data = val;
    }
};
```

### static 关键字

#### 1. 静态局部变量
```cpp
void counter() {
    static int count = 0;  // 只初始化一次，生命周期持续到程序结束
    count++;
    cout << "Count: " << count << endl;
}

// 调用示例
counter(); // 输出: Count: 1
counter(); // 输出: Count: 2
counter(); // 输出: Count: 3
```

#### 2. 静态成员变量
```cpp
class Student {
private:
    static int totalStudents;  // 静态成员变量，所有对象共享
    string name;
public:
    Student(string n) : name(n) {
        totalStudents++;  // 每个新对象创建时递增
    }
    
    static int getTotal() {  // 静态成员函数
        return totalStudents;
    }
};

// 静态成员变量必须在类外定义
int Student::totalStudents = 0;

// 使用示例
Student s1("Alice");
Student s2("Bob");
cout << Student::getTotal();  // 输出: 2
```

#### 3. 静态成员函数
```cpp
class MathUtils {
public:
    static double pi() {      // 静态成员函数
        return 3.14159;
    }
    
    static int max(int a, int b) {
        return (a > b) ? a : b;
    }
};

// 使用：无需创建对象
double circumference = 2 * MathUtils::pi() * radius;
```

#### 4. 静态全局变量和函数
```cpp
// file1.cpp
static int localVar = 10;        // 只在当前文件可见
static void localFunction() {    // 只在当前文件可见
    // ...
}

// file2.cpp
extern int localVar;             // 错误！无法访问其他文件的static变量
```

### const 和 static 的组合使用

#### 1. 静态常量成员
```cpp
class Constants {
public:
    static const int MAX_SIZE = 100;      // 整型静态常量可以在类内初始化
    static const double PI;               // 非整型需要在类外定义
};

const double Constants::PI = 3.14159;     // 类外定义

// 使用
int array[Constants::MAX_SIZE];
```

#### 2. 常量静态成员函数
```cpp
class Calculator {
private:
    static double lastResult;
public:
    static double add(double a, double b) const {  // 错误！静态函数不能是const
        return a + b;
    }
    
    // 正确的静态函数
    static double multiply(double a, double b) {
        lastResult = a * b;
        return lastResult;
    }
};
```

### 实际应用场景总结

#### const 的应用场景：
- **保护数据**：防止意外修改
- **接口设计**：明确函数不会修改参数或对象状态
- **编译器优化**：帮助编译器进行更好的优化
- **线程安全**：const对象天生具有更好的线程安全性

#### static 的应用场景：
- **共享数据**：在类的所有对象间共享数据
- **单例模式**：实现单例设计模式
- **工具函数**：不需要对象实例就能调用的工具函数
- **持久化存储**：保持变量的值在函数调用间不变

#### 组合使用示例：
```cpp
class DatabaseConfig {
private:
    static const int MAX_CONNECTIONS = 100;    // 静态常量
    static int currentConnections;             // 静态变量
    
public:
    static bool canCreateConnection() {        // 静态函数
        return currentConnections < MAX_CONNECTIONS;
    }
    
    const string& getConfig() const {          // const成员函数
        static const string config = "default";
        return config;
    }
};

int DatabaseConfig::currentConnections = 0;    // 静态变量定义
```

这两个关键字是C++中实现封装、数据保护和资源管理的重要工具，正确使用它们可以大大提高代码的质量和可维护性。


## 4. 友元关系的利与弊。
答：

### C++中友元关系的利与弊

友元（friend）是C++中一种特殊的机制，它允许一个类或函数访问另一个类的私有（private）和保护（protected）成员。下面详细分析友元关系的利与弊。

### 友元的优势

#### 1. 提高访问效率
```cpp
class Matrix {
private:
    double data[4][4];
public:
    friend Vector operator*(const Matrix& m, const Vector& v);
    // 友元函数可以直接访问data，避免getter/setter的开销
};

class Vector {
private:
    double x, y, z, w;
    friend Vector operator*(const Matrix& m, const Vector& v);
};

Vector operator*(const Matrix& m, const Vector& v) {
    Vector result;
    // 直接访问双方的私有成员，效率高
    result.x = m.data[0][0]*v.x + m.data[0][1]*v.y + 
               m.data[0][2]*v.z + m.data[0][3]*v.w;
    // ... 其他计算
    return result;
}
```

#### 2. 支持运算符重载
```cpp
class Complex {
private:
    double real, imag;
public:
    Complex(double r, double i) : real(r), imag(i) {}
    
    // 重载输出运算符
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
};

std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << c.real << " + " << c.imag << "i";  // 直接访问私有成员
    return os;
}
```

#### 3. 实现紧密协作的类
```cpp
class TreeNode;  // 前向声明

class Tree {
private:
    TreeNode* root;
public:
    friend class TreeIterator;  // 迭代器需要访问树的内部结构
};

class TreeIterator {
private:
    TreeNode* current;
    Tree* container;
public:
    // 可以自由访问Tree的私有成员
    void begin() { current = container->root; }
    bool end() const { return current == nullptr; }
};
```

#### 4. 单元测试支持
```cpp
class BankAccount {
private:
    double balance;
    void applyInterest() { balance *= 1.05; }  // 私有方法
    
    // 测试类可以访问私有成员进行白盒测试
    friend class BankAccountTest;
};

class BankAccountTest {
public:
    static void testInterestCalculation() {
        BankAccount acc;
        // 可以直接测试私有方法
        acc.applyInterest();
        // 验证结果...
    }
};
```

#### 5. 实现设计模式
```cpp
// 工厂模式
class Product {
private:
    Product() {}  // 私有构造函数
    friend class ProductFactory;  // 只有工厂能创建对象
};

class ProductFactory {
public:
    static Product* create() {
        return new Product();  // 可以调用私有构造函数
    }
};
```

### 友元的弊端

#### 1. 破坏封装性
```cpp
class SecureData {
private:
    string sensitiveData;  // 本应是封装的
    int secretKey;
    
    friend class DataProcessor;  // 破坏了封装性
};

class DataProcessor {
public:
    void misuseData(SecureData& data) {
        // 可以随意访问和修改私有数据，失去了控制
        data.sensitiveData = "modified";
        data.secretKey = 12345;
    }
};
```

#### 2. 增加耦合度
```cpp
class ClassA {
private:
    int internalData;
    friend class ClassB;  // 与ClassB紧密耦合
};

class ClassB {
    // 如果ClassA的实现改变，ClassB可能也需要修改
};
```

#### 3. 降低可维护性
```cpp
class Database {
private:
    Connection* conn;
    friend class QueryExecutor;  // 友元声明
    // 如果删除这个友元关系，需要检查所有相关代码
};

// 在项目的其他地方可能有很多依赖这个友元关系的代码
```

#### 4. 测试困难
```cpp
class Singleton {
private:
    static Singleton* instance;
    Singleton() {}
    
    friend class Application;  // 只有Application可以创建实例
    // 这使得单元测试难以创建独立的测试实例
};
```

#### 5. 继承问题
```cpp
class Base {
private:
    int baseData;
    friend class FriendClass;
};

class Derived : public Base {
    // FriendClass可以访问baseData，但不能访问Derived的私有成员
    // 这种不对称性可能造成混淆
};
```

### 最佳实践建议

#### 1. 最小化友元使用
```cpp
// 不好：整个类都是友元
friend class Utility;

// 更好：只声明需要的函数为友元
friend void utilityFunction(MyClass& obj);
```

#### 2. 使用成员函数替代
```cpp
// 考虑是否可以用公共成员函数替代友元
class Calculator {
public:
    double calculate(const Matrix& m, const Vector& v) {
        // 如果Matrix和Vector提供足够的公共接口，可能不需要友元
        return m.get(0,0) * v.getX() + /* ... */;
    }
};
```

#### 3. 文档化友元关系
```cpp
class Document {
private:
    string content;
    
    /**
     * @brief Printer需要直接访问content以优化打印性能
     * 这种关系在设计中是必要的，因为...
     */
    friend class Printer;
};
```

#### 4. 考虑替代方案
```cpp
// 使用接口类而非友元
class IDataAccess {
public:
    virtual const string& getData() const = 0;
    virtual ~IDataAccess() = default;
};

class SecureData : public IDataAccess {
private:
    string sensitiveData;
public:
    const string& getData() const override { return sensitiveData; }
};
```

### 总结

友元关系在C++中是一把双刃剑：

**适用场景：**
- 运算符重载
- 紧密协作的类（如容器和迭代器）
- 工厂模式
- 性能关键的代码
- 单元测试

**避免场景：**
- 可以用公共接口替代的情况
- 会破坏重要封装性的情况
- 在大型项目中可能造成维护问题的情况

使用友元时应遵循"最小权限原则"，只授予必要的访问权限，并充分文档化设计决策。


## 5. C++多态的实现。
答：



多态是面向对象编程的三大特性之一，C++主要通过虚函数机制来实现多态。下面详细介绍C++中多态的实现方式。

### 1. 多态的基本概念

多态分为两种类型：
- **编译时多态**：通过函数重载和运算符重载实现
- **运行时多态**：通过虚函数和继承实现

### 2. 虚函数机制

#### 2.1 基本虚函数使用
```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    virtual void speak() {
        cout << "Animal speaks" << endl;
    }
    
    virtual ~Animal() = default;  // 虚析构函数
};

class Dog : public Animal {
public:
    void speak() override {  // override关键字(C++11)
        cout << "Woof!" << endl;
    }
};

class Cat : public Animal {
public:
    void speak() override {
        cout << "Meow!" << endl;
    }
};

int main() {
    Animal* animal1 = new Dog();
    Animal* animal2 = new Cat();
    
    animal1->speak();  // 输出: Woof!
    animal2->speak();  // 输出: Meow!
    
    delete animal1;
    delete animal2;
    return 0;
}
```

#### 2.2 纯虚函数和抽象类
```cpp
class Shape {
public:
    virtual double area() const = 0;  // 纯虚函数
    virtual void draw() const = 0;
    
    virtual ~Shape() = default;
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    
    double area() const override {
        return 3.14159 * radius * radius;
    }
    
    void draw() const override {
        cout << "Drawing a circle" << endl;
    }
};

class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    
    double area() const override {
        return width * height;
    }
    
    void draw() const override {
        cout << "Drawing a rectangle" << endl;
    }
};
```

### 3. 虚函数表（vtable）机制

#### 3.1 vtable 工作原理
```cpp
class Base {
public:
    virtual void func1() { cout << "Base::func1" << endl; }
    virtual void func2() { cout << "Base::func2" << endl; }
    void nonVirtual() { cout << "Base::nonVirtual" << endl; }
};

class Derived : public Base {
public:
    void func1() override { cout << "Derived::func1" << endl; }
    void func3() { cout << "Derived::func3" << endl; }
};
```

内存布局示意图：
```
Base 对象：
+---------+
| vptr    | --> Base的vtable
+---------+     +-------------------+
| 其他数据 |     | &Base::func1      |
+---------+     | &Base::func2      |
                +-------------------+

Derived 对象：
+---------+
| vptr    | --> Derived的vtable
+---------+     +-------------------+
| 基类数据 |     | &Derived::func1   |
+---------+     | &Base::func2      |
| 派生类数据|     +-------------------+
+---------+
```

#### 3.2 验证vtable的存在
```cpp
#include <iostream>
using namespace std;

class Test {
public:
    virtual void vfunc1() {}
    virtual void vfunc2() {}
    int data;
};

int main() {
    Test obj;
    cout << "对象大小: " << sizeof(obj) << " bytes" << endl;  // 通常为16字节(64位系统)
    cout << "数据大小: " << sizeof(obj.data) << " bytes" << endl;  // 4字节
    // 额外的8字节是vptr
    return 0;
}
```

### 4. 多态的实现细节

#### 4.1 动态绑定的条件
```cpp
class Base {
public:
    virtual void virtualFunc() { cout << "Base" << endl; }
    void nonVirtualFunc() { cout << "Base non-virtual" << endl; }
};

class Derived : public Base {
public:
    void virtualFunc() override { cout << "Derived" << endl; }
    void nonVirtualFunc() { cout << "Derived non-virtual" << endl; }
};

int main() {
    Derived derived;
    Base* basePtr = &derived;
    
    // 动态绑定 - 通过虚函数表查找
    basePtr->virtualFunc();      // 输出: Derived
    
    // 静态绑定 - 编译时确定
    basePtr->nonVirtualFunc();   // 输出: Base non-virtual
    
    // 对象直接调用 - 静态绑定
    derived.nonVirtualFunc();    // 输出: Derived non-virtual
    
    return 0;
}
```

#### 4.2 虚析构函数的重要性
```cpp
class BaseWithoutVirtual {
public:
    ~BaseWithoutVirtual() { cout << "Base destructor" << endl; }
};

class DerivedWithoutVirtual : public BaseWithoutVirtual {
public:
    ~DerivedWithoutVirtual() { cout << "Derived destructor" << endl; }
};

class BaseWithVirtual {
public:
    virtual ~BaseWithVirtual() { cout << "Base virtual destructor" << endl; }
};

class DerivedWithVirtual : public BaseWithVirtual {
public:
    ~DerivedWithVirtual() override { cout << "Derived virtual destructor" << endl; }
};

int main() {
    // 问题：没有虚析构函数
    BaseWithoutVirtual* ptr1 = new DerivedWithoutVirtual();
    delete ptr1;  // 只调用Base的析构函数！
    
    cout << "---" << endl;
    
    // 正确：有虚析构函数
    BaseWithVirtual* ptr2 = new DerivedWithVirtual();
    delete ptr2;  // 正确调用Derived和Base的析构函数
    
    return 0;
}
```

输出：
```
Base destructor
---
Derived virtual destructor
Base virtual destructor
```

### 5. 高级多态特性

#### 5.1 final 和 override 关键字
```cpp
class Base {
public:
    virtual void func() { cout << "Base" << endl; }
    virtual void cannotOverride() final { cout << "Final" << endl; }
};

class Derived : public Base {
public:
    void func() override { cout << "Derived" << endl; }  // 正确重写
    
    // 错误！不能重写final函数
    // void cannotOverride() override { }
};

class FinalClass final {
    // 这个类不能被继承
};

// 错误！不能继承final类
// class Child : public FinalClass { };
```

#### 5.2 协变返回类型
```cpp
class Animal {
public:
    virtual Animal* clone() const {
        return new Animal(*this);
    }
};

class Dog : public Animal {
public:
    // 协变返回类型：返回派生类指针
    Dog* clone() const override {
        return new Dog(*this);
    }
};

int main() {
    Dog dog;
    Animal* animal = dog.clone();  // 返回Dog*，可以赋值给Animal*
    Dog* dogCopy = dog.clone();    // 也可以直接赋值给Dog*
    
    delete animal;
    delete dogCopy;
    return 0;
}
```

#### 5.3 虚函数与默认参数
```cpp
class Base {
public:
    virtual void show(int x = 10) {
        cout << "Base: " << x << endl;
    }
};

class Derived : public Base {
public:
    void show(int x = 20) override {
        cout << "Derived: " << x << endl;
    }
};

int main() {
    Base* obj = new Derived();
    obj->show();  // 输出: Derived: 10
    // 默认参数在编译时确定，使用Base类的默认值
    delete obj;
    return 0;
}
```

### 6. 性能考虑和最佳实践

#### 6.1 性能影响
- **空间开销**：每个包含虚函数的对象都有一个vptr
- **时间开销**：虚函数调用需要额外的间接寻址
- **内联限制**：虚函数通常不能被内联

#### 6.2 最佳实践
```cpp
class GoodDesign {
public:
    // 1. 多态基类声明虚析构函数
    virtual ~GoodDesign() = default;
    
    // 2. 使用override明确重写
    virtual void method() const = 0;
    
    // 3. 避免在虚函数中使用默认参数
    virtual void process(int value) = 0;
    
    // 4. 考虑将非虚接口模式(NVI)
    void execute() {
        preProcess();
        doExecute();  // 真正的虚函数
        postProcess();
    }

private:
    virtual void doExecute() = 0;  // 由派生类实现
    void preProcess() { /* 通用预处理 */ }
    void postProcess() { /* 通用后处理 */ }
};
```

### 7. 替代多态的技术

#### 7.1 CRTP（奇异递归模板模式）
```cpp
template <typename Derived>
class Base {
public:
    void interface() {
        static_cast<Derived*>(this)->implementation();
    }
};

class Derived1 : public Base<Derived1> {
public:
    void implementation() {
        cout << "Derived1 implementation" << endl;
    }
};

class Derived2 : public Base<Derived2> {
public:
    void implementation() {
        cout << "Derived2 implementation" << endl;
    }
};
```

#### 7.2 std::variant 和访问者模式
```cpp
#include <variant>
#include <vector>

class Circle { /* ... */ };
class Rectangle { /* ... */ };
class Triangle { /* ... */ };

using Shape = std::variant<Circle, Rectangle, Triangle>;

struct DrawVisitor {
    void operator()(const Circle& c) const { /* 绘制圆 */ }
    void operator()(const Rectangle& r) const { /* 绘制矩形 */ }
    void operator()(const Triangle& t) const { /* 绘制三角形 */ }
};

int main() {
    std::vector<Shape> shapes = {Circle(), Rectangle(), Triangle()};
    
    for (const auto& shape : shapes) {
        std::visit(DrawVisitor{}, shape);  // 编译时多态
    }
    
    return 0;
}
```

### 总结

C++的多态主要通过虚函数机制实现，核心要点包括：

1. **虚函数表**：每个多态类都有一个vtable，包含虚函数指针
2. **虚函数指针**：每个对象都有一个vptr指向其类的vtable
3. **动态绑定**：通过vptr在运行时确定调用的函数
4. **重要规则**：多态基类必须有虚析构函数
5. **现代特性**：使用override和final提高代码安全性

多态是C++面向对象编程的核心特性，正确理解其实现机制对于编写高效、可维护的C++代码至关重要。


## 6. STL是什么？有哪些组成部分？核心作用是什么？
答：



### 1. STL 概述

**STL（Standard Template Library）** 是C++标准库的核心组成部分，提供了一系列通用的模板类和函数，实现了常用的数据结构和算法。STL基于泛型编程思想，使得代码可以独立于具体的数据类型工作。

### 2. STL 的核心组件

STL主要由六大组件组成：

#### 2.1 容器（Containers）
用于存储和管理数据的模板类。

##### 序列容器
```cpp
#include <vector>
#include <list>
#include <deque>
#include <array>
#include <forward_list>

// vector - 动态数组
std::vector<int> vec = {1, 2, 3};
vec.push_back(4);  // 在末尾添加元素

// list - 双向链表
std::list<std::string> names = {"Alice", "Bob"};
names.push_front("Charlie");

// deque - 双端队列
std::deque<double> dq = {1.1, 2.2};
dq.push_back(3.3);
dq.push_front(0.0);

// array - 固定大小数组
std::array<int, 5> arr = {1, 2, 3, 4, 5};
```

##### 关联容器
```cpp
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

// set - 有序集合（红黑树实现）
std::set<int> uniqueNumbers = {3, 1, 4, 1, 5};  // {1, 3, 4, 5}

// map - 有序键值对
std::map<std::string, int> ages = {
    {"Alice", 25},
    {"Bob", 30}
};
ages["Charlie"] = 28;

// unordered_set - 哈希集合
std::unordered_set<std::string> words = {"apple", "banana"};

// unordered_map - 哈希映射
std::unordered_map<int, std::string> employees = {
    {101, "John"},
    {102, "Jane"}
};
```

##### 容器适配器
```cpp
#include <stack>
#include <queue>

// stack - 后进先出
std::stack<int> st;
st.push(1);
st.push(2);
int top = st.top();  // 2
st.pop();

// queue - 先进先出
std::queue<std::string> q;
q.push("first");
q.push("second");
std::string front = q.front();  // "first"

// priority_queue - 优先队列
std::priority_queue<int> pq;
pq.push(3);
pq.push(1);
pq.push(4);
int max = pq.top();  // 4（最大元素）
```

#### 2.2 算法（Algorithms）
操作容器中元素的通用函数模板。

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

void demonstrate_algorithms() {
    std::vector<int> numbers = {3, 1, 4, 1, 5, 9, 2, 6};
    
    // 排序
    std::sort(numbers.begin(), numbers.end());
    
    // 查找
    auto it = std::find(numbers.begin(), numbers.end(), 5);
    if (it != numbers.end()) {
        std::cout << "Found 5 at position: " << (it - numbers.begin()) << std::endl;
    }
    
    // 计数
    int count = std::count(numbers.begin(), numbers.end(), 1);
    
    // 反转
    std::reverse(numbers.begin(), numbers.end());
    
    // 遍历并处理
    std::for_each(numbers.begin(), numbers.end(), [](int n) {
        std::cout << n << " ";
    });
    
    // 变换
    std::vector<int> squared;
    std::transform(numbers.begin(), numbers.end(), 
                  std::back_inserter(squared), [](int n) {
        return n * n;
    });
}
```

#### 2.3 迭代器（Iterators）
提供访问容器元素的统一接口。

```cpp
#include <vector>
#include <list>
#include <iostream>

void iterate_examples() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    
    // 1. 使用迭代器遍历
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // 2. 反向迭代器
    for (auto rit = vec.rbegin(); rit != vec.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;
    
    // 3. 常量迭代器（只读）
    for (auto cit = vec.cbegin(); cit != vec.cend(); ++cit) {
        // *cit = 10;  // 错误！不能修改
        std::cout << *cit << " ";
    }
    std::cout << std::endl;
    
    // 4. 基于范围的for循环（C++11）
    for (const auto& element : vec) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}
```

#### 2.4 函数对象（Functors）和Lambda
```cpp
#include <algorithm>
#include <vector>
#include <functional>

struct GreaterThan {
    int threshold;
    GreaterThan(int t) : threshold(t) {}
    bool operator()(int value) const {
        return value > threshold;
    }
};

void functor_examples() {
    std::vector<int> numbers = {1, 5, 3, 8, 2, 7};
    
    // 使用函数对象
    GreaterThan gt(4);
    auto it1 = std::find_if(numbers.begin(), numbers.end(), gt);
    
    // 使用标准库函数对象
    std::sort(numbers.begin(), numbers.end(), std::greater<int>());
    
    // 使用Lambda表达式（C++11）
    auto it2 = std::find_if(numbers.begin(), numbers.end(), 
                           [](int n) { return n % 2 == 0; });
    
    // 带捕获的Lambda
    int threshold = 5;
    int count = std::count_if(numbers.begin(), numbers.end(),
                             [threshold](int n) { return n > threshold; });
}
```

#### 2.5 适配器（Adapters）
```cpp
#include <stack>
#include <queue>
#include <vector>
#include <functional>

void adapter_examples() {
    // 容器适配器
    std::stack<int, std::vector<int>> st;  // 使用vector作为底层容器
    std::queue<int, std::list<int>> q;     // 使用list作为底层容器
    
    // 迭代器适配器
    std::vector<int> vec = {1, 2, 3};
    std::vector<int> dest;
    
    // back_inserter - 在末尾插入
    std::copy(vec.begin(), vec.end(), std::back_inserter(dest));
    
    // 函数适配器（C++11中较少使用，多用Lambda）
    auto is_even = [](int n) { return n % 2 == 0; };
    auto is_odd = std::not1(std::function<bool(int)>(is_even));
}
```

#### 2.6 分配器（Allocators）
```cpp
#include <vector>
#include <memory>

void allocator_example() {
    // 使用自定义分配器
    std::vector<int, std::allocator<int>> vec;
    
    // 也可以使用其他分配器，如pool_alloc
    // std::vector<int, __gnu_cxx::pool_alloc<int>> pool_vec;
}
```

### 3. STL 的核心作用

#### 3.1 代码复用和泛型编程
```cpp
// 同一个算法可以用于不同类型的容器
template<typename Container>
void process_container(const Container& cont) {
    for (const auto& element : cont) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

void usage() {
    std::vector<int> vec = {1, 2, 3};
    std::list<std::string> lst = {"a", "b", "c"};
    
    process_container(vec);  // 处理vector
    process_container(lst);  // 处理list
}
```

#### 3.2 类型安全和性能
```cpp
#include <array>

void safety_and_performance() {
    // 类型安全 - 编译时检查
    std::array<int, 5> arr = {1, 2, 3, 4, 5};
    // arr[10] = 100;  // 编译时可能检测到越界（某些编译器）
    
    // 性能优化
    std::vector<int> vec;
    vec.reserve(1000);  // 预分配内存，避免重复分配
    
    // 移动语义（C++11）
    std::vector<int> source = {1, 2, 3};
    std::vector<int> destination = std::move(source);  // 高效移动
}
```

#### 3.3 实际应用示例
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

class StudentManager {
private:
    std::map<int, std::string> students;  // 学号到姓名的映射
    std::multimap<std::string, int> courses;  // 课程到学号的映射
    
public:
    void addStudent(int id, const std::string& name) {
        students[id] = name;
    }
    
    void enrollCourse(int id, const std::string& course) {
        courses.insert({course, id});
    }
    
    void printStudentsInCourse(const std::string& course) {
        auto range = courses.equal_range(course);
        std::cout << "Students in " << course << ":\n";
        for (auto it = range.first; it != range.second; ++it) {
            std::cout << students[it->second] << " (ID: " << it->second << ")\n";
        }
    }
    
    void removeStudent(int id) {
        auto name_it = students.find(id);
        if (name_it != students.end()) {
            // 从courses中删除该学生的所有选课记录
            for (auto it = courses.begin(); it != courses.end(); ) {
                if (it->second == id) {
                    it = courses.erase(it);
                } else {
                    ++it;
                }
            }
            students.erase(name_it);
        }
    }
};
```

### 4. 现代C++中的STL增强

#### 4.1 C++11/14/17/20 新特性
```cpp
#include <vector>
#include <algorithm>
#include <numeric>

void modern_stl_features() {
    // 移动语义
    std::vector<std::string> old_vec = {"hello", "world"};
    std::vector<std::string> new_vec = std::move(old_vec);  // 高效移动
    
    // 智能指针与STL
    std::vector<std::unique_ptr<int>> smart_vec;
    smart_vec.push_back(std::make_unique<int>(42));
    
    // 并行算法（C++17）
    std::vector<int> data(1000000);
    std::iota(data.begin(), data.end(), 0);
    
    // 并行排序
    std::sort(std::execution::par, data.begin(), data.end());
    
    // 字符串视图（C++17）
    std::string long_text = "This is a very long text...";
    std::string_view view = long_text;  // 不拷贝字符串
    
    // 结构化绑定（C++17）
    std::map<int, std::string> map = {{1, "one"}, {2, "two"}};
    for (const auto& [key, value] : map) {
        std::cout << key << ": " << value << std::endl;
    }
}
```

### 5. STL 的最佳实践

#### 5.1 选择合适的容器
```cpp
void choose_container() {
    // 随机访问频繁 - 使用vector或deque
    std::vector<int> for_random_access;
    
    // 频繁在中间插入删除 - 使用list
    std::list<int> for_frequent_insertions;
    
    // 快速查找 - 使用set/map或unordered_set/unordered_map
    std::unordered_map<std::string, int> for_fast_lookup;
    
    // 需要排序 - 使用set/map
    std::set<int> for_sorted_data;
}
```

#### 5.2 高效使用算法
```cpp
#include <algorithm>
#include <vector>

void efficient_algorithms() {
    std::vector<int> data = {5, 2, 8, 1, 9};
    
    // 使用算法而不是手写循环
    if (std::all_of(data.begin(), data.end(), [](int n) { return n > 0; })) {
        std::cout << "All positive\n";
    }
    
    // 使用accumulate而不是手动求和
    int sum = std::accumulate(data.begin(), data.end(), 0);
    
    // 使用remove-erase惯用法删除元素
    data.erase(std::remove(data.begin(), data.end(), 2), data.end());
}
```

### 总结

STL的核心价值：
1. **标准化**：提供统一的数据结构和算法接口
2. **类型安全**：编译时类型检查
3. **高性能**：经过高度优化的实现
4. **可扩展**：支持自定义类型和算法
5. **可维护性**：清晰的接口和一致的命名约定

STL是现代C++编程的基石，熟练掌握STL是成为高效C++开发者的关键。


# 二、程序设计题（90分）
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