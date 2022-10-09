#include "SceneDev2.h"
#include "SceneManager.h"
#include "../Frameworks.h"

SceneDev2::SceneDev2()
	: Scene(Scenes::Dev2), ballActive(false)
{
}

SceneDev2::~SceneDev2()
{
}

void SceneDev2::Enter()
{
	SOUND_MGR->Play("sound/pong_bgm.wav", 50.f, true);

	wSize = FRAMEWORK->GetWindowSize();
	bat = new Bat({ wSize.x * 0.5f, wSize.y - 25.f });
	ball = new Ball({ wSize.x * 0.5f, wSize.y - 25.f });
	hud = new TextObject(*RESOURCES_MGR->GetFont("fonts/DNFBitBitTTF.ttf"), "", 10.f, 0.f);
	blocks = BlockGenerator::GetBlocks(wSize.x, 20, 5, 1);

	ceil.setSize(Vector2f(wSize.x, 2));
	ceil.setFillColor(Color::Cyan);
	ceil.setPosition(0, 98);

	objList.push_back(bat);
	objList.push_back(ball);
	uiObjList.push_back(hud);

	life = 3;
	score = 0;

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
		ball->Fire(Utils::Normalize({ 2, -1 }), 1000.f);
		ballActive = true;
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
			if (life <= 0)
			{
				score = 0;
				life = 3;
			}
		}
		if (ballRect.intersects(bat->GetBounds()))
		{
			ball->OnCollisionBat();
			score++;
		}
		for (auto it = blocks.begin(); it != blocks.end();)
		{
			if (ballRect.intersects((*it)->GetBounds()))
			{
				ball->OnCollisionBlock(*it);
				delete (*it);
				it = blocks.erase(it);
				SOUND_MGR->Play("sound/hit_soft_block.wav");
				break;
			}
			else
				it++;
		}
	}

	string hudText =
		"Score: " + to_string(score) +
		"\tLife: " + to_string(life);
	hud->SetString(hudText);

    Scene::Update(dt);
}

void SceneDev2::Draw(RenderWindow& window)
{
	for (const auto& obj : blocks)
	{
		if (obj->GetActive())
		{
			obj->Draw(window);
		}
	}
	window.draw(ceil);

	Scene::Draw(window);
}

void SceneDev2::Exit()
{
	cout << "scene2 exit" << endl;
	SOUND_MGR->StopAll();
	Scene::Exit();
}