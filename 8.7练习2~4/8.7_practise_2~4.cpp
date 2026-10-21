#include <iostream>
#include "head.h"


int main()
{
	char myChar{ 'a' };
	while (myChar <= 'z')
	{
		std::cout << myChar << " " << static_cast<int>(myChar) << "\n";
		++myChar;
	}

	kCout_Five_To_One();

	k_Reverse_One_To_Five();

	return 0;
	
}