#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include <vector>
#include <map>

using namespace sf;
using namespace std;

enum class Axis
{
    Horizontal,
    Vertical
};

struct AxisInfo
{
    Axis axis;
    list<Keyboard::Key> positives;
    list<Keyboard::Key> negatives;

    float sensi;
    float value;
};

class InputManager
{
private:
    static map<Axis, AxisInfo> axisInfoMap;
    static vector<bool> downList;
    static vector<bool> ingList;
    static vector<bool> upList;

public:
    static void Init();
    static void Update(float dt);
    static void ProcessInput(Event& ev);

    static bool GetKeyDown(Keyboard::Key key);
    static bool GetKey(Keyboard::Key key);
    static bool GetKeyUp(Keyboard::Key key);

    static float GetAxisRaw(Axis axis);
    static float GetAxis(Axis axis);
};