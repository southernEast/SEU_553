#ifndef _NAME_H_
#define _NAME_H_

#include <string>
#include <iostream>

class Name {
public:
	Name(std::string f, std::string m, std::string l)
		: first(f), middle(m), last(l) {}
	void printName() const {
		std::cout << first << " " << middle << " " << last;
	}
private:
	std::string first;
	std::string middle;
	std::string last;
};

#endif // !_NAME_H_

