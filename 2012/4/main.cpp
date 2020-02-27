#include <iostream>
#include "Name.h"
#include "Person.h"
using namespace std;

int main() {
	Name n("Van", "Dark", "holme");
	Person p(n, "USA", "Male");

	n.printName();
	cout << endl;
	p.printName();
	cout << endl;
	p.printNationality();
	
	return 0;
}