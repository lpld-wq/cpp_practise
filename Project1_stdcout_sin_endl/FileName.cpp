#include<iostream>

int main()
{
	std::cout << "Enter two numbers separated by a space: ";

	int x{ 0 };
	int y{ 0 };
	std::cin >> x >> y;

	std::cout << "You entered " << x << " and " << y;
	return 0;
}
