#ifndef _DATE_H_
#define _DATE_H_

class Date {
public:
	Date(int y = 1900, int m = 1, int d = 1);
	Date(const Date& d);
	void setYear(int y);
	void setMonth(int m);
	void setDay(int d);
	int getYear() const;
	int getMonth() const;
	int getDay() const;
	Date& operator= (const Date& d);
	void printInfo() const;

private:
	int isLeapyear() const;
	const int days[2][13] = {				// 闰年和平年对应的每个月的天数
		{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
		{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
	};
	int year;
	int month;
	int day;
};

#endif // !_DATE_H_

