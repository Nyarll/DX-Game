// ===== ===== ===== ===== ===== ===== ===== =====
// @file	PlayScene.h
// @brief	ÉQÅ[ÉÄÉvÉåÉC
// 
// @date	2023-10-16
// @update	2023-10-16
// 
// @author	UNLUCKY
// ===== ===== ===== ===== ===== ===== ===== =====

#pragma once

#include "../IScene.h"

class LogMessageWindow;

class PlayScene : public IScene
{
private:
	int test_count = 0;

public:
	virtual void Initialize(GameContext& context)override;
	virtual void Update(GameContext& context)override;
	virtual void Render(GameContext& context)override;

	static IScene* Create()
	{
		return { new PlayScene };
	}

	LogMessageWindow& GetLogWindow();
};