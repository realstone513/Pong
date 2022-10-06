﻿#include <SFML/Graphics.hpp>
#include "InputManager.h"
#include "Ball.h"
#include "Bat.h"
#include "Block.h"
#include "BlockGenerator.h"
#include "Utils.h"
#include <list>
#include <iostream>

using namespace sf;
using namespace std;

int main()
{
	int width = 600;
	int height = 900;
	sf::RenderWindow window(sf::VideoMode(width, height), "Pong!", Style::Default);

	Vector2f initPos(width * 0.5f, height - 25.f);

	Bat bat;
	bat.SetOrigin(Origins::TC);
	bat.SetPosition(initPos);
	bat.SetSpeed(1000.f);

	Ball ball;
	ball.SetOrigin(Origins::BC);
	ball.SetPosition(initPos);

	Font font;
	font.loadFromFile("fonts/DS-DIGI.TTF");

	Text hud;
	hud.setFont(font);
	hud.setCharacterSize(75);
	hud.setFillColor(Color::White);
	hud.setPosition({ 20, 10 });

	bool ballActive = true;
	int life = 3;
	int score = 0;

	BlockGenerator bg(width, 15, 15);

	// generate blocks
	list<Block*> blocks = bg.GetBlocks();
	//int offset = 2;
	//int nextY = 100;
	//for (int y = 0; y < 10; y++)
	//{
	//	int nextX = offset;
	//	for (int x = 0; x < 15; x++)
	//	{
	//		Block* block = new Block(nextX, nextY);
	//		blocks.push_back(block);
	//		nextX += 38 + offset;
	//	}
	//	nextY += 30 + offset;
	//}

	InputManager::Init();
	Clock clock;
	while (window.isOpen())
	{
		Time dt = clock.restart();
		Event event;
		InputManager::ClearInput();
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			InputManager::UpdateInput(event);
		}

		if (InputManager::GetKeyDown(Keyboard::Key::Space))
		{
			ball.Fire(Utils::Normalize({ 1, -1 }), 2500.f);
			ballActive = true;
		}

		if (InputManager::GetKeyDown(Keyboard::Key::Escape))
		{
			window.close();
		}

		bat.Update(dt.asSeconds());

		if (!ballActive)
		{
			ball.SetPosition(bat.GetPosition());
			ball.Fire({ 0, 0 }, 0);
		}

		ball.Update(dt.asSeconds());

		// 충돌처리
		if (ballActive)
		{
			FloatRect ballRect = ball.GetBounds();
			if (ballRect.top < 100.f)
			{
				ball.OnCollisionTop();
			}
			if (ballRect.left < 0.f ||
				ballRect.left + ballRect.width > width)
			{
				ball.OnCollisionSides(width);
			}
			if (ballRect.top + ballRect.height > height)
			{
				ball.OnCollisionBottom();
				ballActive = false;

				life--;
				if (life <= 0)
				{
					score = 0;
					life = 3;
				}
			}
			if (ballRect.intersects(bat.GetBounds()))
			{
				ball.OnCollisionBat();
				score++;
			}
			for (auto it = blocks.begin(); it != blocks.end();)
			{
				if (ballRect.intersects((*it)->GetBounds()))
				{
					it = blocks.erase(it);
				}
				else
					it++;
			}
		}

		string hudText =
			"Score: " + to_string(score) +
			"\tLife: " + to_string(life);
		hud.setString(hudText);

		window.clear();
		for (auto i : blocks)
		{
			i->Draw(window);
		}
		bat.Draw(window);
		ball.Draw(window);
		window.draw(hud);
		window.display();
	}

	return 0;
}