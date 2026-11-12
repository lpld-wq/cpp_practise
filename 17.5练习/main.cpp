#include <iostream>
#include <array>
#include <string>
#include <string_view>

namespace Animals
{
	enum Type
	{
		chicken,
		dog,
		cat,
		elephant,
		duck,
		snake,
		max_animals
	};

	struct Data
	{
		std::string_view name{};
		int legs{};
		std::string_view sound{};
	};

	constexpr std::array types{ chicken,dog,cat,elephant,duck,snake };
	constexpr std::array data
	{
		Data{"chicken" , 2 , "cluck"},
		Data{"dog" , 4 , "woof"},
		Data{"cat" , 4 , "meow"},
		Data{"elephant" , 4 , "pawoo"},
		Data{"duck" , 2 , "quack"},
		Data{"snake" , 0 , "hissss"},
	};

	static_assert(std::size(types) == max_animals);
	static_assert(std::size(data) == max_animals);
}

std::istream& operator>> (std::istream& in, Animals::Type& animal)
{
	std::string input{};
	std::getline(in >> std::ws, input);

	for (std::size_t index = 0; index < Animals::data.size(); ++index)
	{
		if (input == Animals::data[index].name)
		{
			animal = static_cast <Animals::Type>(index);
			return in;
		}
	}
	in.setstate(std::ios_base::failbit);
	return in;
}

void printAnimalData(Animals::Type type)
{
	const Animals::Data& animal{ Animals::data[type] };
	std::cout << " A " << animal.name << " has " << animal.legs << " legs and says " << animal.sound << ".\n";
}

int main()
{
	std::cout << "Enter an animal: ";
	Animals::Type type{};
	std::cin >> type;

	if (!std::cin)
	{
		std::cin.clear();
		std::cout << "That animal couldn't be found.\n";
		type = Animals::max_animals;
	}
	else
	{
		printAnimalData(type);
	}

	std::cout << "\nHere is the data for the rest of the animals:\n";
	for (auto a : Animals::types)
	{
		if (a != type)
		{
			printAnimalData(a);
		}
	}

	return 0;
}