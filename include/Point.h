#ifndef POINT_H
#define POINT_H

#include <array>
#include <memory>
#include "Mouse.h"

class Stick;

class Point
{
private:
    std::array<Stick *, 2> sticks{nullptr, nullptr};

    Vec2 pos;
    Vec2 prevPos;
    Vec2 initPos;
    bool isPinned = false;

    bool isSelected = false;

    void KeepInsideView(int width, int height);

public:
    Point() = default;
    Point(float x, float y);
    ~Point() = default;

    void AddStick(Stick *stick, int index);

    const Vec2 &GetPosition() const { return pos; }
    void SetPosition(float x, float y);

    void Pin();

    void Update(float deltaTime, float drag, const Vec2 &acceleration, float elasticity, Mouse *mouse, int windowWidth, int windowHeight);
};

#endif
