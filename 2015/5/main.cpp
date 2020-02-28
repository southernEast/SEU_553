#include <iostream>
#include "Date.h"
#include "Teacher.h"
using namespace std;

int main() {
    Teacher t1(123, "Tom", "male", Date(1960, 10, 10), Date(1990, 5, 3));
    Teacher t2(134, "Jack", "male", Date(1965,10, 10), Date(1995, 5, 3));
    Teacher t3(211, "Lucy", "female", Date(1955, 10, 10),Date(1982, 5, 3));
    Teacher t4(246, "Wendy", "female", Date(1955, 7, 9), Date(1980, 7, 31));
    Teacher* t[4] = { &t1, &t2, &t3, &t4 };

    cout << "Teachers need retire:\n";
    for (int i = 0; i < 4; ++i) {
        if (t[i]->isRetire(2016))
            cout << t[i]->getName() << endl;
    }
    cout << "\nTeachers need keepHire:\n";
    for (int i = 0; i < 4; ++i) {
        if (t[i]->isRetire(2016) && t[i]->isKeepHire(2016))
            cout << t[i]->getName() << endl;
    }

	return 0;
}