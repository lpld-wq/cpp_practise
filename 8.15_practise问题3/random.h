#pragma once
#include <chrono>
#include <random>
namespace Random
{
	// 返回一个播种好的 Mersenne Twister
	inline std::mt19937 generate()
	{
		std::random_device rd{};

		// 返回一个时间戳以及由7个std::random_device产出的随机数组成的种子序列
		std::seed_seq ss{
			static_cast<std::seed_seq::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()),
				rd(), rd(), rd(), rd(), rd(), rd(), rd() };

		return std::mt19937{ ss };
	}

	// 全局的 std::mt19937 对象.
	// inline 关键字，意味着该对象在整个程序中只有一个
	inline std::mt19937 mt{ generate() }; // 生成一个播种好的std::mt19937对象

	// 产出在 [min, max] 间的一个随机数
	inline int get(int min, int max)
	{
		return std::uniform_int_distribution{ min, max }(mt);
	}
}
