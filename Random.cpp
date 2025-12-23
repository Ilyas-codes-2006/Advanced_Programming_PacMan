//
// Created by Youssef on 22/12/2025.
//

#include "Random.h"

Random &Random::getInstance() {
    static Random instance;
    instance.MersenneTw.seed(12345);
    return instance;
}
int Random::randomIndex(int start, int end) {
    std::uniform_int_distribution<int> dist(start,end);
    return dist(MersenneTw);
}
bool Random::probSwitch(float p) {
    std::uniform_real_distribution<float> dist(0.0f,1.0f);
    float value = dist(MersenneTw);
    if (value < p) {
        return true;
    }
    else {
        return false;
    }
}

