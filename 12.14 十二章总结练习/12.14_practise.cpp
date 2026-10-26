#include <iostream>
#include <algorithm>

void sort2(int& lesser, int& greater)
{
    if (lesser > greater)
    {
        std::swap(greater, lesser);
    }
}

int main()
{
    int x{ 7 };
    int y{ 5 };

    std::cout << x << ' ' << y << '\n'; // 应打印 7 5

    sort2(x, y); // 确保需要交换时能正常工作
    std::cout << x << ' ' << y << '\n'; // 应打印 5 7

    sort2(x, y); // 确保不需要交换时也能正常工作
    std::cout << x << ' ' << y << '\n'; // 应打印 5 7

    return 0;
}