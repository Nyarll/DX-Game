// ===== ===== ===== ===== ===== ===== ===== =====
// @file	SceneManager.h
// @brief	シーンマネージャ
// 
// @date	2023-10-16
// @update	2023-10-16
// 
// @author	UNLUCKY
// ===== ===== ===== ===== ===== ===== ===== =====

#pragma once

#include <memory>

class GameContext;
class IScene;

class SceneManager final
{
public:
	enum SceneID
	{
		NONE = -1,

		START_UP,
		TITLE,
		PLAY,
		RESULT,

		NUM_SCENES
	};

private:
	using FactoryMethod = IScene * (*)();

	std::unique_ptr<IScene> activeScene;
	SceneID nextSceneID;

	FactoryMethod sceneFactoryMethods[SceneID::NUM_SCENES];

public:
	SceneManager();
	~SceneManager();

	void Register(SceneID _sceneID, FactoryMethod _factoryMethod);

	void SetStartScene(GameContext& context, SceneID _startScene);

	void UpdateActiveScene(GameContext& context);

	void RenderActiveScene(GameContext& context);

	void RequestScene(SceneID _sceneID);

	IScene& GetActiveScene()
	{
		return *activeScene;
	}

private:
	void ChangeScene(GameContext& context, SceneID _sceneID);
};