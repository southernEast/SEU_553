#ifndef _STEERINGWHEEL_H_
#define _STEERINGWHEEL_H_

class SteeringWheel {
public:
	SteeringWheel(std::string str = "") : name(str) {}
	~SteeringWheel() {}
	std::string getName() const { return name; }
	void setName(std::string str) { name = str; }
private:
	std::string name;
};

#endif // !_STEERINGWHEEL_H_

