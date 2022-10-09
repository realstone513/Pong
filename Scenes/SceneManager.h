#pragma once
#include "Scene.h"
#include <SFML/Graphics.hpp>
#include <map>
#include "../3rd/SingleTon.h"

#define SCENE_MGR (SceneManager::GetInstance())

using namespace sf;
using namespace std;

class SceneManager : public Singleton<SceneManager>
{
private:
	map<Scenes, Scene*> sceneMap;
	Scenes currScene;

public:
	Scenes GetCurrScene() const;
	Scene* GetScene(Scenes scene);
	bool Init();
	void ChangeScene(Scenes scene);
	void Update(float dt);
	void Draw(RenderWindow& window);
};