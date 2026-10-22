#include <iostream>

double getTowerHeight()
{
	std::cout << "Enter the height of the tower in meters: ";
	double towerHeight{};
	std::cin >> towerHeight;
	return towerHeight;
}

double calculateBallHeight(double towerHeight, int seconds)
{
	double gravity{ 9.8 };

	double fallDistance{ gravity * (seconds * seconds) / 2.0 };
	double ballHeight{ towerHeight - fallDistance };

	if (ballHeight < 0.0)
		return 0.0;

	return ballHeight;
}

void printBallHeight(double ballHeight, int seconds)
{
	if (ballHeight > 0.0)
		std::cout << "At " << seconds << " seconds, the ball is at height: " << ballHeight << " meters\n";
	else
		std::cout << "At " << seconds << " seconds, the ball is on the ground.\n";
}

double calculateAndPrintBallHeight(double towerHeight, int seconds)
{
	double ballHeight{ calculateBallHeight(towerHeight, seconds) };
	printBallHeight(ballHeight, seconds);

	return ballHeight;
}

int main()
{
	double towerHeight{ getTowerHeight() };
	int seconds{ 0 };
	while (calculateAndPrintBallHeight(towerHeight, seconds))
	{
		++seconds;
	}

	return 0;
}