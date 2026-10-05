#include <iostream>

int doubled(int n)
{
	return n * 2;
}

int addTen(int n)
{
	return n + 10;
}

int doubledThenAddTen(int n)
{
	n = addTen(doubled(n));
	return n;
}

void printLine()
{
	std::cout << "--------------------\n";
}

void printBanner()
{
	printLine();
	std::cout << "===函数实验台===\n";
	printLine();
}

void showSum(int a, int b)
{
	std::cout << a + b << "\n";
}

int multiply(int a, int b)
{
	return a * b;
}

void tryChange(int n)
{
	n = 100;
	std::cout << "函数内 n = " << n <<"\n";

}

int main() 
{
	printBanner();
	std::cout <<"T3 doubled(5) =" << doubled(5) << "\n";
	int y{doubled(5)};
	std::cout << "T4 y = " << y << "\n";
	std::cout << "T5 doubledThenAddTen(5) = " << doubledThenAddTen(5) << "\n";
	std::cout << "T6 ";
	showSum(2 * 3, 5 + 1);
	std::cout << "T7 multiply(3, 4) = " << multiply(3, 4) << "\n";
	int x{7};
	std::cout << "T8 ";
	tryChange(x);
	std::cout <<"T9 " << "函数外x = " << x << "\n";
	doubled(5);
	return 0;
	//std::cout << printLine();   报错--没有与这些操作数匹配的 "<<" 运算符
	//doubled(5, 6);函数调用中的参数太多
}