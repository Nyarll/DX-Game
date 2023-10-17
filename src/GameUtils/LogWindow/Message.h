// ===== ===== ===== ===== ===== ===== ===== =====
// @file	Message.h
// @brief	ログ用メッセージ
// 
// @date	2023-10-16
// @update	2023-10-16
// 
// @author	UNLUCKY
// ===== ===== ===== ===== ===== ===== ===== =====

#pragma once

#include "../../Framework/Vector2.h"

#include <string>

class Message
{
private:
	Vector2 position;
	std::string msg;
	bool render = true;
	int color;
	int font = -1;

	float cnt = 240;

public:
	Message();
	~Message();

	void SetMessage(std::string& _msg);
	void SetFont(int& _font);

	bool GetAlive();

	void Render();

	void SetPosition(const Vector2& _position);
	Vector2 GetPosition();

	void SetColor(const int& _color);
};