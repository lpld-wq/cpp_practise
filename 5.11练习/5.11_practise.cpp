#include <iostream>
#include <string>
#include <string_view>

std::string kGetName(int token)
{
	std::cout << "Enter the name of person #" << token << ": ";
	std::string name{};
	std::getline(std::cin >> std::ws, name);
	return name;
}

int kGetAge(std::string_view name)
{
	std::cout << "Enter the age of " << name << ": ";
	int age{};
	std::cin >> age;
	return age;
}

bool kCompare(int age_1, int age_2)
{
	return (age_1 > age_2) ? true : false;
}

int main()
{
	int token{1};
	std::string name_1{ kGetName(token) };
	 int age_1{ kGetAge(name_1) };

	token += 1;

	std::string name_2{ kGetName(token) };
	int age_2 {kGetAge(name_2) };
	if (kCompare(age_1, age_2))
		std::cout << name_1 << " (age " << age_1 << ") is older than " << name_2 << " (age " << age_2 << ")." << "\n";
	else
		std::cout << name_2 << " (age " << age_2 << ") is older than " << name_1 << " (age " << age_1 << ")." << "\n";
}
