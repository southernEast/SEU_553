# 一、简答题
## 1. 编写语句说明枚举类型是如何定义和使用的。
答：



枚举类型是C++中一种重要的用户定义类型，用于表示一组相关的命名常量。C++支持两种枚举：传统枚举（C风格）和枚举类（C++11引入）。

### 1. 传统枚举（C风格枚举）

#### 1.1 基本定义
```cpp
// 基本枚举定义
enum Color {
    RED,    // 0
    GREEN,  // 1  
    BLUE    // 2
};

// 指定起始值
enum Weekday {
    MONDAY = 1,
    TUESDAY,   // 2
    WEDNESDAY, // 3
    THURSDAY,  // 4
    FRIDAY,    // 5
    SATURDAY,  // 6
    SUNDAY     // 7
};

// 显式指定所有值
enum HttpStatus {
    OK = 200,
    CREATED = 201,
    BAD_REQUEST = 400,
    NOT_FOUND = 404,
    SERVER_ERROR = 500
};
```

#### 1.2 使用示例
```cpp
#include <iostream>

enum TrafficLight {
    RED,
    YELLOW,
    GREEN
};

void traditional_enum_demo() {
    TrafficLight light = RED;
    
    switch (light) {
        case RED:
            std::cout << "Stop!" << std::endl;
            break;
        case YELLOW:
            std::cout << "Slow down!" << std::endl;
            break;
        case GREEN:
            std::cout << "Go!" << std::endl;
            break;
    }
    
    // 传统枚举可以隐式转换为整数
    int lightValue = light;  // RED -> 0
    std::cout << "Light value: " << lightValue << std::endl;
    
    // 也可以从整数转换（但有风险）
    TrafficLight anotherLight = static_cast<TrafficLight>(1);  // YELLOW
}
```

### 2. 枚举类（Enum Class）- C++11

#### 2.1 基本定义
```cpp
// 枚举类 - 强类型枚举
enum class Color {
    RED,
    GREEN,
    BLUE
};

// 指定底层类型
enum class StatusCode : uint16_t {
    SUCCESS = 200,
    NOT_FOUND = 404,
    ERROR = 500
};

// 带值的枚举类
enum class FileMode : uint8_t {
    READ = 0b001,    // 1
    WRITE = 0b010,   // 2  
    EXECUTE = 0b100  // 4
};
```

#### 2.2 使用示例
```cpp
#include <iostream>
#include <cstdint>

enum class LogLevel {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    CRITICAL
};

void enum_class_demo() {
    LogLevel level = LogLevel::WARNING;
    
    // 必须使用作用域解析运算符
    switch (level) {
        case LogLevel::DEBUG:
            std::cout << "Debug message" << std::endl;
            break;
        case LogLevel::INFO:
            std::cout << "Info message" << std::endl;
            break;
        case LogLevel::WARNING:
            std::cout << "Warning message" << std::endl;
            break;
        case LogLevel::ERROR:
            std::cout << "Error message" << std::endl;
            break;
        case LogLevel::CRITICAL:
            std::cout << "Critical message" << std::endl;
            break;
    }
    
    // 枚举类不能隐式转换为整数
    // int levelValue = level;  // 错误！
    int levelValue = static_cast<int>(level);  // 必须显式转换
    std::cout << "Level value: " << levelValue << std::endl;
    
    // 也不能从整数隐式转换
    // LogLevel newLevel = 2;  // 错误！
    LogLevel newLevel = static_cast<LogLevel>(2);  // WARNING
}
```

### 3. 传统枚举 vs 枚举类

#### 3.1 关键区别对比

| 特性 | 传统枚举 | 枚举类 |
|------|----------|---------|
| **作用域** | 枚举值在外部作用域 | 枚举值在枚举内部作用域 |
| **类型安全** | 弱类型，可隐式转换 | 强类型，需显式转换 |
| **底层类型** | 实现定义 | 可指定 |
| **前向声明** | 需要知道大小 | 可前向声明 |

#### 3.2 作用域问题示例
```cpp
// 传统枚举的作用域问题
enum Color { RED, GREEN, BLUE };
enum TrafficLight { RED, YELLOW, GREEN };  // 错误！RED、GREEN重定义

// 枚举类解决作用域问题
enum class Color { RED, GREEN, BLUE };
enum class TrafficLight { RED, YELLOW, GREEN };  // 正确，不同作用域

void scope_demo() {
    Color color = Color::RED;
    TrafficLight light = TrafficLight::RED;  // 不会冲突
    
    // 传统枚举污染全局作用域
    // int red = RED;  // 如果使用传统枚举，这会编译
    
    // 枚举类需要显式作用域
    // int red = RED;  // 错误！
    int red = static_cast<int>(Color::RED);  // 正确但显式
}
```

### 4. 高级用法和特性

#### 4.1 指定底层类型
```cpp
#include <cstdint>

// 指定底层类型节省内存
enum class SmallEnum : uint8_t {
    VALUE1 = 1,
    VALUE2 = 2,
    VALUE3 = 3
};

enum class LargeEnum : uint64_t {
    BIG_VALUE1 = 10000000000,
    BIG_VALUE2 = 20000000000
};

void underlying_type_demo() {
    std::cout << "Size of SmallEnum: " << sizeof(SmallEnum) << " bytes" << std::endl;
    std::cout << "Size of LargeEnum: " << sizeof(LargeEnum) << " bytes" << std::endl;
    
    // 获取底层类型
    using SmallUnderlying = std::underlying_type_t<SmallEnum>;
    SmallUnderlying value = static_cast<SmallUnderlying>(SmallEnum::VALUE1);
}
```

#### 4.2 位标志枚举
```cpp
#include <iostream>

enum class Permissions : uint8_t {
    NONE = 0,
    READ = 1 << 0,    // 1
    WRITE = 1 << 1,   // 2
    EXECUTE = 1 << 2  // 4
};

// 重载位运算符用于枚举类
constexpr Permissions operator|(Permissions lhs, Permissions rhs) {
    return static_cast<Permissions>(
        static_cast<std::underlying_type_t<Permissions>>(lhs) |
        static_cast<std::underlying_type_t<Permissions>>(rhs)
    );
}

constexpr Permissions operator&(Permissions lhs, Permissions rhs) {
    return static_cast<Permissions>(
        static_cast<std::underlying_type_t<Permissions>>(lhs) &
        static_cast<std::underlying_type_t<Permissions>>(rhs)
    );
}

void bit_flags_demo() {
    Permissions userPerms = Permissions::READ | Permissions::WRITE;
    
    if ((userPerms & Permissions::READ) == Permissions::READ) {
        std::cout << "User has read permission" << std::endl;
    }
    
    if ((userPerms & Permissions::EXECUTE) != Permissions::EXECUTE) {
        std::cout << "User does not have execute permission" << std::endl;
    }
}
```

#### 4.3 枚举与switch的完备性检查
```cpp
enum class Direction {
    NORTH,
    SOUTH, 
    EAST,
    WEST
};

void handle_direction(Direction dir) {
    switch (dir) {
        case Direction::NORTH:
            std::cout << "Going north" << std::endl;
            break;
        case Direction::SOUTH:
            std::cout << "Going south" << std::endl;
            break;
        case Direction::EAST:
            std::cout << "Going east" << std::endl;
            break;
        case Direction::WEST:
            std::cout << "Going west" << std::endl;
            break;
        // 如果添加了新枚举值，编译器会警告switch不完备
    }
}

// C++17: 使用[[fallthrough]]
void enhanced_switch(Direction dir) {
    switch (dir) {
        case Direction::NORTH:
            std::cout << "Cold direction" << std::endl;
            [[fallthrough]];  // 明确告知编译器这是故意的
        case Direction::SOUTH:
            std::cout << "Polar direction" << std::endl;
            break;
        case Direction::EAST:
        case Direction::WEST:
            std::cout << "Lateral direction" << std::endl;
            break;
    }
}
```

### 5. 枚举在实际项目中的应用

#### 5.1 状态机实现
```cpp
enum class DownloadState {
    INITIALIZING,
    CONNECTING,
    DOWNLOADING,
    PAUSED,
    COMPLETED,
    FAILED
};

class FileDownloader {
private:
    DownloadState state = DownloadState::INITIALIZING;
    
public:
    void start() {
        if (state == DownloadState::INITIALIZING || state == DownloadState::PAUSED) {
            state = DownloadState::CONNECTING;
            // 连接逻辑...
            state = DownloadState::DOWNLOADING;
        }
    }
    
    void pause() {
        if (state == DownloadState::DOWNLOADING) {
            state = DownloadState::PAUSED;
        }
    }
    
    void resume() {
        if (state == DownloadState::PAUSED) {
            state = DownloadState::CONNECTING;
            // 重新连接逻辑...
            state = DownloadState::DOWNLOADING;
        }
    }
    
    DownloadState getState() const {
        return state;
    }
};
```

#### 5.2 配置选项
```cpp
enum class LogLevel {
    DEBUG,
    INFO,
    WARNING,
    ERROR
};

enum class OutputFormat {
    TEXT,
    JSON,
    XML
};

class Logger {
private:
    LogLevel level = LogLevel::INFO;
    OutputFormat format = OutputFormat::TEXT;
    
public:
    void setLevel(LogLevel newLevel) {
        level = newLevel;
    }
    
    void setFormat(OutputFormat newFormat) {
        format = newFormat;
    }
    
    void log(LogLevel msgLevel, const std::string& message) {
        if (msgLevel >= level) {  // 假设枚举值按严重程度递增
            // 根据format输出不同格式
            switch (format) {
                case OutputFormat::TEXT:
                    std::cout << "[TEXT] " << message << std::endl;
                    break;
                case OutputFormat::JSON:
                    std::cout << "{\"log\": \"" << message << "\"}" << std::endl;
                    break;
                case OutputFormat::XML:
                    std::cout << "<log>" << message << "</log>" << std::endl;
                    break;
            }
        }
    }
};
```

### 6. 最佳实践

#### 6.1 优先使用枚举类
```cpp
// 推荐：使用枚举类
enum class Color { RED, GREEN, BLUE };

// 不推荐：使用传统枚举（除非有特殊需求）
enum LegacyColor { LEGACY_RED, LEGACY_GREEN, LEGACY_BLUE };
```

#### 6.2 为枚举添加辅助函数
```cpp
#include <string>
#include <stdexcept>

enum class ErrorCode {
    SUCCESS = 0,
    FILE_NOT_FOUND = 1,
    PERMISSION_DENIED = 2,
    NETWORK_ERROR = 3
};

// 转换为字符串
std::string to_string(ErrorCode code) {
    switch (code) {
        case ErrorCode::SUCCESS: return "SUCCESS";
        case ErrorCode::FILE_NOT_FOUND: return "FILE_NOT_FOUND";
        case ErrorCode::PERMISSION_DENIED: return "PERMISSION_DENIED";
        case ErrorCode::NETWORK_ERROR: return "NETWORK_ERROR";
        default: throw std::invalid_argument("Unknown error code");
    }
}

// 从字符串转换
ErrorCode from_string(const std::string& str) {
    if (str == "SUCCESS") return ErrorCode::SUCCESS;
    if (str == "FILE_NOT_FOUND") return ErrorCode::FILE_NOT_FOUND;
    if (str == "PERMISSION_DENIED") return ErrorCode::PERMISSION_DENIED;
    if (str == "NETWORK_ERROR") return ErrorCode::NETWORK_ERROR;
    throw std::invalid_argument("Invalid error code string: " + str);
}
```

#### 6.3 遍历枚举值
```cpp
#include <array>

enum class Planet {
    MERCURY,
    VENUS,
    EARTH,
    MARS,
    JUPITER,
    SATURN,
    URANUS,
    NEPTUNE
};

constexpr std::array<Planet, 8> ALL_PLANETS = {
    Planet::MERCURY,
    Planet::VENUS,
    Planet::EARTH,
    Planet::MARS,
    Planet::JUPITER,
    Planet::SATURN,
    Planet::URANUS,
    Planet::NEPTUNE
};

void iterate_enum() {
    for (Planet planet : ALL_PLANETS) {
        std::cout << "Planet: " << static_cast<int>(planet) << std::endl;
    }
}
```

### 7. C++20 增强特性

#### 7.1 使用using enum（C++20）
```cpp
enum class Color { RED, GREEN, BLUE };

void cpp20_using_enum() {
    // C++20: 使用 using enum 引入枚举值到当前作用域
    {
        using enum Color;
        Color c = RED;  // 不需要 Color:: 前缀
    }
    
    // 传统方式仍然可用
    Color c = Color::RED;
}
```

### 总结

**枚举类型的核心要点：**

1. **传统枚举**：简单但容易污染命名空间，类型不安全
2. **枚举类**：类型安全，作用域明确，是现代C++的推荐方式
3. **底层类型**：可以指定以控制内存使用和取值范围
4. **类型安全**：枚举类防止了意外的隐式类型转换
5. **实用技巧**：结合位运算、字符串转换等增强实用性

**选择指南：**
- 新代码优先使用`enum class`
- 需要与C代码交互时考虑传统枚举
- 需要位标志操作时指定底层类型并重载运算符
- 为常用枚举提供字符串转换函数

枚举类型让代码更加清晰、安全，是现代C++中不可或缺的特性之一。


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
答：见2011简答题第5题。
## 4. 为什么说“继承是面向对象的主要特征之一”？请简要说明。
答：见2011简答题第3题。
## 5. 如何声明和使用虚函数？说明它在多态性中的作用和意义。
答：见2011简答题第4题。

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