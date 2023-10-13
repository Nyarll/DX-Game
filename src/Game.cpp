#include "Game.h"

#include "Framework/Input/InputManager.h"

const std::string Game::TITLE = "DxLibGame";
const std::string Game::VERSION = "develop 0.0.0";

Game::Game()
{
}

Game::~Game()
{
}

void Game::Initialize()
{
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
}

void Game::Render()
{
}
