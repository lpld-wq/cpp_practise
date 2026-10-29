#include <iostream>

template <typename T>
struct Triad
{
	T first{};
	T second{};
	T third{};
};

template <typename T>
void print(const Triad<T>& t_x)
{
	std::cout << '[' << t_x.first << ", " << t_x.second << ", " << t_x.third << "]\n";
}



int main()
{
	Triad t1{ 1, 2, 3 }; // 注意：使用 CTAD 推导模板实参
	print(t1);

	Triad t2{ 1.2, 3.4, 5.6 }; // 注意：使用 CTAD 推导模板实参
	print(t2);

	return 0;
}