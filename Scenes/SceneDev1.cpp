#include "SceneDev1.h"
#include "SceneManager.h"
#include "../Framework/InputManager.h"
#include "../Framework/ResourceManager.h"
#include "../Framework/SoundManager.h"
#include "../GameObject/TextObject.h"

SceneDev1::SceneDev1()
	:Scene(Scenes::Dev1)
{
}

SceneDev1::~SceneDev1()
{
}

void SceneDev1::Enter()
{
	cout << "scene1 enter" << endl;
}

void SceneDev1::Exit()
{
	cout << "scene1 exit" << endl;
    SOUND_MGR->StopAll();
}

void SceneDev1::Update(float dt)
{
	if (InputManager::GetKeyDown(Keyboard::Key::Space))
		SCENE_MGR->ChangeScene(Scenes::Dev2);
    
    Scene::Update(dt);
}

void SceneDev1::Draw(RenderWindow& window)
{
    Scene::Draw(window);
}