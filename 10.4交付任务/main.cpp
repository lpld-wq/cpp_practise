#include <iostream>

int main()
{
	std::cout << "请输入身高(m):";
	double height{};
	std::cin >> height;
	std::cout << "\n请输入体重(kg):";
	double weight{};
	std::cin >> weight;
	std::cout << "\n您的BMI指数为" << weight / (height * height);
	return 0;
}