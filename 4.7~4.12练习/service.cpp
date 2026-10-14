#include <iostream>
#include "service.h"

double getFirstNumber()
{
	double x{ 0 };
	std::cout << "请输入第一个数字:";
	std::cin >> x;
	return x;
}
 
char getSymbol()
{ 
	std::cout << "\n请输入运算符(仅限+,-,*,/):";
	char op{};
	std::cin >> op;
	return op;
}

double getSecondNumber()
{
	double x{ 0 };
	std::cout << "\n请输入第二个数字:";
	std::cin >> x;
	return x;
}

double getResult(double x, char op, double y)
{
    if (op == '+')
    {
        return x + y;
    }
    else if (op == '-')
    {
        return x - y;
    }
    else if (op == '*')
    {
        return x * y;
    }
    else if (op == '/')
    {
        if (y == 0)
        {
            std::cout << "除数不能为 0\n";
            return 0;
        }
        return x / y;
    }
    else
    {
        std::cout << "不支持的运算符\n";
        return 0;
    }
}
