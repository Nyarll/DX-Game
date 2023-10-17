#include "PlayScene.h"

#include "../SceneManager.h"
#include "../../Framework/Input/InputManager.h"

#include "../../GameUtils/LogWindow/LogMessageWindow.h"

void PlayScene::Initialize(GameContext& context)
{
	auto msg_window = registry.create();
	registry.emplace<LogMessageWindow>(msg_window);
}

void PlayScene::Update(GameContext& context)
{
	if (test_count > 180)
	{
		context.Get<SceneManager>().RequestScene(SceneManager::SceneID::RESULT);
	}
	test_count++;
	GetLogWindow().SetMessage(GetColor(255, 255, 0), "now count : %d", test_count);
}

void PlayScene::Render(GameContext& context)
{
	DrawString(0, 0, "Play Scene", GetColor(255, 255, 255));

	GetLogWindow().Render();
}

LogMessageWindow& PlayScene::GetLogWindow()
{
	auto log_window = registry.view<LogMessageWindow>()[0];
	return registry.get<LogMessageWindow>(log_window);
}

