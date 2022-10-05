#include <SFML/Graphics.hpp>
#include "Bat.h"
#include "InputManager.h"
#include <iostream>

int main()
{
    int width = 1280;
    int height = 720;
    sf::RenderWindow window(sf::VideoMode(width, height), "Pong!", Style::Default);

    Bat bat;
    bat.SetPosition({ width * 0.5f, height - 20.f });
    bat.SetSpeed(1000.f);

    InputManager::Init();
    Clock clock;
    while (window.isOpen())
    {
        Time dt = clock.restart();
        sf::Event event;

        InputManager::ClearInput();
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            InputManager::UpdateInput(event);
        }

        bat.Update(dt.asSeconds());

        window.clear();
        bat.Draw(window);
        window.display();
    }

    return 0;
}