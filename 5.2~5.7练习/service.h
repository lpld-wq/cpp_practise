#pragma once

inline constexpr double kCritMul{ 2.0 };
inline constexpr double kNormalMul{ 1.0 };
double kGetAktDate();
double kGetDefendDate();
bool kGetCritDate();

constexpr double kCritMultiplier(bool crit)
{
	return (crit ? kCritMul : kNormalMul);
}

constexpr double kDamegeCulculate(double akt, double defence, double mult)
{
	return (akt * mult) - defence;
}