#pragma once

namespace Random
{
	// 0.0 <= x <= 1.0
	float Value();

	// 0 <= x <= max int
	int Rand(int max);

	// 0.0 <= x <= max float
	float Rand(float max);

	// min <= x <= max int
	int Range(int min, int max);

	// min <= x <= max float
	float Range(float min, float max);
}