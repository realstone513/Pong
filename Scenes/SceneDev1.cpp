#include "SceneDev1.h"
#include "SceneManager.h"
#include "../Frameworks.h"

SceneDev1::SceneDev1()
	:Scene(Scenes::Dev1)
{
}

SceneDev1::~SceneDev1()
{
}

void SceneDev1::Init()
{
	Vector2i wSize = FRAMEWORK->GetWindowSize() / 2;
	string titleString = "PONG";
	float titleTextSize = 250;
	title = new TextObject(*RESOURCES_MGR->GetFont("fonts/DNFBitBitTTF.ttf"),
		titleString, wSize.x, wSize.y, Color(0, 200, 200, 255), 250);
	titleShadow = new TextObject(*RESOURCES_MGR->GetFont("fonts/DNFBitBitTTF.ttf"),
		titleString, wSize.x - 20, wSize.y + 10, Color(60, 60, 60, 255), 250);
	title->SetOrigin(Origins::BC);
	titleShadow->SetOrigin(Origins::BC);
	uiObjList.push_back(titleShadow);
	uiObjList.push_back(title);

	Scene::Init();
}

void SceneDev1::Enter()
{
	cout << "scene1 enter" << endl;
	Scene::Enter();
}

void SceneDev1::Exit()
{
	Scene::Exit();
	cout << "scene1 exit" << endl;
    SOUND_MGR->StopAll();
}

void SceneDev1::Update(float dt)
{
	if (InputManager::GetKeyDown(Keyboard::Key::Space))
		SCENE_MGR->ChangeScene(Scenes::Dev2);
    
    Scene::Update(dt);
	if (title->GetPosition().x > titleShadow->GetPosition().x - 20)
		titleShadow->Translate({ dt * 10, dt });
}

void SceneDev1::Draw(RenderWindow& window)
{
    Scene::Draw(window);
}