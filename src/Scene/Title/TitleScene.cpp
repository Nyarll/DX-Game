#include "TitleScene.h"

#include "../SceneManager.h"
#include "../../Framework/Input/InputManager.h"

void TitleScene::Initialize(GameContext& context)
{
}

void TitleScene::Update(GameContext& context)
{
	if (InputManager::singleton().Keyboard().IsKeyDown(KEY_INPUT_SPACE))
	{
		context.Get<SceneManager>().RequestScene(SceneManager::SceneID::PLAY);
	}
}

void TitleScene::Render(GameContext& context)
{
	DrawString(0, 0, "Title Scene", GetColor(255, 255, 255));
	DrawString(0, 12, "push to [SPACE] key.", GetColor(255, 255, 255));
}
