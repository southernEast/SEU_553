#include <iostream>
#include "Employee.h"
#include "Date.h"
using namespace std;

int main() {
	Date birth(1970, 11, 23);
	Date hire(1995, 3, 5);
	Date limit(2029, 9, 5);

	Employee e1( "维尼", "233666", "12323", birth, hire, limit, 10000);
	e1.display();

	e1.extentHireDay(1);
	e1.display();
	e1.extentHireDay(2);
	e1.display();

	return 0;
}