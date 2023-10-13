#include "Vector2.h"

#define _USE_MATH_DEFINES
#include <cmath>

const Vector2 Vector2::ZERO = Vector2(0, 0);

Vector2::Vector2()
{
	x = 0;
	y = 0;
}

Vector2::Vector2(const Vector2& vec)
{
	x = vec.x;
	y = vec.y;
}

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2::Vector2(int x, int y)
{
	this->x = static_cast<float>(x);
	this->y = static_cast<float>(y);
}

Vector2 Vector2::Normalized()
{
	float len = this->Length();
	return{ this->x / len,this->y / len };
}

float Vector2::Dot(Vector2* vec2)
{
	return ((this->x * vec2->x) + (this->y * vec2->y));
}

float Vector2::Cross(Vector2* vec2)
{
	return (this->x * vec2->y - vec2->x * this->y);
}

Vector2 Vector2::Rotate(float rad)
{
	return{ ((this->x * cosf(rad)) - (this->y * sinf(rad))),((this->x * sinf(rad)) + (this->y * cosf(rad))) };
}

float Vector2::Angle()
{
	return atan2f(this->y, this->x);
}

float Vector2::Angle2(Vector2* vec2)
{
	return atan2(vec2->y - this->y, vec2->x - this->x);
}

float Vector2::Length()
{
	return sqrtf(this->x * this->x + this->y * this->y);
}

float Vector2::LengthSquared()
{
	return (this->x * this->x) + (this->y * this->y);
}

float Vector2::LengthTo(Vector2* vec2)
{
	return sqrtf(LengthSquaredTo(vec2));
}

float Vector2::LengthSquaredTo(Vector2* vec2)
{
	return (vec2->x - this->x) * (vec2->x - this->x) + (vec2->y - this->y) * (vec2->y - this->y);
}

void Vector2::Decompose(Vector2* vec2, Vector2* outvec1, Vector2* outvec2)
{
	float angle_rota = vec2->Angle();
	float vec_rota = Angle();
	float diff_rota = vec_rota - angle_rota;
	float vec_length = Length();

	float vec_a_length = vec_length * cosf(diff_rota);
	float vec_b_length = vec_length * sinf(diff_rota);
	float vec_a_rota = angle_rota;
	float vec_b_rota = angle_rota + (float)M_PI_2;

	*outvec1 = { vec_a_length * cosf(vec_a_rota), vec_a_length * sinf(vec_a_rota) };
	*outvec2 = { vec_b_length * cosf(vec_b_rota), vec_b_length * sinf(vec_b_rota) };
}

Vector2 Vector2::TranslateTowards(const Vector2& from, const Vector2& to, float maxDelta)
{
	Vector2 sub = to - from;
	Vector2 vel = sub.Normalized() * maxDelta;
	Vector2 towards = (vel.LengthSquared() < sub.LengthSquared()) ? vel : sub;
	return from + towards;
}

bool Vector2::CrossPoint(Vector2* vec1_gool, Vector2* vec2_start, Vector2* vec2_gool, Vector2* output)
{
	Vector2 p1 = { this->x,this->y };
	Vector2 p2 = *vec1_gool;
	Vector2 p3 = *vec2_start;
	Vector2 p4 = *vec2_gool;

	float d = (p2.x - p1.x) * (p4.y - p3.y) - (p2.y - p1.y) * (p4.x - p3.x);
	if (d == 0)
	{
		return false;
	}
	float u = ((p3.x - p1.x) * (p4.y - p3.y) - (p3.y - p1.y) * (p4.x - p3.x)) / d;
	float v = ((p3.x - p1.x) * (p2.y - p1.y) - (p3.y - p1.y) * (p2.x - p1.x)) / d;

	// ���̃u���b�N�������ƁA�������m�̌�_�ɂȂ�܂�
	{
		if (u < 0.0 || u > 1.0)
		{
			return false;
		}
		if (v < 0.0 || v > 1.0)
		{
			return false;
		}
	}
	*output = { p1.x + u * (p2.x - p1.x) ,p1.y + u * (p2.y - p1.y) };

	return true;
}