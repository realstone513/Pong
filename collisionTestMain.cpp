#include <SFML/Graphics.hpp>
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

	Ball balls[7];
	balls[0].SetOrigin(Origins::BC); // left
	balls[0].SetPosition({ 100, 300 });

	balls[1].SetOrigin(Origins::BC); // right
	balls[1].SetPosition({ 500, 300 });

	balls[2].SetOrigin(Origins::BC); // top
	balls[2].SetPosition({ 300, 150 });

	balls[3].SetOrigin(Origins::BC); // top left
	balls[3].SetPosition({ 100, 150 });

	balls[4].SetOrigin(Origins::BC); // top right
	balls[4].SetPosition({ 500, 150 });

	balls[5].SetOrigin(Origins::BC); // bottom left
	balls[5].SetPosition({ 100, 500 });

	balls[6].SetOrigin(Origins::BC); // bottom right
	balls[6].SetPosition({ 500, 500 });

	Font font;
	font.loadFromFile("fonts/DS-DIGI.TTF");

	Text hud;
	hud.setFont(font);
	hud.setCharacterSize(75);
	hud.setFillColor(Color::White);
	hud.setPosition({ 20, 10 });

	bool ballActive = true;
	int life = 13;
	int score = 5;

	Block block(280.f, 290.f, { 40, 20 });
	cout << block.GetCenterPos().x << " " << block.GetCenterPos().y << endl;

	RectangleShape ceil(Vector2f(width, 2));
	ceil.setFillColor(Color::Red);
	ceil.setPosition(0, 96);

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
			ball.Fire({ 0, -1 }, 2500.f);
			ballActive = true;
		}

		if (InputManager::GetKeyDown(Keyboard::Key::Escape))
		{
			window.close();
		}

		if (InputManager::GetKeyDown(Keyboard::Key::G))
		{
			balls[0].Fire({ 1, 0 }, 500.f);
		}

		if (InputManager::GetKeyDown(Keyboard::Key::J))
		{
			balls[1].Fire({ -1, 0 }, 500.f);
		}

		if (InputManager::GetKeyDown(Keyboard::Key::Y))
		{
			balls[2].Fire({ 0, 1 }, 500.f);
		}

		if (InputManager::GetKeyDown(Keyboard::Key::T))
		{
			balls[3].Fire({ 1, 1 }, 500.f);
		}

		if (InputManager::GetKeyDown(Keyboard::Key::U))
		{
			balls[4].Fire({ -1, 1 }, 500.f);
		}

		if (InputManager::GetKeyDown(Keyboard::Key::B))
		{
			balls[5].Fire({ 1, -1 }, 500.f);
		}

		if (InputManager::GetKeyDown(Keyboard::Key::M))
		{
			balls[6].Fire({ -1, -1 }, 500.f);
		}

		bat.Update(dt.asSeconds());

		if (!ballActive)
		{
			ball.SetPosition(bat.GetPosition());
			ball.Fire({ 0, 0 }, 0);
		}

		ball.Update(dt.asSeconds());

		for (int i = 0; i < 7; i++)
		{
			balls[i].Update(dt.asSeconds());

			if (balls[i].GetBounds().intersects(block.GetBounds()))
			{
				balls[i].OnCollisionBlock(&block);
				balls[i].SetSpeed(0);
				/*if (i == 0)
					balls[0].SetPosition({ 100, 300 });
				if (i == 1)
					balls[1].SetPosition({ 500, 300 });
				if (i == 2)
					balls[2].SetPosition({ 300, 150 });
				if (i == 3)
					balls[3].SetPosition({ 100, 150 });
				if (i == 4)
					balls[4].SetPosition({ 500, 150 });
				if (i == 5)
					balls[5].SetPosition({ 100, 500 });
				if (i == 6)
					balls[6].SetPosition({ 500, 500 });*/
			}
		}

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

			if (ballRect.intersects(block.GetBounds()))
			{
				ball.OnCollisionBlock(&block);
				/*ball.SetSpeed(0);
				ball.SetPosition(initPos);*/
				/*delete (*it);
				it = blocks.erase(it);
				break;*/
			}
		}

		string hudText =
			"Score: " + to_string(score) +
			"\tLife: " + to_string(life);
		hud.setString(hudText);

		window.clear();
		/*for (auto i : blocks)
		{
			i->Draw(window);
		}*/

		for (int i = 0; i < 7; i++)
		{
			balls[i].Draw(window);
		}

		bat.Draw(window);
		ball.Draw(window);
		block.Draw(window);
		window.draw(ceil);

		window.draw(hud);
		window.display();
	}

	return 0;
}