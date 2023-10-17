#include "LogMessageWindow.h"

#include "../../Game.h"

LogMessageWindow::LogMessageWindow()
{
	font = CreateFontToHandle("Meiryo UI", 16, -1);
	start = Vector2(0, MAX_LOG_MSG);
	end = Vector2(Game::SCREEN_CENTER_X, Game::SCREEN_HEIGHT);
}

LogMessageWindow::~LogMessageWindow()
{
}

void LogMessageWindow::SetMessage(int msgColor, std::string fmt_msg, ...)
{
	int final_n, n = ((int)fmt_msg.size()) * 2; /* fmt_str‚Ì‚Q”{‚ÌƒTƒCƒY‚ð—\–ñ */
	std::unique_ptr<char[]> formatted;
	va_list ap;
	while (1)
	{
		formatted.reset(new char[n]);
		strcpy_s(&formatted[0], n, fmt_msg.c_str());
		va_start(ap, fmt_msg);
		final_n = vsnprintf(&formatted[0], n, fmt_msg.c_str(), ap);
		va_end(ap);
		if (final_n < 0 || final_n >= n)
			n += abs(final_n - n + 1);
		else
			break;
	}
	std::string result = std::string(formatted.get());

	Message msg;
	msg.SetMessage(result);
	msg.SetPosition(Vector2(start.GetX(), end.GetY() - 20));
	msg.SetFont(font);
	msg.SetColor(msgColor);

	for (int i = 0; i < messages.size(); i++)
	{
		Vector2 next_position = Vector2(messages[i].GetPosition().GetX(), messages[i].GetPosition().GetY() - 20);
		messages[i].SetPosition(next_position);
	}
	messages.push_back(msg);
}

void LogMessageWindow::Render()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
	DrawBox((int)start.GetX(), (int)start.GetY(), 400, (int)end.GetY(), GetColor(0, 0, 0), true);
	DrawBox((int)start.GetX(), (int)start.GetY(), 400, (int)end.GetY(), GetColor(255, 0, 0), false);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	for (int i = 0; i < this->messages.size(); i++)
	{
		int y = messages[i].GetPosition().GetY();
		if (y >= LogMessageWindow::MAX_LOG_MSG)
		{
			this->messages[i].Render();
		}
		else
		{
			this->messages.erase(this->messages.begin() + i);
		}

		if (this->messages[i].GetAlive() == false)
		{
			this->messages.erase(this->messages.begin() + i);
		}
	}
}

void LogMessageWindow::DeleteAll()
{
	messages.clear();
}
