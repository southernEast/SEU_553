/***** string类 *****/

// 构造函数
string(const char* s);		// 使用c语言形式的字符串s初始化string
string(int n, char c);		// 使用n个字符c初始化string
string s;					// 默认构造函数
string s = "Hello World!";	// 调用复制构造函数初始化

// 部分特性
size_t capacity() const;	// 当前容量
size_t max_size() const;	// 当前string对象中可以存放的最大字符串长度
size_t size() const;		// 当前字符串大小
size_t length() const;		// 当前字符串的长度
bool empty() const;			// 当前字符串是否为空
void resize(size_t n, char c = '\000');	// 把当前字符串的大小设置为n，用c填充多出来的部分

// 赋值操作
string& operator=(const string& s);	// 把字符串s赋值给当前字符串
string& assign(const char* s);		// 用c语言形式的字符串s赋值
string& assign(const char* s, size_t n);	// 用c语言形式的字符串s前n个字符赋值
string& assign(const string& s);	// 将字符串s赋值给当前字符串
string& assign(size_t n, char c);	// 用n个字符c赋值给字符串
string& assign(const string& s, int start, int n);	// 将字符串s中从start开始的n个字符赋值给当前字符串
string& assign(const_iterator first, const_iterator last);	// 把first和last迭代器之间的部分赋值给当前字符串

// 比较操作 大于返回1，小于返回-1，等于返回0
int compare(const string& s) const;	// 与string比较
int compare(int pos, int n, const char* s) const;	// 与c语言形式的字符串s从pos开始的n个字符比较
int compare(int pos1, int n1, const string& s, int pos2, int n2) const;	
													// 当前string的字符串从pos1开始的n1个字符与s的pos2开始的n2个字符比较


// 取子串
string substr(int pos = 0, int n = npos) const;		// 返回从pos开始的n个字符组成的字符串，默认取到当前字符串的最后

// 交换
void swap(string& s2);		// 交换当前字符串与s2的值

// 查找
size_t find(char c, int pos = 0) const;			// 从pos开始查找字符c在当前字符串中的位置
size_t find(const char* s, int pos = 0) const;	// 从pos开始查找字符串s在当前字符串中的位置
size_t find(const char* s, int pos, int n) const;	// 从pos开始查找字符串s前n个字符在当前字符串中的位置
size_t find(const string& s, int pos = 0) const;	// 从pos开始查找字符串s在当前字符串中的位置

// 替换
string& replace(int p, int n, const char* s);	// 删除从p开始的n个字符，然后在p处插入串s
string& replace(int p, int n, const char* s, int n);	// 删除从p开始的n个字符，然后在p处插入字符串s的前n个字符
string& replace(int p, int n, const string& s);	// 删除从p开始的n个字符，然后在p处插入串s
string& replace(int p, int n, const string& s, int pos, int n1);	// 删除...然后在p处插入串s中pos开始的n1个字符
string& replace(int p, int n, int n1, char c);	// 删除...然后在p处插入n1个字符c
string& raplace(iterator first0, iterator last0, const char* s);	// 把[first0,last0)之间的部分替换为s
string& replace(iterator first0, iterator last0, const char* s, int n);	// ...替换为s的前n个字符
string& replace(iterator first0, iterator last0, const string& s);	// ...替换为s
string& replace(iterator first0, iterator last0, int n, char c);	// ...替换为n个字符c
string& replace(iterator first0, iterator last0, const_iterator first1, const_iterator last1);
																	// [first0,last0)替换为[first1,last0)
// 删除
iterator erase(iterator first, iterator last);	// 删除[first,last)返回删除后迭代器的位置
iterator erase(iterator it);		// 删除it指向的字符，并返回删除后迭代器的位置
string& erase(int pos = 0, int n = npos);		//  从pos开始删除n个字符，返回修改后的字符串，默认删除所有

// 与c风格字符串的转换
size_t copy(char* s, size_t count, size_t pos);	// 在当前string字符串中pos位置至多复制count个字符到s所指向的内存中
												// 注意默认可能不会复制'\0'
/***** string类 *****/


/***** c语言cstring中的部分函数 *****/
char* strtok(char* str, const char* delim);		// 在str中按照delim分割字符串，如果没有可以分割的字符串则返回nullptr
// 后续继续使用该函数分割需要将str设置为nullptr，同时，strtok会修改原来的字符串，将其中的delim替换为'\0'