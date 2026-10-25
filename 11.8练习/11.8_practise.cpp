#include <iostream>

template <int N>
constexpr int factorial()
{
    static_assert(N >= 0);

    int product{ 1 };
    for (int i{ 2 }; i <= N ; ++i)
    {
        product *= i;
    }
    return product;

}




int main()
{
    static_assert(factorial<0>() == 1);
    static_assert(factorial<3>() == 6);
    static_assert(factorial<5>() == 120);

    //factorial<-3>(); 编译失败。E2784:静态断言失败，最终比较为 - 3 >= 0，在"int factorial<N>0[其中N =- 3]"所在行数:17实例化期间检测

    return 0;
}