# Cloth Physics Simulation Documentation

## API Reference

### Classes

#### Application

Main application class that handles initialization, game loop, and cleanup.

```cpp
class Application {
public:
    void Setup(int width, int height, int cloth_size);
    bool IsRunning() const;
    void Input();
    void Update();
    void Render();
    void Destroy();
};
```

#### Cloth

Represents the cloth object with physics simulation.

```cpp
class Cloth {
public:
    Cloth(int width, int height, float spacing);
    void Update(float deltaTime);
    void Render(Renderer& renderer);
    void Reset();
};
```

#### Point

Individual particle in the cloth simulation.

```cpp
class Point {
public:
    Vec2 position;
    Vec2 old_position;
    Vec2 acceleration;
    bool pinned;

    void Update(float deltaTime);
    void Constrain(float x, float y, float width, float height);
};
```

#### Stick

Constraint between two points (spring connection).

```cpp
class Stick {
public:
    Point* p1;
    Point* p2;
    float rest_length;
    float stiffness;

    void Update();
    void Render(Renderer& renderer);
};
```

## Physics Implementation

### Verlet Integration

The simulation uses Verlet integration for stable physics:

```cpp
// Position update
new_pos = 2 * current_pos - old_pos + acceleration * dt²
```

### Constraint Satisfaction

Distance constraints maintain cloth structure:

```cpp
// Constraint relaxation
float distance = length(p1.pos - p2.pos);
float difference = (rest_length - distance) / distance;
Vec2 translate = (p1.pos - p2.pos) * difference * 0.5f;
```

## Performance Optimization

### Spatial Partitioning

Consider implementing spatial partitioning for large cloth grids to reduce collision detection complexity.

### Multi-threading

The physics update loop can be parallelized for better performance on multi-core systems.

### Memory Management

Use object pooling for dynamic objects to reduce memory allocations during runtime.

## Configuration

### Simulation Parameters

Modify these constants in `Application.cpp`:

```cpp
const float GRAVITY = 981.0f;        // Gravity acceleration
const float DAMPING = 0.99f;         // Velocity damping
const int CONSTRAINT_ITERATIONS = 3;  // Constraint solving iterations
const float TIME_STEP = 1.0f / 60.0f; // Fixed time step
```

### Cloth Properties

Adjust cloth behavior:

```cpp
const float STIFFNESS = 1.0f;        // Spring stiffness
const float REST_LENGTH = 10.0f;     // Default stick length
const int CLOTH_WIDTH = 40;          // Cloth grid width
const int CLOTH_HEIGHT = 30;         // Cloth grid height
```

## Build Configuration

### Compiler Flags

For optimal performance:

```bash
# Release build with optimizations
g++ -O2 -DNDEBUG -march=native

# Debug build with symbols
g++ -g -DDEBUG -Wall -Wextra
```

### SDL2 Setup

Windows (MinGW):

```bash
# Include paths
-I./include -I./vendor/SDL2/include

# Library paths and linking
-L./lib -lmingw32 -lSDL2main -lSDL2
```

Linux:

```bash
# Using pkg-config
$(pkg-config --cflags --libs sdl2)
```

## Troubleshooting

### Common Build Issues

1. **SDL2 not found**: Ensure SDL2 development libraries are installed
2. **Linker errors**: Check library order (mingw32, SDL2main, SDL2)
3. **Runtime crashes**: Verify SDL2 DLLs are in PATH or executable directory

### Performance Issues

1. **Low FPS**: Reduce cloth grid size or constraint iterations
2. **High memory usage**: Implement object pooling
3. **CPU spikes**: Add frame rate limiting

## Examples

### Basic Usage

```cpp
#include "Application.h"

int main(int argc, char* argv[]) {
    Application app;

    // Initialize with window size and cloth grid size
    app.Setup(1200, 800, 40);

    // Main loop
    while (app.IsRunning()) {
        app.Input();   // Handle user input
        app.Update();  // Update physics
        app.Render();  // Draw everything
    }

    app.Destroy();
    return 0;
}
```

### Custom Cloth Configuration

```cpp
// Create cloth with specific properties
Cloth cloth(50, 30, 15.0f);  // 50x30 grid, 15 pixel spacing

// Pin corners
cloth.GetPoint(0, 0)->pinned = true;
cloth.GetPoint(49, 0)->pinned = true;

// Apply wind force
for (auto& point : cloth.GetPoints()) {
    point.acceleration.x += wind_force;
}
```

## Architecture

### Class Hierarchy

```
Application
├── Renderer
├── Mouse
└── Cloth
    ├── Point[]
    └── Stick[]
```

### Data Flow

1. **Input**: Mouse and keyboard events
2. **Physics**: Update point positions and constraints
3. **Rendering**: Draw points and connections
4. **Timing**: Maintain consistent frame rate

### Extension Points

- **Physics**: Add new constraint types
- **Rendering**: Implement texturing or shaders
- **Input**: Add GUI controls
- **Export**: Save simulation state
