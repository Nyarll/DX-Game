// ===== ===== ===== ===== ===== ===== ===== =====
// @file	LogMessageWindow.h
// @brief	ÉçÉOï\é¶ópUI
// 
// @date	2023-10-17
// @update	2023-10-17
// 
// @author	UNLUCKY
// ===== ===== ===== ===== ===== ===== ===== =====

#pragma once

#include "Message.h"

#include <vector>

class LogMessageWindow
{
private:
	static const int MAX_LOG_MSG = 20 * 8;

	static const int LOG_WINDOW_SIZE = 400;

	Vector2 start;
	Vector2 end;
	int font;

	std::vector<Message> messages;

public:
	LogMessageWindow();
	~LogMessageWindow();

	void SetMessage(int msgColor, std::string fmt_msg, ...);
	void Render();

	void DeleteAll();
};