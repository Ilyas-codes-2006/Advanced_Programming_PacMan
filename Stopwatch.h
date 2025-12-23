//
// Created by Youssef on 9/11/2025.
//

#ifndef ADVANCEDPROGRAMMING_PACMAN_STOPWATCH_H
#define ADVANCEDPROGRAMMING_PACMAN_STOPWATCH_H
#include <chrono>


class Stopwatch {
private:
    std::chrono::steady_clock::time_point previousTime = std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point currentTime;
    std::chrono::duration<float> deltaTime;
    Stopwatch() = default;
    Stopwatch(const Stopwatch& stopwatch) = delete;
    Stopwatch& operator=(const Stopwatch& stopwatch) = delete;
public:
    static Stopwatch& getInstance();
    float tick();
};


#endif //ADVANCEDPROGRAMMING_PACMAN_STOPWATCH_H