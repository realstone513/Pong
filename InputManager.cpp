#include "InputManager.h"
#include <iostream>
#include <algorithm>

vector<bool> InputManager::downList(Keyboard::KeyCount, false); //개수, 초기화(false)
vector<bool> InputManager::ingList(Keyboard::KeyCount, false);
vector<bool> InputManager::upList(Keyboard::KeyCount, false);
vector<int> InputManager::ingIdx;
map<Axis, AxisInfo> InputManager::axisInfoMap;

void InputManager::Init()
{
    //Horizontal
    AxisInfo info;
    info.axis = Axis::Horizontal;
    info.positives.push_back(Keyboard::Key::D);
    info.positives.push_back(Keyboard::Key::Right);
    info.negatives.push_back(Keyboard::Key::A);
    info.negatives.push_back(Keyboard::Key::Left);
    axisInfoMap.insert({ info.axis, info });
    //Vertical
    info.axis = Axis::Vertical;
    info.positives.push_back(Keyboard::Key::S);
    info.positives.push_back(Keyboard::Key::Down);
    info.negatives.push_back(Keyboard::Key::W);
    info.negatives.push_back(Keyboard::Key::Up);
    axisInfoMap.insert({ info.axis, info });

}

void InputManager::ClearInput()
{
    //fill(downList.begin(), downList.end(), false);
    //fill(upList.begin(), upList.end(), false);
    for (auto idx : ingIdx)
    {
        downList[idx] = false;
        upList[idx] = false;
    }
    ingIdx.clear();

}

void InputManager::UpdateInput(Event& ev)
{
    switch (ev.type)
    {
    case Event::EventType::KeyPressed:
        if (ev.key.code != Keyboard::Unknown && !ingList[ev.key.code]) //처음에 눌렀을때
        {
            downList[ev.key.code] = true;  //다운 true    ->  다음프레임(while다시시작) 에서 clear로 false로 변경
            ingList[ev.key.code] = true;   //ing true
            ingIdx.push_back(ev.key.code);
        }
        break;
    case Event::EventType::KeyReleased:
        if (ev.key.code != Keyboard::Unknown)
        {
            ingList[ev.key.code] = false;
            upList[ev.key.code] = true;
            ingIdx.push_back(ev.key.code);
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
    float v = 0.f;

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