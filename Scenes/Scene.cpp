#include "Scene.h"

Scene::Scene(Scenes type) :type(type)
{
}

Scene::~Scene()
{
}

void Scene::Enter()
{
    for (const auto& obj : objList)
    {
        obj->Init();
    }

    for (const auto& obj : uiObjList)
    {
        obj->Init();
    }
}

void Scene::Update(float dt)
{
    for (const auto& obj : objList)
    {
        if (obj->GetActive())
        {
            obj->Update(dt);
        }
    }

    for (const auto& obj : uiObjList)
    {
        if (obj->GetActive())
        {
            obj->Update(dt);
        }
    }
}

void Scene::Draw(RenderWindow& window)
{
    for (const auto& obj : objList)
    {
        if (obj->GetActive())
        {
            obj->Draw(window);
        }
    }

    for (const auto& obj : uiObjList)
    {
        if (obj->GetActive())
        {
            obj->Draw(window);
        }
    }
}

void Scene::Exit()
{
    for (const auto& obj : objList)
    {
        delete obj;
    }
    objList.clear();

    for (const auto& obj : uiObjList)
    {
        objList.clear();
    }
    uiObjList.clear();
}