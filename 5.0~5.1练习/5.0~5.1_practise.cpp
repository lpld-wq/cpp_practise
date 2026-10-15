#include <iostream>
#include "service.h"

//输入半径计算面积
int main()
{
	double radius{};
	radius = kGetRadius();
	kGetResult(radius);
	
	return 0;
}