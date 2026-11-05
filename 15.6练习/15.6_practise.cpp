#include <chrono>
#include <random>
#include <iostream>

class Random
{
private:
	static std::mt19937 generate()
	{
		std::random_device rd{};

		// 用高精度时钟和 std::random_device 生成的 7 个随机数来创建 seed_seq
		std::seed_seq ss{
			static_cast<std::seed_seq::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()),
				rd(), rd(), rd(), rd(), rd(), rd(), rd() };

		return std::mt19937{ ss };
	}

	static inline std::mt19937 mt{ generate() }; // 生成一个已播种的 std::mt19937 并拷贝到全局对象中

public:
	// 生成 [min, max]（含两端）范围内的随机整数
	static int get(int min, int max)
	{
		return std::uniform_int_distribution{ min, max }(mt);
	}
};

int main()
{
	// 打印一堆随机数
	for (int count{ 1 }; count <= 10; ++count)
		std::cout << Random::get(1, 6) << '\t';

	std::cout << '\n';

	return 0;
}