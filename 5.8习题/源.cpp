#include <iostream>
#include <string>
#include <iterator>

int main()
{
	std::cout << "Enter your full name: ";
	std::string name{};
	std::getline(std::cin >> std::ws, name);
	auto len_name{ std::ssize(name) };

	std::cout << "Enter your age: ";
	int age{};
	std::cin >> age;

	std::cout << "Your age + length of name is: " << age + len_name << "\n";
	return 0;
}
