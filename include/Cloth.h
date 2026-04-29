#ifndef CLOTH_H
#define CLOTH_H

#include <memory>
#include <vector>
#include "Point.h"
#include "Stick.h"

class Cloth
{
private:
    Vec2 gravity = {0.0f, 981.0f};
    float drag = 0.01f;
    float elasticity = 10.0f;

    std::vector<std::unique_ptr<Point>> points;
    std::vector<std::unique_ptr<Stick>> sticks;

public:
    Cloth() = default;
    Cloth(int width, int height, int spacing, int startX, int startY);
    ~Cloth() = default;

    void Update(Renderer *renderer, Mouse *mouse, float deltaTime);
    void Draw(Renderer *renderer) const;
};

#endif