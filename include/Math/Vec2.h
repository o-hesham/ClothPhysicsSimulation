#ifndef VEC2_H
#define VEC2_H

struct Vec2
{
    float x, y;

    Vec2() : x(0), y(0) {}
    Vec2(float x, float y) : x(x), y(y) {}

    ~Vec2() = default;

    Vec2 operator+(const Vec2 &rhs) const
    {
        Vec2 result;
        result.x = x + rhs.x;
        result.y = y + rhs.y;

        return result;
    }

    Vec2 operator-(const Vec2 &rhs) const
    {
        Vec2 result;
        result.x = x - rhs.x;
        result.y = y - rhs.y;

        return result;
    }

    Vec2 operator*(const float n) const
    {
        Vec2 result;
        result.x = x * n;
        result.y = y * n;

        return result;
    }

    Vec2 operator/(const float n) const
    {
        Vec2 result;
        result.x = x / n;
        result.y = y / n;

        return result;
    }
};

#endif