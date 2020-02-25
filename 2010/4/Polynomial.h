#ifndef _POLYNOMIAL_H_
#define _POLYNOMIAL_H_

#include <iostream>
#include <vector>

class Polynomial {
	friend std::ostream& operator<<(std::ostream& output, const Polynomial& p);
public:
	Polynomial(const std::vector<double>& coe);
	~Polynomial() {};
	Polynomial(const Polynomial& p);
	void setCoeficient(size_t pos, double val);
	double getCoeficient(size_t pos);
	Polynomial& operator=(const Polynomial& p);
	Polynomial operator+(const Polynomial& p);
private:
	std::vector<double> coeficient;
};

#endif // !_POLYNOMIAL_H_

