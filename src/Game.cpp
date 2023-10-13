#include "pch.h"
#include "Game.h"

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
		//TODO: Update
		//TODO: Render

		ScreenFlip();
		ClearDrawScreen();
	}
}

void Game::Finalize()
{
}
