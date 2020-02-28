#ifndef _TEACHER_H_
#define _TEACHER_H_

#include "Date.h"
#include <string>

class Teacher {
public:
	Teacher(int number = 0, std::string name = "", std::string sex = "male",
		Date birthday = Date(1900, 1, 1), Date hireDate = Date(2000, 1, 1));
	Teacher(const Teacher& t);
	bool isRetire(int year) const;
	bool isKeepHire(int year) const;
	void printInfo() const;
	std::string getName() const;

private:
	int number;
	std::string name;
	std::string sex;
	Date birthday;
	Date hireDate;
};

#endif // !_TEACHER_H_

