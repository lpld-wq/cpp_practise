#include <iostream>
#include <string>
#include <string_view>

struct Monster
{
	enum Type
	{
	ogre,
	dragon,
	orc,
	giant_spider,
	slime,
	};
	
	Type type{};
	std::string name{};
	int health{};
};

constexpr std::string_view kGetMonsterTypeString(Monster::Type type)
{
	switch (type)
	{
		case Monster::ogre:              return "Ogre";
		case Monster::dragon:            return "dragon";
		case Monster::orc:               return "orc";
		case Monster::giant_spider:      return "giant_spider";
		case Monster::slime:             return "slime";
	}
	
	return "unknown";
}
void printMonster(const Monster& monster)
{
	std::cout << "This " << kGetMonsterTypeString(monster.type) <<
		         " is named " << monster.name << 
		         " and has " << monster.health << " health.\n";
}

int main()
{
	Monster ogre{ Monster::ogre, "Torg", 145 };
	Monster slime{ Monster::slime, "Blurp", 23 };

	printMonster(ogre);
	printMonster(slime);

	return 0;
}