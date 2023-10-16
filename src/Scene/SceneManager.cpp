#include "SceneManager.h"

#include "../Framework/Context/GameContext.h"
#include "IScene.h"

SceneManager::SceneManager()
	:activeScene(nullptr)
	,nextSceneID(SceneID::NONE)
{
	for (int i = 0; i < SceneID::NUM_SCENES; i++)
	{
		sceneFactoryMethods[i] = nullptr;
	}
}

SceneManager::~SceneManager()
{
	activeScene.reset();
}

void SceneManager::Register(SceneID _sceneID, FactoryMethod _factoryMethod)
{
	assert(_sceneID >= 0 && _sceneID < SceneID::NUM_SCENES && "Error : Invalid scene ID.");
	assert(_factoryMethod && "Error : Generation function is not specified.");

	if ((!(_sceneID >= 0 && _sceneID < SceneID::NUM_SCENES)) || (!(_factoryMethod)))
	{
		// TODO: Exit
		return;
	}
	sceneFactoryMethods[_sceneID] = _factoryMethod;
}

void SceneManager::SetStartScene(GameContext& context, SceneID _startScene)
{
	assert(_startScene >= 0 && _startScene < SceneID::NUM_SCENES && "Error : Invalid scene ID.");
	ChangeScene(context, _startScene);
}

void SceneManager::UpdateActiveScene(GameContext& context)
{
	assert(activeScene && "Error : There are no active scenes.");
	
	if (nextSceneID != SceneID::NONE)
	{
		ChangeScene(context, nextSceneID);
		nextSceneID = SceneID::NONE;
	}
	activeScene->Update(context);
}

void SceneManager::RenderActiveScene(GameContext& context)
{
	assert(activeScene && "Error : There are no active scenes.");
	activeScene->Render(context);
}

void SceneManager::RequestScene(SceneID _sceneID)
{
	assert(_sceneID >= 0 && _sceneID < SceneID::NUM_SCENES && "Error : Invalid scene ID.");
	nextSceneID = _sceneID;
}

void SceneManager::ChangeScene(GameContext& context, SceneID _sceneID)
{
	assert(_sceneID >= 0 && _sceneID < SceneID::NUM_SCENES && "Error : Invalid scene ID.");
	assert(sceneFactoryMethods[_sceneID] && "Error : Generation function is not specified.");

	if (activeScene != nullptr)
	{
		activeScene->Finalize(context);
		activeScene.reset();
	}

	activeScene.reset(sceneFactoryMethods[_sceneID]());
	activeScene->Initialize(context);
}
