#include "InputManager.h"

InputManager::InputManager()
{
	keyboard = std::make_unique<InputKeyboard>();
}

InputManager::~InputManager()
{
}

void InputManager::Update()
{
	keyboard->Update();
}

void InputManager::UpdateOld()
{
	keyboard->UpdateOld();
}

std::unique_ptr<InputKeyboard>& InputManager::Keyboard()
{
	return keyboard;
}

void InputKeyboard::Update()
{
	GetHitKeyStateAll(key);
}

void InputKeyboard::UpdateOld()
{
	GetHitKeyStateAll(key_old);
}

bool InputKeyboard::IsKeyDown(int key_id)
{
	if (key[key_id] && !key_old[key_id])
	{
		return true;
	}
	return false;
}

bool InputKeyboard::IsKeyStay(int key_id)
{
	if (key[key_id])
	{
		return true;
	}
	return false;
}

bool InputKeyboard::IsKeyUp(int key_id)
{
	if (!key[key_id] && key_old[key_id])
	{
		return true;
	}
	return false;
}

bool InputKeyboard::IsAnyKeyDown()
{
	for (int i = 0; i < 256; i++)
	{
		if (this->key[i])
		{
			return true;
		}
	}
	return false;
}
