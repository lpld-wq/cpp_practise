#include <iostream>
#include <utility>

int main()
{
	int array[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };
	constexpr int length{ static_cast<int>(std::size(array)) };

	for (int literation{0}; literation < length - 1; literation++)
	{
		int endofArrayIndex{ length - literation };

		bool swapped{ false };

		for (int start_index{ 0 }; start_index < endofArrayIndex - 1; start_index++)
		{
			if (array[start_index] > array[start_index + 1])
			{
				std::swap(array[start_index], array[start_index + 1]);
				swapped = true;
			}
		}

		if (!swapped)
		{
			std::cout << "Early termination on iteration: " << literation + 1 << '\n';
			break;
		}

		for (int index{ 0 }; index < length; ++index)
			std::cout << array[index] << ' ';

		std::cout << '\n';
	}

	

	return 0;
}
