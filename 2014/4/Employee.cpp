#include "Date.h"
#include "Employee.h"
#include <string>
#include <iostream>
using namespace std;

Employee::Employee(string name, string number, string idNumber,
	Date birthday, Date hireDay, Date deadline, int salary) :
	name(name), number(number), idNumber(idNumber), birthday(birthday),
	hireDay(hireDay), deadline(deadline), salary(salary) {}
void Employee::setBirthDay(Date d) {
	birthday = d;
}
void Employee::setDeadline(Date d) {
	deadline = d;
}
void Employee::setSalary(int s) {
	salary = s;
}
void Employee::extentHireDay(int y) {
	if (deadline.getYear() + y - birthday.getYear() > 60)			
		cerr << "Can't hire! This employee will be over 60 years old!" << endl;
	else {
		deadline.setDate(deadline.getYear() + y, deadline.getMonth(),
			deadline.getDay());
		cout << "Extent successful!" << endl;
	}
}
void Employee::display() const {
	cout << "name: " << name << endl
		<< "number: " << number << endl
		<< "id number: " << idNumber << endl
		<< "salary: " << salary << endl;
	cout << "birthday: ";
	birthday.display();
	cout << endl;
	cout << "hireday: ";
	hireDay.display();
	cout << endl;
	cout << "deadline: ";
	deadline.display();
	cout << endl << endl;
}