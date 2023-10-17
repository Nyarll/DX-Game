// ===== ===== ===== ===== ===== ===== ===== =====
// @file	Vector2.h
// @brief	2D �x�N�g��
// 
// @date	2023-10-13
// @update	2023-10-13
// 
// @author	UNLUCKY
// ===== ===== ===== ===== ===== ===== ===== =====

#pragma once

class Vector2
{
private:
	float x, y;

public:

	static const Vector2 ZERO;

	Vector2();
	Vector2(const Vector2& vec);
	Vector2(float x, float y);
	Vector2(int x, int y);

	float GetX()
	{
		return x;
	}

	float GetY()
	{
		return y;
	}

	void SetX(float _x)
	{
		x = _x;
	}

	void SetY(float _y)
	{
		y = _y;
	}

	inline Vector2 operator +() const { return *this; }
	inline Vector2 operator -() const { return (*this) * (-1); }

	inline Vector2 operator +(const Vector2& other) const { return { x + other.x, y + other.y }; }
	inline Vector2 operator -(const Vector2& other) const { return { x - other.x, y - other.y }; }
	inline Vector2 operator *(const Vector2& scale) const { return { x * scale.x, y * scale.y }; }
	inline Vector2 operator *(const float scale) const { return { x * scale, y * scale }; }
	inline Vector2 operator /(const Vector2& scale) const { return { x / scale.x, y / scale.y }; }
	inline Vector2 operator /(const float scale) const { return { x / scale, y / scale }; }

	inline Vector2& operator +=(const Vector2& other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}

	inline Vector2& operator -=(const Vector2& other)
	{
		x -= other.x;
		y -= other.y;
		return *this;
	}

	inline Vector2& operator *=(const Vector2& scale)
	{
		x *= scale.x;
		y *= scale.y;
		return *this;
	}

	inline Vector2& operator *=(const float scale)
	{
		x *= scale;
		y *= scale;
		return *this;
	}

	inline Vector2& operator /=(const Vector2& scale)
	{
		x /= scale.x;
		y /= scale.y;
		return *this;
	}

	inline Vector2& operator /=(const float scale)
	{
		x /= scale;
		y /= scale;
		return *this;
	}

	bool operator==(const Vector2& p) { return ((static_cast<int>(this->x) == static_cast<int>(p.x)) && (static_cast<int>(this->y) == static_cast<int>(p.y))); };
	bool operator!=(const Vector2& p) { return ((static_cast<int>(this->x) != static_cast<int>(p.x)) && (static_cast<int>(this->y) != static_cast<int>(p.y))); };

	Vector2 Normalized();				// 2D�x�N�g���̐��K��
	float Dot(Vector2* vec);	// 2D�x�N�g�����m�̓���
	float Cross(Vector2* vec);	// 2D�x�N�g�����m�̊O��

	Vector2 Rotate(float rad);	// 2D�x�N�g����rad����]������

	float Angle();					// 2D�x�N�g���̊p�x
	float Angle2(Vector2* vec);	// 2D�x�N�g���Ԃ̊p�x
	float Length();					// 2D�x�N�g���̒���
	float LengthSquared();			// 2D�x�N�g���̒����̓��
	float LengthTo(Vector2* vec);// 2D�x�N�g���Ԃ̋���
	float LengthSquaredTo(Vector2* vec);	// 2D�x�N�g���Ԃ̋����̓��

	void Decompose(Vector2* vec, Vector2* outvec1, Vector2* outvec2);	// 2D�x�N�g���𕪉�

	Vector2 TranslateTowards(const Vector2& from, const Vector2& to, float maxDelta);

	bool CrossPoint(Vector2* vec1_gool, Vector2* vec2_start, Vector2* vec2_gool, Vector2* output);// �����Ɛ����̌�_�����߂�
};