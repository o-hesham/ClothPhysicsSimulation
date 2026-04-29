#ifndef MOUSE_H
#define MOUSE_H

#include "Math/Vec2.h"

class Mouse
{
private:
    Vec2 pos;
    Vec2 prevPos;

    float cursorSize = 20;
    float maxCursorSize = 100;
    float minCursorSize = 20;

    bool leftButton = false;
    bool rightButton = false;

public:
    Mouse() = default;
    ~Mouse() = default;

    void UpdatePosition(int x, int y);
    const Vec2 &GetPosition() const { return pos; }
    const Vec2 &GetPreviousPosition() const { return prevPos; }

    bool GetLeftMouseButton() const { return leftButton; }
    void SetLeftMouseButton(bool state) { leftButton = state; }

    bool GetRightMouseButton() const { return rightButton; }
    void SetRightMouseButton(bool state) { rightButton = state; }

    void IncreaseCursorSize(float increment);
    float GetCursorSize() const { return cursorSize; }
};

#endif
