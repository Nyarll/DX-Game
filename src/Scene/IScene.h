// ===== ===== ===== ===== ===== ===== ===== =====
// @file	IScene.h
// @brief	ゲームシーンインターフェイス
// 
// @date	2023-10-13
// @update	2023-10-13
// 
// @author	UNLUCKY
// ===== ===== ===== ===== ===== ===== ===== =====

#pragma once

#include <entt.hpp>

#include "../Framework/Context/GameContext.h"

class IScene
{
protected:
	entt::registry registry;

public:
	IScene() {};
	virtual ~IScene() = default;

	virtual void Initialize(GameContext& context) = 0;
	virtual void Update(GameContext& context) = 0;
	virtual void Render(GameContext& context) = 0;
	virtual void Finalize(GameContext& context) {}
};