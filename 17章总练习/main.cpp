#include <iostream>
#include <array>
#include "Random.h"
#include <limits> 

namespace Potion
{
	enum Type
	{
		healing,
		mana,
		speed,
		invisibility,
		max_potions
	};

	constexpr std::array types{ healing , mana , speed , invisibility };
	
	constexpr std::array<std::string_view, max_potions> name{"healing" , "mana" , "speed" , "invisibility"};
	constexpr std::array cost{ 20, 30, 12, 50 };

	static_assert(std::size(types) == max_potions);
	static_assert(std::size(cost) == max_potions);
	static_assert(std::size(types) == max_potions);
}

class Player
{
public:
	explicit Player(std::string_view name)
		:player_name{ name }, player_budget{ Random::get(s_minStartingGold , s_maxStartingGold) }
	{
	}

	int getGold() const{ return player_budget; }
	int inventory(Potion::Type p) { return player_inventory[p]; }

	bool buy(Potion::Type type)
	{
		if (player_budget < Potion::cost[type])
		{
			return false;
		}
		player_budget -= Potion::cost[type];
		++player_inventory[type];
		return true;
	}
private:
	static constexpr int s_minStartingGold{ 80 };
	static constexpr int s_maxStartingGold{ 120 };


	std::string_view player_name{};
	int player_budget{};
	std::array<int, Potion::max_potions > player_inventory{};
};

void ignoreLine()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int charNumToInt(char c)
{
	return c - '0';
}

Potion::Type whichPotion()
{
	std::cout << "Enter the number of the potion you'd like to buy, or 'q' to quit: ";
	char input{};
	while (true)
	{
		std::cin >> input;
		if (!std::cin)
		{
			std::cin.clear();
			ignoreLine();
			continue;
		}

		if (!std::cin.eof() && std::cin.peek() != '\n')
		{
			std::cout << "That is an invalid input.  Try again: ";
			ignoreLine(); // 忽略所有多余输入
			continue;
		}

		if (input == 'q')
		{
			return Potion::max_potions;
		}

		int val{ charNumToInt(input) };
		if (val >= 0 && val < Potion::max_potions)
			return static_cast<Potion::Type>(val);

		std::cout << "That is an invalid input.  Try again: ";
		ignoreLine();
	}
}


void shop(Player &player)
{
	while (true)
	{
		std::cout << "Here is our selection for today:\n";

		for (auto e : Potion::types)
		{
			std::cout << e << ") " << Potion::name[e] << " costs " << Potion::cost[e] << " \n";
		}

		Potion::Type which{ whichPotion() };
		if (which == Potion::max_potions)
		{
			return;
		}

		bool success{ player.buy(which) };
		if (!success)
			std::cout << "You can not afford that.\n\n";
		else
			std::cout << "You purchased a potion of " << Potion::name[which] << ".  You have " << player.getGold() << " gold left.\n\n";
	}
}

void printInventory(Player& player)
{
	std::cout << "Your inventory contains: \n";

	for (auto p : Potion::types)
	{
		if (player.inventory(p) > 0)
		{
			std::cout << player.inventory(p) << "x potion of " << Potion::name[p] << '\n';
		}
	}

	std::cout << "You escaped with " << player.getGold() << " gold remaining.\n";
}


int main()
{
	std::cout << "Welcome to Roscoe's potion emporium!\n";
	std::cout << "Enter your name: ";
	std::string name{};
	std::cin >> name;

	Player player{ name };

	std::cout << "Hello, " << name << ", you have " << player.getGold() << " gold.\n\n";

	shop(player);

	std::cout << "\n";

	printInventory(player);

	std::cout << "\nThanks for shopping at Roscoe's potion emporium!\n";

	return 0;
}