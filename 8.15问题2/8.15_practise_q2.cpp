#undef NDEBUG

#include <cassert> // assert
#include <iostream>

bool isPrime(int x)
{
    if (x <= 1)
        return false;
    if (x == 2)
        return true;
    if (x % 2 == 0)
        return false;

    for (int test{ 3 }; test * test <= x; test += 2)
    {
        if (x % test == 0)
            return false;
    }
    
    return true;
    
}

int main()
{
    assert(!isPrime(0)); // 如果 isPrime(0) 为真，则终止程序
    assert(!isPrime(1));
    assert(isPrime(2));  // 如果 isPrime(2) 为假，则终止程序
    assert(isPrime(3));
    assert(!isPrime(4));
    assert(isPrime(5));
    assert(isPrime(7));
    assert(!isPrime(9));
    assert(isPrime(11));
    assert(isPrime(13));
    assert(!isPrime(15));
    assert(!isPrime(16));
    assert(isPrime(17));
    assert(isPrime(19));
    assert(isPrime(97));
    assert(!isPrime(99));
    assert(isPrime(13417));

    std::cout << "Success!\n";

    return 0;
}