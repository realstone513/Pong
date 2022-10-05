﻿#include <SFML/Graphics.hpp>
#include "InputManager.h"
#include "Ball.h"
#include "Bat.h"
#include "Utils.h"
#include <iostream>

using namespace sf;
using namespace std;

int main()
{
    int width = 1280;
    int height = 720;
    sf::RenderWindow window(sf::VideoMode(width, height), "Pong!", Style::Default);

    Vector2f initPos(width * 0.5f, height - 25.f);

    Bat bat;
    bat.SetOrigin(Origins::TC);
    bat.SetPosition(initPos);
    bat.SetSpeed(1000.f);

    Ball ball;
    ball.SetOrigin(Origins::BC);
    ball.SetPosition(initPos);

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
        if (Keyboard::isKeyPressed(Keyboard::Key::Space))
        {
            ball.Fire(Utils::Normalize({ 1, -1 }), 1500.f);
        }

        bat.Update(dt.asSeconds());
        ball.Update(dt.asSeconds());

        // 충돌처리
        FloatRect ballRect = ball.GetBounds();

        if (ballRect.top < 0.f)
        {
            ball.OnCollisionTop();
        }
        if (ballRect.left < 0.f || ballRect.left + ballRect.width > width)
        {
            ball.OnCollisionSides();
        }
        if (ballRect.top + ballRect.height > height)
        {
            ball.OnCollisionBottom();
        }
        if (ballRect.intersects(bat.GetBounds()))
        {
            ball.OnCollisionBat();
        }


        window.clear();
        bat.Draw(window);
        ball.Draw(window);
        window.display();
    }

    return 0;
}