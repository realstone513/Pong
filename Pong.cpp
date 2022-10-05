#include <SFML/Graphics.hpp>
#include "InputManager.h"
#include "Ball.h"
#include "Bat.h"
#include "Utils.h"
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
	hud.setPosition({ 20, 20 });

	bool ballActive = true;
	int life = 3;
	int score = 0;

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
			if (ballRect.top < 0.f)
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
		}

		string hudText =
			"Score: " + to_string(score) +
			"\tLife: " + to_string(life);
		hud.setString(hudText);

		window.clear();
		bat.Draw(window);
		ball.Draw(window);
		window.draw(hud);
		window.display();
	}

	return 0;
}