//
// Created by Youssef on 9/11/2025.
//

#include "Stopwatch.h"

Stopwatch &Stopwatch::getInstance() {
    static Stopwatch instance;
    return instance;
}
float Stopwatch::tick() {
    currentTime = std::chrono::steady_clock::now();
    deltaTime = currentTime - previousTime;
    previousTime = currentTime;
    return deltaTime.count();
}
void Stopwatch::reset() {
    previousTime = std::chrono::steady_clock::now();
}
