#ifndef _DATE_H_
#define _DATE_H_

class Date {
public:
	Date(unsigned y = 2000, unsigned m = 1, unsigned d = 1);
	void setDate(unsigned y, unsigned m, unsigned d);
	void display() const;
	unsigned getYear() const;
	unsigned getMonth() const;
	unsigned getDay() const;

private:
	int isLeapyear() const;
	unsigned year;
	unsigned month;
	unsigned day;
};

#endif // !_DATE_H_

