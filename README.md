# Cloth Physics Simulation

A real-time cloth physics simulation built with SDL2 and C++. This project demonstrates particle-based cloth simulation with interactive mouse controls and realistic physics behavior.

![Cloth Physics Simulation](assets/demo.gif)

## Features

- **Real-time Physics**: Interactive cloth simulation with particle-based physics
- **Mouse Interaction**: Click and drag to interact with the cloth
- **Constraint System**: Spring-damper constraints for realistic cloth behavior
- **Efficient Rendering**: Hardware-accelerated rendering using SDL2
- **Cross-platform**: Runs on Windows, macOS, and Linux

## Screenshots

![Screenshot 1](assets/screenshot1.png)
_Interactive cloth simulation in action_

## Getting Started

### Prerequisites

- **C++ Compiler**: GCC/MinGW-w64, Clang, or MSVC with C++17 support
- **SDL2**: Graphics and input library
- **CMake**: Build system (optional, Makefile also provided)
- **Git**: Version control

### Installation

#### Windows (MinGW)

```bash
# Clone the repository
git clone https://github.com/yourusername/ClothPhysicsSimulation.git
cd ClothPhysicsSimulation

# Download SDL2 development libraries
# Extract to vendor/SDL2/ directory

# Build using Make
make

# Or build using CMake
mkdir build && cd build
cmake ..
cmake --build .
```

#### Linux/macOS

```bash
# Install SDL2 (Ubuntu/Debian)
sudo apt-get install libsdl2-dev libsdl2-image-dev

# Install SDL2 (macOS with Homebrew)
brew install sdl2 sdl2_image

# Clone and build
git clone https://github.com/yourusername/ClothPhysicsSimulation.git
cd ClothPhysicsSimulation
make
```

### Quick Start

1. **Clone the repository**
2. **Install SDL2 development libraries**
3. **Build the project**: `make` or use VS Code build tasks
4. **Run**: `./bin/ClothSim` (Linux/macOS) or `bin\ClothSim.exe` (Windows)

## Usage

### Controls

- **Left Mouse Button**: Grab and drag cloth points
- **Right Mouse Button**: Cut cloth connections
- **R Key**: Reset simulation
- **Space**: Pause/unpause simulation
- **ESC**: Exit application

### Configuration

Edit `src/Application.cpp` to modify simulation parameters:

- Grid size and resolution
- Physics constants (gravity, damping)
- Rendering options

## Project Structure

```
ClothPhysicsSimulation/
├── .vscode/                 # VS Code configuration
│   ├── tasks.json          # Build tasks
│   ├── launch.json         # Debug configuration
│   └── c_cpp_properties.json
├── src/                    # Source files
│   ├── Main.cpp           # Application entry point
│   ├── Application.cpp    # Main application class
│   ├── Cloth.cpp         # Cloth physics implementation
│   ├── Point.cpp         # Particle/point physics
│   ├── Stick.cpp         # Constraint/spring system
│   ├── Mouse.cpp         # Mouse interaction handling
│   └── Renderer.cpp      # SDL2 rendering
├── include/               # Header files
│   ├── Application.h
│   ├── Cloth.h
│   ├── Point.h
│   ├── Stick.h
│   ├── Mouse.h
│   ├── Renderer.h
│   └── Math/
│       └── Vec2.h        # 2D vector math
├── vendor/               # Third-party libraries
│   └── SDL2/            # SDL2 development libraries
├── bin/                 # Compiled executable
├── lib/                 # Static libraries
├── assets/              # Resources (textures, fonts)
├── docs/                # Documentation
├── tests/               # Unit tests
├── CMakeLists.txt       # CMake build configuration
├── Makefile             # Make build configuration
├── README.md            # This file
├── LICENSE              # License file
└── .gitignore          # Git ignore rules
```

## Building

### Using Make

```bash
# Debug build (default)
make

# Release build
make release

# Clean build files
make clean

# Install (Linux/macOS)
sudo make install
```

### Using CMake

```bash
# Configure
cmake -B build -DCMAKE_BUILD_TYPE=Release

# Build
cmake --build build

# Install
cmake --install build
```

### Using VS Code

1. Open project in VS Code
2. `Ctrl+Shift+P` → "Tasks: Run Build Task"
3. `F5` to run with debugger

## Physics Implementation

The simulation uses a particle-based approach with the following components:

### Particles (Points)

- Position, velocity, and acceleration
- Mass and inverse mass for dynamics
- Pinning constraints for fixed points

### Constraints (Sticks)

- Spring-damper model for cloth connections
- Rest length and stiffness parameters
- Satisfies distance constraints using Verlet integration

### Integration

- Verlet integration for stable physics
- Constraint relaxation for maintaining cloth structure
- Collision detection with boundaries

## Contributing

Contributions are welcome! Please follow these steps:

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

### Development Guidelines

- Follow C++ best practices and modern C++17 features
- Maintain consistent code style (see `.clang-format`)
- Add unit tests for new features
- Update documentation for API changes
- Ensure cross-platform compatibility

## Performance

The simulation is optimized for real-time performance:

- **Target**: 60 FPS at 40x40 cloth grid
- **Memory**: ~10MB typical usage
- **CPU**: Single-threaded, suitable for modern processors
- **Scalability**: Adjustable grid resolution for different hardware

## Dependencies

- **SDL2**: Graphics, input, and window management
- **SDL2_image**: Image loading (optional)
- **Standard Library**: C++17 STL

## Troubleshooting

### Common Issues

**Build Errors**

- Ensure SDL2 development libraries are installed
- Check compiler supports C++17
- Verify library paths in build configuration

**Runtime Issues**

- Ensure SDL2 DLLs are in PATH (Windows)
- Check graphics drivers are up to date
- Reduce grid size for better performance

**Performance Issues**

- Lower cloth resolution in `Application::Setup()`
- Disable VSync if needed
- Close other applications consuming GPU

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- SDL2 development team for the excellent multimedia library
- Physics simulation techniques inspired by academic research
- Community feedback and contributions

## Roadmap

- [ ] Multi-threading for larger cloth grids
- [ ] Collision detection with arbitrary objects
- [ ] Texture mapping and improved graphics
- [ ] Wind simulation effects
- [ ] Cloth tearing mechanics
- [ ] Export simulation data
- [ ] Interactive GUI controls

## Contact

- **Author**: Your Name
- **Email**: your.email@example.com
- **Project Link**: https://github.com/yourusername/ClothPhysicsSimulation
- **Issues**: https://github.com/yourusername/ClothPhysicsSimulation/issues

---

**Star ⭐ this repository if you find it helpful!**
