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
	std::cout << "-------------------\n";
}

void printBanner()
{
	printLine();
	std::cout << "函数实验台\n";
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
	std::cout << "函数内n=" << n <<"\n";

}

int main() 
{
	printBanner();
	std::cout << doubled(5) << "\n";
	int y{doubled(5)};
	std::cout << y << "\n";
	std::cout << doubledThenAddTen(5) << "\n";
	showSum(2 * 3, 5 + 1);
	std::cout << multiply(3, 4) << "\n";
	int x{7};
	tryChange(x);
	std::cout << x << "\n";
	doubled(5);
}