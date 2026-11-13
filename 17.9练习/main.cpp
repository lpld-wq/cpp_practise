#include <iostream>

void printCString(const char str[])
{
	while (*str != '\0')
	{
		std::cout << *str;

		++str;
	}
}

void printCStringBackwards(const char str[])
{
	const char* ptr{ str };
	while (*ptr != '\0')
	{
		++ptr;
	}

	while (ptr-- != str)
	{
		std::cout << *ptr;
	}
}


int main()
{
	printCStringBackwards("Hello world!");
	std::cout << '\n';

	return 0;
}
