#include "Framework.h"
#include "InputManager.h"
#include "ResourceManager.h"
#include "SoundManager.h"
#include "../3rd/SingleTon.h"
#include "../Scenes/SceneManager.h"
#include "../DataTable/DataTableManager.h"

Framework::Framework()
    : timeScale(1.f)
{
}

Framework::~Framework()
{
}

float Framework::GetDT() const
{
    return deltaTime.asSeconds() * timeScale;
}

float Framework::GetRealDT() const
{
    return deltaTime.asSeconds();
}

const Vector2i& Framework::GetWindowSize() const
{
    return windowSize;
}

bool Framework::Init(int width, int height)
{
    windowSize = { width, height };
    window.create(VideoMode(width, height), "Realstone's Pong");

    InputManager::Init();
  
    RESOURCES_MGR->LoadAll();
    SOUND_MGR->Init();
    DATATABLE_MGR->Init();
    SCENE_MGR->Init();

    return true;
}

bool Framework::Do()
{
    while (window.isOpen())
    {
        deltaTime = clock.restart();
        float dt = GetDT();
        InputManager::Update(dt);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            InputManager::ProcessInput(event);
        }

        window.clear();
        SOUND_MGR->Update(dt);
        SCENE_MGR->Update(dt);
        SCENE_MGR->Draw(window);
        window.display();
    }

    return true;
}

void Framework::Exit()
{
    window.close();
}