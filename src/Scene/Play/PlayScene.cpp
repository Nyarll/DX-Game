#include "PlayScene.h"

#include "../SceneManager.h"
#include "../../Framework/Input/InputManager.h"

void PlayScene::Initialize(GameContext& context)
{
}

void PlayScene::Update(GameContext& context)
{
	if (test_count > 180)
	{
		context.Get<SceneManager>().RequestScene(SceneManager::SceneID::RESULT);
	}
	test_count++;
}

void PlayScene::Render(GameContext& context)
{
	DrawString(0, 0, "Play Scene", GetColor(255, 255, 255));
}
