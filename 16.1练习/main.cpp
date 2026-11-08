#include <vector>
#include <iostream>

int main()
{
	std::vector square{ 1 , 4, 9 , 16 , 25 };
	std::vector<double> temperature{ 365 };

	std::vector<int> arr(3);
	std::cout << "Enter 3 integers: ";
	std::cin >> arr[0] >> arr[1] >> arr[2];

	std::cout << "The sum is: " << arr[0] + arr[1] + arr[2] << "\n";
	std::cout << "The product is: " << arr[0] * arr[1] * arr[2] << '\n';

	return 0;
}
