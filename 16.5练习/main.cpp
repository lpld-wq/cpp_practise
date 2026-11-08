#include <iostream>
#include <vector>

template <typename T>
void printArray(const std::vector<T>& arr)
{
    std::size_t length{ arr.size() };

    for (std::size_t index{ 0 }; index < length; ++index)
    {
        std::cout << arr[index] << " ";
    }

    if (arr.size() > 0)
        std::cout << '\n';
}

template <typename T>
int findIndex(const std::vector<T>& arr, T val)
{
    std::size_t length{ arr.size() };
    for (std::size_t index{ 0 }; index < length; ++index)
    {
        if (arr[index] == val)
        {
            return static_cast<int>(index);
        }
    }

    return -1;
}

template <typename T>
T getValidNumber(T low , T high)
{
    T val{};
    do
    {
        std::cout << "Enter a number between 1 and 9: ";
        std::cin >> val;

        if (!std::cin)
        {
            std::cin.clear();
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (val < low || val > high);

    return val;
}

template <typename T>
T findMax(std::vector<T> arr)
{
    std::size_t length{ arr.size() };
    if (length == 0)
        return T{};
    T max{ arr[0] };
    for (std::size_t index{ 1 }; index < length; ++index)
    {
        if (arr[index] > max)
        {
            max = arr[index];
        }
    }

    return max;
}



int main()
{
    std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };
    std::vector arr_1{ 4.4, 6.6, 7.7, 3.3, 8.8, 2.2, 1.1, 9.9 };

    auto num{ getValidNumber(1.0 , 9.9) };
    printArray(arr_1);
    int index{ findIndex(arr_1, num) };
    if (index != -1)
    {
        std::cout << "The number " << num << " has index " << index << "\n";
    }
    else
    {
        std::cout << "The number " << num << " was not found\n";
    }

    std::vector data1{ 84, 92, 76, 81, 56 };
    std::cout << findMax(data1) << '\n';

    std::vector data2{ -13.0, -26.7, -105.5, -14.8 };
    std::cout << findMax(data2) << '\n';

    std::vector<int> data3{ };
    std::cout << findMax(data3) << '\n';

    return 0;
}