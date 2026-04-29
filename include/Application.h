#ifndef APPLICATION_H
#define APPLICATION_H

#include <vector>
#include <memory>
#include <SDL.h>
#include "Mouse.h"
#include "Renderer.h"
#include "Cloth.h"

struct Application
{
private:
    std::unique_ptr<Renderer> renderer;
    std::unique_ptr<Mouse> mouse;
    std::unique_ptr<Cloth> cloth;

    bool isRunning = false;

    Uint32 lastUpdateTime;

public:
    Application() = default;
    ~Application() = default;

    bool IsRunning() const;

    void Setup(int clothWidth, int clothHeight, int clothSpacing);
    void Input();
    void Update();
    void Render() const;

    void Destroy();
};

#endif