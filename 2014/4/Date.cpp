#include "Date.h"
#include <iostream>
using namespace std;

Date::Date(unsigned y, unsigned m, unsigned d) {
	setDate(y, m, d);
}
void Date::setDate(unsigned y, unsigned m, unsigned d) {
	static unsigned days[2][13] = { 
		{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },		// 每个月的天数
		{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }		// 如果是闰年则第一维取1
	};
	if (y < 2900)
		year = y;
	else {
		cerr << "The year is out of range.";
		exit(EXIT_FAILURE);
	}

	if (m >= 1 && m <= 12)
		month = m;
	else {
		cerr << "The month is out of range.";
		exit(EXIT_FAILURE);
	}
	
	if (d >= 1 && d <= days[isLeapyear()][month])
		day = d;
	else {
		cerr << "The day is out of range.";
		exit(EXIT_FAILURE);
	}
}
int Date::isLeapyear() const {
	return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
}
void Date::display() const {
	cout << year << "." << month << "." << day;
}
unsigned Date::getYear() const {
	return year;
}
unsigned Date::getMonth() const {
	return month;
}
unsigned Date::getDay() const {
	return day;
}