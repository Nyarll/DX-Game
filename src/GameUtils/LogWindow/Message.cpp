#include "Message.h"

Message::Message()
	:color(0)
{
}

Message::~Message()
{
}

void Message::SetMessage(std::string& _msg)
{
	msg = _msg;
}

void Message::SetFont(int& _font)
{
	font = _font;
}

bool Message::GetAlive()
{
	return render;
}

void Message::Render()
{
	if (render)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, cnt);
		DrawFormatStringToHandle(position.GetX() + 3, position.GetY() + 3, GetColor(0, 0, 0), font, msg.c_str());
		DrawFormatStringToHandle(position.GetX(), position.GetY(), color, font, msg.c_str());
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
	if (cnt >= 0)
	{
		cnt -= 0.5;
	}
}

void Message::SetPosition(const Vector2& _position)
{
	position = _position;
}

Vector2 Message::GetPosition()
{
	return position;
}

void Message::SetColor(const int& _color)
{
	color = _color;
}
