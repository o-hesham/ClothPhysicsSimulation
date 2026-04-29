#include <math.h>
#include "Stick.h"
#include "Point.h"

// Initializes a stick (constraint) between two points with a target length.
Stick::Stick(Point &p0, Point &p1, float length)
    : p0(p0), p1(p1), length(length) {}

// Updates the stick constraint, enforcing the target distance between p0 and p1.
void Stick::Update()
{
    if (!isActive)
        return;

    // Get the current positions of both points
    Vec2 p0Pos = p0.GetPosition();
    Vec2 p1Pos = p1.GetPosition();

    Vec2 diff = p0Pos - p1Pos;
    float dist = sqrtf(diff.x * diff.x + diff.y * diff.y); // Current distance between the two points
    float diffFactor = (length - dist) / dist;             // Compute how far off the current distance is from the rest length
    Vec2 offset = diff * diffFactor * 0.5f;                // Offset to apply equally in opposite directions to both points

    // Move both points to maintain the constraint distance
    // Each point gets moved halfway to preserve center stability
    p0.SetPosition(p0Pos.x + offset.x, p0Pos.y + offset.y);
    p1.SetPosition(p1Pos.x - offset.x, p1Pos.y - offset.y);
}

// Renders the stick (line) connecting the two points using the renderer.
// Draws with a different color if the stick is selected.
void Stick::Draw(const Renderer *renderer) const
{
    if (!isActive)
        return;

    Vec2 p0Pos = p0.GetPosition();
    Vec2 p1Pos = p1.GetPosition();

    renderer->DrawLine(p0Pos.x, p0Pos.y, p1Pos.x, p1Pos.y, isSelected ? colorSelected : color);
}

// Marks the stick as inactive (broken).
// This allows the cloth to tear dynamically.
void Stick::Break()
{
    isActive = false;
}

void Stick::SetIsSelected(bool value)
{
    isSelected = value;
}