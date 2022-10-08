#include "SceneDev2.h"
#include "SceneManager.h"
#include "../Framework/InputManager.h"
#include "../Framework/ResourceManager.h"
#include "../Framework/SoundManager.h"
#include "../GameObject/TextObject.h"

SceneDev2::SceneDev2()
	:Scene(Scenes::Dev2)
{
}

SceneDev2::~SceneDev2()
{
}

void SceneDev2::Enter()
{
	cout << "scene2" << endl;
}

void SceneDev2::Exit()
{
	cout << "scene2 exit" << endl;
    SOUND_MGR->StopAll();
}

void SceneDev2::Update(float dt)
{
	if (InputManager::GetKeyDown(Keyboard::Key::Space))
		SCENE_MGR->ChangeScene(Scenes::Dev1);

    Scene::Update(dt);
}

void SceneDev2::Draw(RenderWindow& window)
{
    Scene::Draw(window);
}