#include <iostream>
#include "service.h"

int main()
{	
	double akt{};
	akt = kGetAktDate();

	double defence{};
	defence = kGetDefendDate();

	bool crit{};
	crit = kGetCritDate();
	

	double damage{};
	damage = kDamegeCulculate(akt, defence, kCritMultiplier(crit));
	if (damage < 0)
		damage = 0;
	std::cout << "\n最终造成的伤害为: " << damage << "\n";
	return 0;
}
