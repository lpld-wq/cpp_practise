#include <iostream>

int accumulate(int num)
{
    static int x{ 0 };
    x += num;
    return x;
}




int main()
{
    std::cout << accumulate(4) << '\n'; // 打印 4
    std::cout << accumulate(3) << '\n'; // 打印 7
    std::cout << accumulate(2) << '\n'; // 打印 9
    std::cout << accumulate(1) << '\n'; // 打印 10

    return 0;
}