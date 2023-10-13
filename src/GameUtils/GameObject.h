// ===== ===== ===== ===== ===== ===== ===== =====
// @file	GameObject.h
// @brief	GameObjectクラス
// 
// @date	2023-10-13
// @update	2023-10-13
// 
// @author	UNLUCKY
// ===== ===== ===== ===== ===== ===== ===== =====

#pragma once

#include <entt.hpp>

#include "../Framework/Vector2.h"

class GameObject
{
protected:
	entt::registry* registry;
	entt::entity entity;

	bool isActive = true;
	bool isRendering = true;

	bool isCollision = false;

	int gh;		// グラフィックハンドル

	Vector2 position;

	std::string tag = "object";
	std::string collidedObjectTag = 0;

	entt::entity parent = entt::null;	// 親オブジェクト

public:
	GameObject()
		:registry(nullptr),
		entity(entt::null),
		gh(-1)
	{
	}

	GameObject(entt::registry* _pRegistry, entt::entity _entity, int _gh)
		:registry(_pRegistry),
		entity(_entity),
		gh(_gh)
	{
	}

	void Update()
	{
	}

	Vector2 GetPosition()
	{
		if (parent == entt::null)
		{
			return position;
		}
		
		Vector2 _position = position;
		Vector2 parentPosition = registry->get<GameObject>(parent).GetPosition();
		_position += parentPosition;
		return _position;
	}

	void SetPosition(Vector2 _pos)
	{
		if (parent == entt::null)
		{
			position = _pos;
		}
		else
		{
			Vector2 parentPosition = registry->get<GameObject>(parent).GetPosition();
			position = _pos - parentPosition;
		}
	}

	void SetParent(entt::entity _parent)
	{
		parent = _parent;
	}

	void Activate()
	{
		isActive = true;
	}

	void Deactivate()
	{
		isActive = false;
	}

	void ActivateRendering()
	{
		isRendering = true;
	}

	void DeactivateRendering()
	{
		isRendering = false;
	}

	bool IsActive()
	{
		return isActive;
	}

	bool IsRendering()
	{
		return isRendering;
	}

	void Collided()
	{
		isCollision = true;
	}

	void NotCollided()
	{
		isCollision = false;
	}

	bool IsCollision()
	{
		return isCollision;
	}

	std::string GetTag()
	{
		return tag;
	}

	void SetTag(std::string _tag)
	{
		tag = _tag;
	}

	std::string GetCollidedTag()
	{
		return collidedObjectTag;
	}

	void SetCollidedObjectTag(std::string _tag)
	{
		collidedObjectTag = _tag;
	}

};