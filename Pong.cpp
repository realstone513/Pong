#include <SFML/Graphics.hpp>
#include "InputManager.h"
#include "Ball.h"
#include "Bat.h"
#include <iostream>

using namespace sf;
using namespace std;

int main()
{
    int width = 1280;
    int height = 720;
    sf::RenderWindow window(sf::VideoMode(width, height), "Pong!", Style::Default);

    Ball ball;
    ball.SetPosition({ width / 2.f, width / 2.f });

    Bat bat;
    bat.SetPosition({ width * 0.5f, height - 20.f });
    bat.SetSpeed(1000.f);

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
            ball.Fire({ 0,1 }, 1500.f);
        }

        ball.Update(dt.asSeconds());

        window.clear();
        ball.Draw(window);


        bat.Update(dt.asSeconds());
        bat.Draw(window);
        window.display();
    }

    return 0;
}