#include "Game.h"

#include "Framework/Input/InputManager.h"
#include "Scene/Scene.h"

const std::string Game::TITLE = "DxLibGame";
const std::string Game::VERSION = "develop 0.0.0";

Game::Game() noexcept(false)
{
}

Game::~Game()
{
}

void Game::Initialize()
{
	RegisterScene();
}

void Game::Execute()
{
	while (!ProcessMessage())
	{
		Update();
		Render();

		InputManager::singleton().UpdateOld();
		
		ScreenFlip();
		ClearDrawScreen();
	}
}

void Game::Finalize()
{
}

void Game::Update()
{
	InputManager::singleton().Update();
	Get<SceneManager>().UpdateActiveScene(*this);
}

void Game::Render()
{
	Get<SceneManager>().RenderActiveScene(*this);
}

void Game::RegisterScene()
{
	Register(std::make_unique<SceneManager>());
	auto& manager = Get<SceneManager>();

	manager.Register(SceneManager::SceneID::START_UP, StartUpScene::Create);

	manager.SetStartScene(*this, SceneManager::SceneID::START_UP);
}
