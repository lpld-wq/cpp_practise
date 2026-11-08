#include <iostream>
#include <string_view>
#include <vector>

template <typename T>
bool isValueInArray(const std::vector<T>& arr, const T& value)
{
	for (const auto& a : arr)
	{
		if (a == value)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	std::vector<std::string_view> names{ "Alex" , "Caroline" ,"Betty" , "Emily" , "Fred" , "Greg" , "Holly" , "Dave" };
	std::string getName{};
	std::cout << "Enter a name: ";
	std::cin >> getName;



	bool found{ isValueInArray<std::string_view>(names , getName)};
	
	if (found)
	{
		std::cout << getName << " was found.\n";
	}
	else
	{
		std::cout << getName << " was not found.\n";
	}

	return 0;
}
