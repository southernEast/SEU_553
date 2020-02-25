#ifndef _VEHICLE_H_
#define _VEHICLE_H_

class Vehicle {
public:
	Vehicle(int speed = 0) : speedNum(speed) {}
	~Vehicle() {}
	int getSpeed() const { return speedNum; }
	void setSpeed(int speed) { speedNum = speed; }
private:
	int speedNum;
};

#endif // !_VEHICLE_H_

