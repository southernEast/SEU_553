#ifndef _PERSON_H_
#define _PERSON_H_

#include "Name.h"
#include <iostream>

class Person {
public:
	Person(Name n, std::string nation, std::string s)
		: name(n), nationality(nation), sex(s) {}			// Name复制无特殊要求，使用默认复制构造函数
	void printName() const {
		name.printName();
	}
	void printNationality() const {
		std::cout << nationality;
	}
private:
	Name name;
	std::string nationality;
	std::string sex;
};

#endif // !_PERSON_H_

