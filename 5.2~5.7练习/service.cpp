#include <iostream>
#include "service.h"

double kGetAktDate()
{
	std::cout << "请填入您的基础攻击力(akt)\n";
	std::cout << "akt: " ;
	double akt{};
	std::cin >> akt;
	return akt;
}

double kGetDefendDate()
{
	std::cout << "\n请填入对手的防御力(defence)\n";
	std::cout << "defence: " ;
	double defence{};
	std::cin >> defence;
	return defence;
}


bool kGetCritDate()
{
	std::cout << "\n请填入您的攻击暴击与否(crit)\n";
	std::cout << "crit(1 or 0): " ;
	bool crit{};
	std::cin >> crit;
	return crit;
}
