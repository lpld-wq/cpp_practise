#include <iostream>

// 在这里给出 IntPair 的定义和各个成员函数
struct IntPair
{
	int num_1{};
	int num_2{};
	void print()
	{
		std::cout << "Pair(" << num_1 << ", " << num_2 << ")\n";
	}
	bool isEqual(const IntPair& x)
	{
		if (num_1 == x.num_1 && num_2 == x.num_2)
			return true;
		return false;
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

	std::cout << "p1 and p1 " << (p1.isEqual(p1) ? "are equal\n" : "are not equal\n");
	std::cout << "p1 and p2 " << (p1.isEqual(p2) ? "are equal\n" : "are not equal\n");

	return 0;
}
