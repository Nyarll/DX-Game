#include "Random.h"

namespace Random
{
	std::random_device rd;
	std::mt19937 mt(rd());

	float Value()
	{
		return static_cast<float>(Rand(RAND_MAX)) / RAND_MAX;
	}

	int Rand(int max)
	{
		return mt() % (max + 1);
	}

	float Rand(float max)
	{
		return Value() * max;
	}

	int Range(int min, int max)
	{
		if (max < min)
			std::swap(min, max);
		return Rand(max - min) + min;
	}

	float Range(float min, float max)
	{
		if (max < min)
			std::swap(min, max);
		return Rand(max - min) + min;
	}

}