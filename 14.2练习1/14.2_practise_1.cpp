#include <iostream>

// 在这里给出 IntPair 的定义和 print() 成员函数
struct IntPair
{
	int num_1 {};
	int num_2 {};
	void print()
	{
		std::cout <<"Pair(" << num_1 << ", " << num_2 << ")" << "\n";
	}
};

int main()
{
	IntPair p1{ 1, 2 };
	IntPair p2{ 3, 4 };

	std::cout << "p1: ";
	p1.print();

	std::cout << "p2: ";
	p2.print();

	return 0;
}