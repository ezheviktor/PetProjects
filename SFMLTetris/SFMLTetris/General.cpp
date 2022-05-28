#include "General.h"

int getRandomNumber(int min, int max)
{
	static const double fraction = 1 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void getPassedTime(Clock& clock, float& timer)
{
	float time = clock.getElapsedTime().asSeconds();
	clock.restart();
	timer += time;
}