#include "SceneDev2.h"
#include "SceneManager.h"
#include "../Frameworks.h"
#include "../GameObject/SpriteObject.h"

SceneDev2::SceneDev2()
	: Scene(Scenes::Dev2), ballActive(false), life(3), score(0), curStage(1), clearGame(false)
{
}

SceneDev2::~SceneDev2()
{
}

void SceneDev2::Enter()
{
	SpriteObject* background = new SpriteObject();
	background->SetTexture(*RESOURCES_MGR->GetTexture("graphics/mokoko.png"));
	objList.push_back(background);

	life = 3;
	score = 0;
	curStage = 1;

	SOUND_MGR->Play("sound/pong_bgm.wav", 50.f, true);

	wSize = FRAMEWORK->GetWindowSize();
	initPos = { wSize.x * 0.5f, wSize.y - 25.f };
	bat = new Bat(initPos);
	ball = new Ball(initPos);
	hud = new TextObject(*RESOURCES_MGR->GetFont("fonts/DNFBitBitTTF.ttf"), "", 10.f, 0.f);
	if (!bg.GetBlocks(blocks, wSize.x, curStage))
		return;
	ceil.setSize(Vector2f(wSize.x, 2));
	ceil.setFillColor(Color::Cyan);
	ceil.setPosition(0, 98);

	objList.push_back(bat);
	objList.push_back(ball);
	uiObjList.push_back(hud);

	Scene::Enter();
}

void SceneDev2::Update(float dt)
{
	if (InputManager::GetKeyDown(Keyboard::Key::Escape))
	{
		ballActive = false;
		SCENE_MGR->ChangeScene(Scenes::Dev1);
		return ;
	}

	if (InputManager::GetKeyDown(Keyboard::Key::Space))
	{
		if (ballActive == false)
		{
			ball->Fire(Utils::Normalize({ Utils::Random(-1.f, 1.f), -1 }), 800.f);
			ballActive = true;
		}
	}

	if (blocks.size() == 0 || InputManager::GetKeyDown(Keyboard::Key::C))
	{
		for (const auto& obj : blocks)
		{
			delete obj;
		}
		blocks.clear();
		ball->Init();
		bat->Init();
		ballActive = false;

		if (!bg.GetBlocks(blocks, wSize.x, ++curStage))
			clearGame = true;
	}
	
	if (clearGame)
	{

	}

	if (!ballActive)
	{
		ball->SetPosition(bat->GetPosition());
		ball->Fire({ 0, 0 }, 0);
	}

	if (ballActive)
	{
		FloatRect ballRect = ball->GetBounds();
		if (ballRect.top < 100.f)
		{
			ball->OnCollisionTop();
		}
		if (ballRect.left < 0.f ||
			ballRect.left + ballRect.width > wSize.x)
		{
			ball->OnCollisionSides(wSize.x);
		}
		if (ballRect.top + ballRect.height > wSize.y)
		{
			ball->OnCollisionBottom();
			ballActive = false;

			life--;
			ball->SetPosition(initPos);
			if (life <= 0)
			{
				Exit();
				Enter();
			}
		}
		if (ballRect.intersects(bat->GetBounds()))
		{
			ball->OnCollisionBat(bat);
			score++;
		}
		for (auto it = blocks.begin(); it != blocks.end();)
		{
			if (ballRect.intersects((*it)->GetBounds()))
			{
				ball->OnCollisionBlock(*it);
				(*it)->Hit();
				if ((*it)->hp == 0)
					SOUND_MGR->Play("sound/hit_soft_block.wav");
				else
					SOUND_MGR->Play("sound/hit_hard_block.wav");
				hitBlocks.push_back(*it);
				it = blocks.erase(it);
				break;
			}
			else
				it++;
		}
	}

	for (auto it = hitBlocks.begin(); it != hitBlocks.end();)
	{
		(*it)->Update(dt);
		if ((*it)->GetActive())
		{
			if ((*it)->hp > 0)
				blocks.push_back(*it);
			delete (*it);
			it = hitBlocks.erase(it);
		}
		else
			it++;
	}

	string hudText =
		"Score: " + to_string(score) +
		"\t\t\t\t\tLife: " + to_string(life);
	hud->SetString(hudText);

    Scene::Update(dt);
}

void SceneDev2::Draw(RenderWindow& window)
{
	Scene::Draw(window);

	for (const auto& obj : blocks)
	{
		if (obj->GetActive())
			obj->Draw(window);
	}

	for (const auto& obj : hitBlocks)
	{
		obj->Draw(window);
	}
	window.draw(ceil);
}

void SceneDev2::Exit()
{
	cout << "scene2 exit" << endl;
	SOUND_MGR->StopAll();

	for (const auto& obj : blocks)
	{
		delete obj;
	}
	blocks.clear();

	Scene::Exit();
}