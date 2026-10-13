#include <iostream>

int main()
{
    unsigned short x{ 65535 }; // 最大的16位无符号整数
    std::cout << "x was: " << x << '\n';

    x = 65536; // 65536 溢出, 所以重新取值
    std::cout << "x is now: " << x << '\n';

    x = 65537; // 65537 溢出, 所以重新取值
    std::cout << "x is now: " << x << '\n';

    unsigned short y{ 0 }; // 最小的16位无符号整数
    std::cout << "y was: " << y << '\n';

    y = -1; // -1 溢出, 所以重新取值 一个2字节无符号整数的值为0，那么-1会环绕到取值范围的最大值，即65535
    std::cout << "y is now: " << y << '\n';

    y = -2; // -2 溢出, 所以重新取值 -2环绕到65534，以此类推
    std::cout << "y is now: " << y << '\n';

    signed int s{ -1 };
    unsigned int u{ 1 };

    if (s < u) // -1 被转换为 4294967295,  4294967295 < 1 结果 false
        std::cout << "-1 is less than 1\n";
    else
        std::cout << "1 is less than -1\n";
    std::cout << "s : " << s << '\n'; //-1
    std::cout << "u : " << u << '\n'; //1

    return 0;
}