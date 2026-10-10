#include <iostream>
#include "add.h"
//#include "add.h" //1>D:\cpp_practise\2.9~2.11练习\2.9~2.11_practise.cpp(6,37): error C2568: '<<': 无法解析函数重载
int main()
{
	std::cout << "add(10,20) = " << add(10, 20) << "\n";
	return 0;
}