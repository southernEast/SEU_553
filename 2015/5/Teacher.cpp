#include "Teacher.h"
#include <string>
#include <iostream>
using namespace std;

Teacher::Teacher(int number, string name, string sex, Date birthday, Date hireDate) {
	this->number = number;
	this->name = name;
	this->sex = sex;
	this->birthday = birthday;
	this->hireDate = hireDate;
}
Teacher::Teacher(const Teacher& t) {
	number = t.number;
	name = t.name;
	birthday = t.birthday;
	hireDate = t.hireDate;
}

// 以下两个函数有第二种设计方法，即不返回bool类型，而直接在函数内
// 将需要输出的信息进行输出
bool Teacher::isRetire(int year) const {
	if (sex == "male")				
		return (year - birthday.getYear() >= 55);		// 男性大于等于55岁退休
	else
		return (year - birthday.getYear() >= 60);		// 女性大于等于60岁退休
}

// 此函数只用于在满足isRetire的条件下的进一步判断
bool Teacher::isKeepHire(int year) const {
	if (isRetire(year) && sex == "female") {			// 如果满足退休年龄且是女性才需要合格第一条件
		return (year - hireDate.getYear() < 35);		// 判断工龄是否达到35岁，未达到则续聘
	}												
	else
		return false;
}
void Teacher::printInfo() const {
	cout << "name:" << name << endl
		<< "number:" << number << endl << endl;
}
string Teacher::getName() const {
	return name;
}
