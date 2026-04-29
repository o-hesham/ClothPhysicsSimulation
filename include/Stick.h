#ifndef STICK_H
#define STICK_H

#include "Renderer.h"
#include "Point.h"

class Point;

class Stick
{
private:
    Point &p0;
    Point &p1;
    float length;

    bool isActive = true;
    bool isSelected = false;

    Uint32 color = 0xFF000000;
    Uint32 colorSelected = 0xFFCC0000;

public:
    Stick(Point &p0, Point &p1, float length);
    ~Stick() = default;

    void SetIsSelected(bool value);
    void Update();
    void Draw(const Renderer *renderer) const;
    void Break();
};

#endif