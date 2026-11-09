#include <iostream>
#include <vector>
#include <cassert>

namespace Items
{
	enum Type
	{
		health_potion,
		torch,
		arrow,
		max_items
	};
}

std::string_view getItemNameSingular(Items::Type type)
{
	switch (type)
	{
	case Items::health_potion: return "health_potion";
	case Items::torch:         return "torch";
	case Items::arrow:         return "arrow";
	
	default:                   return "???";
	}
}

std::string_view getItemNamePlural(Items::Type type)
{
	switch (type)
	{
	case Items::health_potion: return "health_potions";
	case Items::torch:         return "torches";
	case Items::arrow:         return "arrows";

	default:                   return "???";
	}
}
template <typename T>
constexpr std::size_t toUZ(T value)
{
	static_assert(std::is_integral<T>() || std::is_enum<T>());

	return static_cast<std::size_t>(value);
}


void printInventoryItem(const std::vector<int>& inventory , Items::Type type)
{
		if (inventory[toUZ(type)] != 1)
		{
			std::cout << "You have " << inventory[toUZ(type)] << " " << getItemNamePlural(type) << "\n";
		}
		else
		{
			std::cout << "You have " << inventory[toUZ(type)] << " " << getItemNameSingular(type) << "\n";
		}
}

template <typename T>
std::pair<std::size_t, std::size_t> findMinMaxIndices(const std::vector<T>& arr)
{
	std::size_t minIndex{ 0 };
	std::size_t maxIndex{ 0 };

	for (std::size_t index{ 1 }; index < arr.size(); index++)
	{
		if (arr[index] > arr[maxIndex])
		{
			maxIndex = index;
		}
		if (arr[index] < arr[minIndex])
		{
			minIndex = index;
		}
	}

	return { maxIndex , minIndex };
}

template <typename T>
void printArray(const std::vector<T>& arr)
{
	bool comma{ false };
	std::cout << "With array ( ";
	for (const auto& e : arr)
	{
		if (comma)
		{
			std::cout << " , ";
		}
		std::cout << e;
		comma = true;
	}
	std::cout << " ):\n";
}

int main() 
{
	/*
	std::vector evens{ 2, 4, 6, 8, 10, 12 };
	const std::vector d{ 1.2 , 3.4 , 5.6 , 7.8 };

	using namespace std::literals::string_view_literals;
	const std::vector names{ "Alex"sv, "Brad"sv, "Charles"sv, "Dave"sv };

	std::vector v{ 12 };

	std::vector<int> a( 12 );*/

	// 练习一

	std::vector inventory{ 1, 5, 10 };
	assert(std::size(inventory) == Items::max_items);

	for (int i{ 0 }; i < Items::max_items ; i++)
	{
		auto item{ static_cast<Items::Type>(i) };
		printInventoryItem(inventory, item);
	}


	std::vector v1{ 3, 8, 2, 5, 7, 8, 3 };
	printArray(v1);

	auto m1{ findMinMaxIndices(v1) };
	std::cout << "The max element has index " << m1.first << " and value " << v1[m1.first] << '\n';
	std::cout << "The min element has index " << m1.second << " and value " << v1[m1.second] << '\n';

	std::cout << '\n';

	std::vector v2{ 5.5, 2.7, 3.3, 7.6, 1.2, 8.8, 6.6 };
	printArray(v2);

	auto m2{ findMinMaxIndices(v2) };
	std::cout << "The max element has index " << m2.first << " and value " << v2[m2.first] << '\n';
	std::cout << "The min element has index " << m2.second << " and value " << v2[m2.second] << '\n';

	std::vector<int> v3{};
	std::cout << "Enter numbers to add (use -1 to stop): ";

	while (true)
	{
		int input{};
		std::cin >> input;
		if (input == -1)
		{
			break;
		}

		if (!std::cin) // 如果上一次提取失败
		{
			std::cin.clear(); // 让流回到「正常」工作模式
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 并移除错误的输入
			continue;
		}

		v3.push_back(input);
	}

	if (v3.size() == 0)
	{
		std::cout << "The array has no elements\n";
	}
	else
	{
		printArray(v3);

		auto m3{ findMinMaxIndices(v3)};
		std::cout << "The max element has index " << m3.first << " and value " << v3[m3.first] << '\n';
		std::cout << "The min element has index " << m3.second << " and value " << v3[m3.second] << '\n';
	}

	return 0;
}