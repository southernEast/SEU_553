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
bool Teacher::isRetire(int year) const {
	if (sex == "male")				
		return (year - birthday.getYear() >= 55);		// 男性大于等于55岁退休
	else
		return (year - birthday.getYear() >= 60);		// 女性大于等于60岁退休
}
bool Teacher::isKeepHire(int year) const {
	if (isRetire(year) && sex == "female") {			// 如果满足退休年龄且是女性才需要合格第一条件
		return (year - hireDate.getYear() < 35);		// 判断工龄是否达到35岁，未达到则续聘
	}
	else
		return false;
}
void Teacher::printInfo() const {
	cout << "number: " << number << endl
		<< "name: " << name << endl
		<< "sex: " << sex << endl;
	cout << "birthday: ";
	birthday.printInfo();
	cout << endl;
	cout << "hire date: ";
	hireDate.printInfo();
	cout << endl;
}
string Teacher::getName() const {
	return name;
}
