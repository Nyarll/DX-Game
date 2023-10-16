// ===== ===== ===== ===== ===== ===== ===== =====
// @file	StartUpScene.h
// @brief	ゲーム起動時
// 
// @date	2023-10-16
// @update	2023-10-16
// 
// @author	UNLUCKY
// ===== ===== ===== ===== ===== ===== ===== =====

#pragma once

#include "../IScene.h"

class StartUpScene : public IScene
{
public:
	virtual void Initialize(GameContext& context)override;
	virtual void Update(GameContext& context)override;
	virtual void Render(GameContext& context)override;

	static IScene* Create()
	{
		return { new StartUpScene };
	}
};