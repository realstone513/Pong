#include "InputManager.h"
//#include <iostream>
//#include <algorithm>

vector<bool> InputManager::downList(Keyboard::KeyCount, false);
vector<bool> InputManager::ingList(Keyboard::KeyCount, false);
vector<bool> InputManager::upList(Keyboard::KeyCount, false);
map<Axis, AxisInfo> InputManager::axisInfoMap;

void InputManager::Init()
{ 
    //Horizontal
    AxisInfo infoH;
    infoH.axis = Axis::Horizontal;
    infoH.positives.push_back(Keyboard::Key::D);
    infoH.positives.push_back(Keyboard::Key::Right);
    infoH.negatives.push_back(Keyboard::Key::A);
    infoH.negatives.push_back(Keyboard::Key::Left);
    infoH.sensi = 5.f;
    infoH.value = 0.f;
    
    axisInfoMap.insert({ infoH.axis, infoH });

    //Vertical
    AxisInfo infoV;
    infoV.axis = Axis::Vertical;
    infoV.positives.push_back(Keyboard::Key::S);
    infoV.positives.push_back(Keyboard::Key::Down);
    infoV.negatives.push_back(Keyboard::Key::W);
    infoV.negatives.push_back(Keyboard::Key::Up);
    infoV.sensi = 5.f;
    infoV.value = 0.f;

    axisInfoMap.insert({ infoV.axis, infoV });
}

void InputManager::Update(float dt)
{
    fill(downList.begin(), downList.end(), false);
    fill(upList.begin(), upList.end(), false);

    for (auto& it : axisInfoMap)
    {
        AxisInfo& axis = it.second;
        float raw = GetAxisRaw(axis.axis);
        if (raw == 0.f && axis.value != 0)
        {
            raw = axis.value > 0.f ? -1.f : 1.f;
        }
        axis.value += raw * axis.sensi * dt;

        if (axis.value > 1.0f)
            axis.value = 1.f;
        if (axis.value < -1.0f)
            axis.value = -1.f;
        if (abs(axis.value) < 0.001f)
            axis.value = 0.f;
    }
}

void InputManager::ProcessInput(Event& ev)
{
    switch (ev.type)
    {
    case Event::EventType::KeyPressed:
        if (ev.key.code != Keyboard::Key::Unknown &&
            !ingList[ev.key.code])
        {
            downList[(int)ev.key.code] = true;
            ingList[(int)ev.key.code] = true;
        }
        break;
    case Event::EventType::KeyReleased:
        if (ev.key.code != Keyboard::Key::Unknown)
        {
            ingList[(int)ev.key.code] = false;
            upList[(int)ev.key.code] = true;
        }
        break;
    }
}

bool InputManager::GetKeyDown(Keyboard::Key key)
{
    return downList[key];
}

bool InputManager::GetKey(Keyboard::Key key)
{
    return ingList[key];
}

bool InputManager::GetKeyUp(Keyboard::Key key)
{
    return upList[key];
}

float InputManager::GetAxisRaw(Axis axis)
{
    const AxisInfo& info = axisInfoMap[axis];

    for (auto key : info.negatives)
    {
        if (GetKey(key))
            return -1.f;
    }
    for (auto key : info.positives)
    {
        if (GetKey(key))
            return 1.f;
    }
    return 0;
}

float InputManager::GetAxis(Axis axis)
{
    return axisInfoMap[axis].value;
}