#include <iostream>

// 在这里编写你的 add 函数模板
template <typename T>
T add(T a, T b)
{
	return a + b;
}

template <typename T , typename U>
auto mult(T a, U b)
{
	return a * b;
}

template <typename T, typename U>
auto sub(T a, U b)
{
	return a - b;
}

int main()
{
	std::cout << add(2, 3) << '\n';
	std::cout << add(1.2, 3.4) << '\n';

	std::cout << mult(2, 3) << '\n';
	std::cout << mult(1.2, 3) << '\n';

	std::cout << sub(3, 2) << '\n';
	std::cout << sub(3.5, 2) << '\n';
	std::cout << sub(4, 1.5) << '\n';
	return 0;
}