#include <iostream>
#include <iomanip>

int main()
{
	std::cout << std::left;
	std::cout << std::setw(16) << "bool = " << sizeof(bool) << "\n";
	std::cout << std::setw(16) << "char = " << sizeof(char) << "\n";
	std::cout << std::setw(16) << "short = " << sizeof(short) << "\n";
	std::cout << std::setw(16) << "int = " << sizeof(int) << "\n";
	std::cout << std::setw(16) << "long = " << sizeof(long) << "\n";
	std::cout << std::setw(16) << "long long = " << sizeof(long long) << "\n";
	std::cout << std::setw(16) << "float = " << sizeof(float) << "\n";
	std::cout << std::setw(16) << "double = " << sizeof(double) << "\n";
	std::cout << std::setw(16) << "long double = " << sizeof(long double) << "\n";
	//std::cout << std::setw(16) << "void = " << sizeof(void) << "\n"; error C2070: 'void': 格式错误的 sizeof 操作数
	int x{};
	std::cout << std::setw(16) << "x = " << sizeof(x) << "\n";

	return 0;
}