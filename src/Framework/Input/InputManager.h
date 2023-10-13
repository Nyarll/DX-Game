// ===== ===== ===== ===== ===== ===== ===== =====
// @file	InputManager.h
// @brief	デバイス入力を管理
// 
// @date	2023-10-13
// @update	2023-10-13
// 
// @author	UNLUCKY
// ===== ===== ===== ===== ===== ===== ===== =====

#pragma once
#include "../Singleton.h"

class InputKeyboard;

class InputManager final : public Singleton<InputManager>
{
private:
	std::unique_ptr<InputKeyboard> keyboard;

private:
	friend class Singleton<InputManager>;
	InputManager();

public:
	~InputManager();

	void Update();
	void UpdateOld();

	std::unique_ptr<InputKeyboard>& Keyboard();
};

class InputKeyboard
{
private:
	char key[256] = { 0 };
	char key_old[256] = { 0 };

public:
	InputKeyboard() {};
	~InputKeyboard() {};

	void Update();
	void UpdateOld();

	bool IsKeyDown(int key_id);
	bool IsKeyStay(int key_id);
	bool IsKeyUp(int key_id);

	bool IsAnyKeyDown();
};