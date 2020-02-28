#include "Date.h"
#include <iostream>
using namespace std;

Date::Date(int y, int m, int d) {
	setYear(y);
	setMonth(m);
	setDay(d);
}
Date::Date(const Date& d) {
	setYear(d.year);
	setMonth(d.month);
	setDay(d.day);
}
void Date::setYear(int y) {
	if (y >= 1900)
		year = y;
	else 
		throw(out_of_range("The year is out of range"));
}
void Date::setMonth(int m) {
	if (m >= 1 && m <= 12)
		month = m;
	else 
		throw(out_of_range("The month is out of range"));
}
void Date::setDay(int d) {
	if (d >= 1 && d <= days[isLeapyear()][month])
		day = d;
	else
		throw(out_of_range("The day is out of range"));
}
int Date::getYear() const {
	return year;
}
int Date::getMonth() const {
	return month;
}
int Date::getDay() const {
	return day;
}
int Date::isLeapyear() const {		// ÅÐ¶ÏÆ½ÄêÈòÄê
	return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0) ? 1 : 0);
}
Date& Date::operator= (const Date& d) {
	setYear(d.year);
	setMonth(d.month);
	setDay(d.day);
	return *this;
}
void Date::printInfo() const {
	cout << year << "." << month << "." << day;
}