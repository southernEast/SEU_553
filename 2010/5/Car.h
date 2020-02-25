#ifndef _CAR_H_
#define _CAR_H_

#include "Vehicle.h"
#include "Brake.h"
#include "SteeringWheel.h"
#include <iostream>

class Car : public Vehicle{	// 车辆和汽车为“是一个”的关系，故使用继承
public:
	Car(std::string brakeName, std::string steeringWheelName, int speed)
		: Vehicle(speed) {
		b.setName(brakeName);
		s.setName(steeringWheelName);
	}
	~Car() {}
	void showInfo() const {
		std::cout << "Brake Name: " << b.getName() << std::endl;
		std::cout << "Steering Wheel: " << s.getName() << std::endl;
		std::cout << "Speed: " << getSpeed() << std::endl;
	}
private:
	Brake b;			// 刹车系统和方向盘为“有一个”的关系，故使用组合
	SteeringWheel s;
};

#endif // !_CAR_H_

