#include "ResultScene.h"

#include "../SceneManager.h"
#include "../../Framework/Input/InputManager.h"

void ResultScene::Initialize(GameContext& context)
{
}

void ResultScene::Update(GameContext& context)
{
	if (InputManager::singleton().Keyboard().IsKeyDown(KEY_INPUT_SPACE))
	{
		context.Get<SceneManager>().RequestScene(SceneManager::SceneID::TITLE);
	}
}

void ResultScene::Render(GameContext& context)
{
	DrawString(0, 0, "Result Scene", GetColor(255, 255, 255));
	DrawString(0, 12, "push to [SPACE] key.", GetColor(255, 255, 255));
}
