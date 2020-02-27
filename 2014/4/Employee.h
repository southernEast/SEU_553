#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

#include "Date.h"
#include <string>

class Employee {
public:
	Employee(std::string name, std::string number, std::string idNumber,
		Date birthday, Date hireDay, Date deadline, int salary);
	void setBirthDay(Date d);
	void setDeadline(Date d);
	void setSalary(int s);
	void extentHireDay(int y);
	void display() const;
private:
	std::string name;		// 姓名
	std::string number;		// 工号
	std::string idNumber;	// 身份证号
	Date birthday;		// 出生日期
	Date hireDay;		// 受聘日期
	Date deadline;		// 聘用年限
	int salary;			// 月薪
};

#endif // !_EMPLOYEE_H_