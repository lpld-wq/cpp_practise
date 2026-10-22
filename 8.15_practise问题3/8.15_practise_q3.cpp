#include <iostream>
#include "random.h"

int main()
{
	bool next{ true };
	while (next)
	{
		int target{ Random::get(1, 100) };
		std::cout << target << "\n";//for test
		int token{ 0 };
		std::cout << "Let's play a game. I'm thinking of a number between 1 and 100. You have 7 tries to guess what it is.\n";
		while (token < 7)
		{
			++token;
			std::cout << "Guess #" << token << ": ";
			int x{ 0 };
			std::cin >> x;
			if (x > target)
				std::cout << "Your guess is too high.\n";
			else if (x < target)
				std::cout << "Your guess is too low.\n";
			else
			{
				std::cout << "Correct!You win!\n";
				break;
			}
		}
		char t_tryagain{};
		std::cout << "Would you like to play again (y/n)? ";
		std::cin >> t_tryagain;
		if (t_tryagain == 'y')
			next = true;
		else
			next = false;
	}
}
