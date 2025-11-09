cmake_minimum_required(VERSION 4.0)
project(AdvancedProgramming_PacMan)

set(CMAKE_CXX_STANDARD 20)
set(SFML_DIR "C:/Users/Youssef/Downloads/SFML-2.6.2-windows-gcc-13.1.0-mingw-64-bit/SFML-2.6.2/lib/cmake/SFML")
find_package(SFML 2.5 REQUIRED COMPONENTS
        graphics window system)
add_executable(AdvancedProgramming_PacMan main.cpp
        Game.cpp
        Game.h
        StateManager.cpp
        StateManager.h
        State.cpp
        State.h
        World.cpp
        World.h
        Entity.cpp
        Entity.h)
target_link_libraries(AdvancedProgramming_PacMan sfml-graphics sfml-window sfml-system)
