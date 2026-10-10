#include <iostream>

#define PRINT_JOE

int main()
{
	#ifdef PRINT_JOE
	std::cout << "Joe\n";
	#endif

	#ifdef PRINT_BOB
	std::cout << "Bob\n";
	#endif

	return 0;
}