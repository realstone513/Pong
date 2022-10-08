#include "SceneManager.h"
#include "SceneDev1.h"
#include "SceneDev2.h"

Scenes SceneManager::GetCurrScene() const
{
	return currScene;
}

Scene* SceneManager::GetScene(Scenes scene)
{
	return sceneMap[scene];
}

bool SceneManager::Init()
{
	sceneMap[Scenes::Dev1] = new SceneDev1();
	sceneMap[Scenes::Dev2] = new SceneDev2();

	currScene = Scenes::Dev1;
	sceneMap[currScene]->Enter();
	return false;
}

void SceneManager::ChangeScene(Scenes scene)
{
	sceneMap[currScene]->Exit();
	currScene = scene;
	sceneMap[currScene]->Enter();
}

void SceneManager::Update(float dt)
{
	sceneMap[currScene]->Update(dt);
}

void SceneManager::Draw(RenderWindow& window)
{
	sceneMap[currScene]->Draw(window);
}