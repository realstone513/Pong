#include "SceneDev1.h"
#include "SceneManager.h"
#include "../Frameworks.h"
#include "../GameObject/SpriteObject.h"

SceneDev1::SceneDev1()
	: Scene(Scenes::Dev1)
{
}

SceneDev1::~SceneDev1()
{
}

void SceneDev1::Enter()
{
	SpriteObject* background = new SpriteObject();
	background->SetTexture(*RESOURCES_MGR->GetTexture("graphics/mokoko.png"));
	objList.push_back(background);

	Vector2i wSize = FRAMEWORK->GetWindowSize() / 2;
	string titleString = "PONG";
	float titleTextSize = 250;
	title = new TextObject(*RESOURCES_MGR->GetFont("fonts/DNFBitBitTTF.ttf"),
		titleString, wSize.x, wSize.y, Color(0, 204, 0, 255), 250);
	titleShadow = new TextObject(*RESOURCES_MGR->GetFont("fonts/DNFBitBitTTF.ttf"),
		titleString, wSize.x - 20, wSize.y + 10, Color(60, 60, 60, 255), 250);
	title->SetOrigin(Origins::BC);
	titleShadow->SetOrigin(Origins::BC);
	uiObjList.push_back(titleShadow);
	uiObjList.push_back(title);

	Scene::Enter();
}

void SceneDev1::Update(float dt)
{
	if (InputManager::GetKeyDown(Keyboard::Key::Space))
		SCENE_MGR->ChangeScene(Scenes::Dev2);

	if (InputManager::GetKeyDown(Keyboard::Key::Escape))
		FRAMEWORK->Exit();

	if (title->GetPosition().x > titleShadow->GetPosition().x - 15)
		titleShadow->Translate({ dt * 10, dt });
    
	Scene::Update(dt);
}

void SceneDev1::Draw(RenderWindow& window)
{
    Scene::Draw(window);
}

void SceneDev1::Exit()
{
	cout << "scene1 exit" << endl;
	SOUND_MGR->StopAll();

	Scene::Exit();
}