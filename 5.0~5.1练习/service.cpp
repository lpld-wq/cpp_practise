#include <iostream>
#include "service.h"

//从用户手中获取半径
double kGetRadius()
{
	double radius{};
	std::cout << "Please enter a radius: ";
	std::cin >> radius;
	return radius;
}

//进行计算
double kGetResult(double radius)
{
	double result{};
	result = radius * radius * kPi;
	std::cout << "\nThe area of the circle is : " << result;
	return result;
}