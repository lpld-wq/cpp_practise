#include <iostream>
#include <algorithm> // std::swap

void printValue(const int* p)
{
	//E1 
	if (!p)
	{
		std::cout << "null\n";
	}
	else
	{
		std::cout << *p << "\n";
	}
}

void addOne(int* p)
{
	//E3
	if (!p)
	{
		std::cout << "null\n";
	}
	else
	{
		++(*p);
	}
}

void swap(int* a, int* b)
{
	//E3
	std::cout << *a << " " << *b << "\n";
	std::swap( *a , *b );
	std::cout << "exchange\n";
	std::cout << *a << " " << *b << "\n";
}

int& at(int* arr, int index)
{
	//E4
	return arr[index];
}

int* find(int* arr, int n, int target)
{
	//E4
	if (!arr || n <= 0)
	{
		return nullptr;
	}
	for (int i{ 0 }; i < n; ++i)
	{
		if (arr[i] == target)
		{
			return &arr[i];
		}	
	}
	return nullptr;
}
/*int& bad()
{
	//E4
	int local{ 42 };
	return local;
}
*/
int main()
{
	//E1
	int x{ 7 };
	printValue(&x);
	printValue(nullptr);

	int z{ 10 }, y{ 20 };
	const int* p1{ &z };
	int* const p2{ &z };
	const int* const p3{ &z };
	//E1
	
	//E2
	//*p1 = 11; “p1”: 赋值给类型为 'const int *' 的常量限定 变量
	p1 = &y;
	*p2 = 11;
	//p2 = &y; “p2”: 赋值给类型为 'int *const ' 的常量限定 变量
	//*p3 = 12;
	//p3 = &y;“p3”: 赋值给类型为 'int *const ' 的常量限定 变量
	//E2

	//E3
	int a{ 5 }; 
	int b{ 10 };
	addOne(&a); 
	std::cout << a << "\n";
	addOne(nullptr);

	swap(&a, &b);
	//E3
	
	//E4
	int arr[3]{ 1,2,3 };
	at(arr, 1) = 20;
	std::cout << arr[1] << "\n";
	int* p = find(arr, 3, 2);
	if (p != nullptr)
	{
		std::cout << *p << '\n';
	}
	else
	{
		std::cout << "not found\n";
	}
	//int test = bad();//返回局部变量的地址或临时 : local
}