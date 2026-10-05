#include<iostream>
int main()
{
	int x{};
	std::cout << "Enter an integer:";
	std::cin >> x;
	std::cout << "Double that number is:" << x * 2;
	return 0;
}