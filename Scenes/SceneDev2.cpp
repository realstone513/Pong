#include "SceneDev2.h"
#include "SceneManager.h"
#include "../Frameworks.h"

SceneDev2::SceneDev2()
	:Scene(Scenes::Dev2)
{
}

SceneDev2::~SceneDev2()
{
}

void SceneDev2::Init()
{
	Vector2i wSize = FRAMEWORK->GetWindowSize();
	bat = new Bat({ wSize.x * 0.5f, wSize.y - 25.f });
	ball = new Ball({ wSize.x * 0.5f, wSize.y - 25.f });
	hud = new TextObject(*RESOURCES_MGR->GetFont("fonts/DNFBitBitTTF.ttf"), "", 20.f, 10.f);

	objList.push_back(bat);
	objList.push_back(ball);
	uiObjList.push_back(hud);

	Scene::Init();
}

void SceneDev2::Enter()
{
	cout << "scene2" << endl;
	Scene::Enter();
}

void SceneDev2::Exit()
{
	Scene::Exit();
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