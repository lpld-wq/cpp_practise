#include <iostream>
#include "service.h"

int main()
{
	int x{ getFirstNumber() };
	char op{ getSymbol() };
	int y{ getSecondNumber() };
	int result{ getResult(x, op, y) };
	std::cout << "计算结果为: " << result << "\n";

	return 0;
}
