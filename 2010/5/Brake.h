#ifndef _BRAKE_H_
#define _BRAKE_H_

class Brake {
public:
	Brake(std::string str = "") : name(str) {}
	~Brake() {}
	std::string getName() const { return name; }
	void setName(std::string str) { name = str; }
private:
	std::string name;
};

#endif // !_BRAKE_H_

