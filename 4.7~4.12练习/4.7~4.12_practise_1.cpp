#include <iostream>
#include "service.h"

int main()
{
	double x{ getFirstNumber()};
	char op{ getSymbol() };
	double y{ getSecondNumber() };
	double result{ getResult(x, op, y) };
	std::cout << "计算结果为: " << result <<"\n";

}
