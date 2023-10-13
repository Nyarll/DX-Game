// ===== ===== ===== ===== ===== ===== ===== =====
// @file	Random.h
// @brief	ƒ‰ƒ“ƒ_ƒ€‚È”’l‚ğ¶¬‚·‚é
// 
// @date	2023-10-13
// @update	2023-10-13
// 
// @author	UNLUCKY
// ===== ===== ===== ===== ===== ===== ===== =====

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