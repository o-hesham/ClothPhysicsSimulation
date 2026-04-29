#include <cstddef>
#include "Cloth.h"
#include "Point.h"
#include "Renderer.h"

// Builds a grid of points connected by sticks to form a cloth mesh.
// Each point is connected to its left and upper neighbor to form a grid of constraints.
Cloth::Cloth(int width, int height, int spacing, int startX, int startY)
{
    for (size_t y = 0; y <= height; y++)
    {
        for (size_t x = 0; x <= width; x++)
        {
            auto point = std::make_unique<Point>(startX + x * spacing, startY + y * spacing);

            // If not the first column, connect this point to the one on its left
            if (x != 0)
            {
                auto leftPoint = points[this->points.size() - 1].get();        // Get the previous point in the same row
                auto s = std::make_unique<Stick>(*point, *leftPoint, spacing); // Create a stick between this point and the one on the left
                // Register the stick with both points
                leftPoint->AddStick(s.get(), 0);
                point->AddStick(s.get(), 0);

                sticks.push_back(std::move(s));
            }

            // If not the first row, connect this point to the one above it
            if (y != 0)
            {
                auto upPoint = points[x + (y - 1) * (width + 1)].get();      // Access the point directly above in the grid
                auto s = std::make_unique<Stick>(*point, *upPoint, spacing); // Create a stick between this point and the one above
                // Register the stick with both points
                upPoint->AddStick(s.get(), 1);
                point->AddStick(s.get(), 1);

                sticks.push_back(std::move(s));
            }

            if (y == 0 && x % 2 == 0)
            {
                point->Pin();
            }

            points.push_back(std::move(point));
        }
    }
}

void Cloth::Update(Renderer *renderer, Mouse *mouse, float deltaTime)
{
    for (size_t i = 0; i < points.size(); i++)
    {
        points[i]->Update(deltaTime, drag, gravity, elasticity, mouse, renderer->GetWindowWidth(), renderer->GetWindowHeight());
    }

    for (size_t i = 0; i < sticks.size(); i++)
    {
        sticks[i]->Update();
    }
}

void Cloth::Draw(Renderer *renderer) const
{
    for (size_t i = 0; i < sticks.size(); i++)
    {
        sticks[i]->Draw(renderer);
    }
}