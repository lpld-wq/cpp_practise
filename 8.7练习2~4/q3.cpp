#include <iostream>
#include "head.h"

void kCout_Five_To_One()
{
	int outer{ 5 };
	while (outer > 0)
	{
		int inner{ outer };
		while (inner > 0)
		{
			std::cout << inner << " ";
			--inner;
		}
		std::cout << "\n";
		--outer;
	}
}

void k_Reverse_One_To_Five()
{
	int outer{ 1 };
	while (outer <= 5)
	{
		int inner{ outer };
		int space{ 0 };
		while (space < (5 - inner))
		{
			std::cout << "  ";
			++space;
		}
		while (inner > 0)
		{
			std::cout << inner << " ";
			--inner;
		}
		std::cout << "\n";
		++outer;
	}

}