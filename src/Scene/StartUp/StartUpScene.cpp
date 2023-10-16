#include "StartUpScene.h"

#include "../SceneManager.h"

void StartUpScene::Initialize(GameContext& context)
{
}

void StartUpScene::Update(GameContext& context)
{
	if (test_count > 180)
	{
		context.Get<SceneManager>().RequestScene(SceneManager::SceneID::TITLE);
	}
	test_count++;
}

void StartUpScene::Render(GameContext& context)
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "Start Up Scene : count - %d", test_count);
}
