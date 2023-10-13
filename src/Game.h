// ===== ===== ===== ===== ===== ===== ===== =====
// @file	Game.h
// @brief	ゲーム本体クラス
// 
// @date	2023-10-13
// @update	2023-10-13
// 
// @author	UNLUCKY
// ===== ===== ===== ===== ===== ===== ===== =====

#pragma once

class Game
{
public:
	static const std::string TITLE;
	static const std::string VERSION;

public:
	Game();
	~Game();

	void Initialize();
	void Execute();
	void Finalize();

private:
	void Update();
	void Render();
};