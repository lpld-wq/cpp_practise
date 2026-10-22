#include <iostream>

int sumTo(int aimNum)
{
	int sum{ 0 };
	for (int i = 1; i <= aimNum; i++)
	{
		sum += i;
	}
	return sum;
}

void fizzbuzz(int aimNum)
{
	for (int i = 1; i <= aimNum; ++i)
	{
		bool printed{ false };
		if (i % 3 == 0)
		{
			std::cout << "fizz";
			printed = true;
		}
		if (i % 5 == 0)
		{
			std::cout << "buzz";
			printed = true;
		}
		if (i % 7 == 0)
		{
			std::cout << "pop";
			printed = true;
		}
		if (!printed)
			std::cout << i;
		std::cout << "\n";
	}
}

int main()
{
	for (int i = 0; i <= 20; i += 2)
	{
		std::cout << i << "\n";
	}
	
	int aimNum{ 0 };
	std::cout << "输入累加目标数字: ";
	std::cin >> aimNum;
	int sum{ sumTo(aimNum)};
	std::cout << "累加目标值为: " << sum << "\n";

	fizzbuzz(aimNum);
	return 0;
}