#include <SFML/Graphics.hpp>
#include "Frameworks.h"
#include <list>

#include "PongObject/Ball.h"
#include "PongObject/Bat.h"
#include "PongObject/Block.h"
#include "PongObject/BlockGenerator.h"

#include <iostream>

using namespace sf;
using namespace std;

int main()
{
	int width = 1000;
	int height = 800;
	FRAMEWORK->Init(width, height);
	FRAMEWORK->Do();
	return 0;
}

	//sf::RenderWindow window(sf::VideoMode(width, height), "Pong!", Style::Default);

	//Vector2f initPos(width * 0.5f, height - 25.f);

	//Bat bat;
	//bat.SetOrigin(Origins::TC);
	//bat.SetPosition(initPos);
	//bat.SetSpeed(1000.f);

	//Ball ball;
	//ball.SetOrigin(Origins::BC);
	//ball.SetPosition(initPos);

	//Font font;
	//font.loadFromFile("fonts/DNFBitBitTTF.ttf");

	//Text hud;
	//hud.setFont(font);
	//hud.setCharacterSize(75);
	//hud.setFillColor(Color::White);
	//hud.setPosition({ 20, 10 });

	//bool ballActive = true;
	//int life = 3;
	//int score = 0;

	//list<Block*> blocks = BlockGenerator::GetBlocks(width, 40, 25, 1);

	//RectangleShape ceil(Vector2f(width, 2));
	//ceil.setFillColor(Color::Red);
	//ceil.setPosition(0, 96);

	//InputManager::Init();
	//Clock clock;
	//while (window.isOpen())
	//{
	//	Time dt = clock.restart();
	//	Event event;
	//	InputManager::Update(dt.asSeconds());
	//	while (window.pollEvent(event))
	//	{
	//		if (event.type == sf::Event::Closed)
	//			window.close();

	//		InputManager::ProcessInput(event);
	//	}

	//	if (InputManager::GetKeyDown(Keyboard::Key::Space))
	//	{
	//		ball.Fire(Utils::Normalize({ 1, -2 }), 1000.f);
	//		ballActive = true;
	//	}

	//	if (InputManager::GetKeyDown(Keyboard::Key::Escape))
	//	{
	//		window.close();
	//	}

	//	bat.Update(dt.asSeconds());

	//	if (!ballActive)
	//	{
	//		ball.SetPosition(bat.GetPosition());
	//		ball.Fire({ 0, 0 }, 0);
	//	}

	//	ball.Update(dt.asSeconds());

	//	// 충돌처리
	//	if (ballActive)
	//	{
	//		FloatRect ballRect = ball.GetBounds();
	//		if (ballRect.top < 100.f)
	//		{
	//			ball.OnCollisionTop();
	//		}
	//		if (ballRect.left < 0.f ||
	//			ballRect.left + ballRect.width > width)
	//		{
	//			ball.OnCollisionSides(width);
	//		}
	//		if (ballRect.top + ballRect.height > height)
	//		{
	//			ball.OnCollisionBottom();
	//			ballActive = false;

	//			life--;
	//			if (life <= 0)
	//			{
	//				score = 0;
	//				life = 3;
	//			}
	//		}
	//		if (ballRect.intersects(bat.GetBounds()))
	//		{
	//			ball.OnCollisionBat();
	//			score++;
	//		}
	//		for (auto it = blocks.begin(); it != blocks.end();)
	//		{
	//			if (ballRect.intersects((*it)->GetBounds()))
	//			{
	//				ball.OnCollisionBlock(*it);
	//				delete (*it);
	//				it = blocks.erase(it);
	//				break;
	//			}
	//			else
	//				it++;
	//		}
	//	}

	//	string hudText =
	//		"Score: " + to_string(score) +
	//		"\tLife: " + to_string(life);
	//	hud.setString(hudText);

	//	window.clear();
	//	for (auto i : blocks)
	//	{
	//		i->Draw(window);
	//	}
	//	bat.Draw(window);
	//	ball.Draw(window);
	//	window.draw(hud);

	//	window.draw(ceil);
	//	window.display();
	//}