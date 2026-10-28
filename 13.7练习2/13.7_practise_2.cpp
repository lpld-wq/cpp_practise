#include <iostream>

struct Fraction
{
	int numerator{ 0 };
	int denominator{ 1 };
};

Fraction kGetFraction()
{
	Fraction temp{};
	std::cout << "Enter a value for the numerator:";
	std::cin >> temp.numerator;
	std::cout << "Enter a value for the denominator :";
	std::cin >> temp.denominator;

	return temp;
}

constexpr Fraction multiply(const Fraction& f1, const Fraction& f2)
{
	return { f1.numerator * f2.numerator , f1.denominator * f2.denominator };
}

void printFraction(const Fraction& f)
{
	std::cout << f.numerator << "/" << f.denominator << "\n";
}

int main()
{
	Fraction f1{ kGetFraction() };
	Fraction f2{ kGetFraction() };
	std::cout << "Your fractions multiplied together: ";
	printFraction (multiply(f1, f2));

	return 0;
}