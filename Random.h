//
// Created by Youssef on 22/12/2025.
//

#ifndef ADVANCEDPROGRAMMING_PACMAN_RANDOM_H
#define ADVANCEDPROGRAMMING_PACMAN_RANDOM_H
#include <random>

class Random {
private:
    std::mt19937 MersenneTw;
    Random() = default;
    Random(const Random& random) = delete;
    Random& operator=(const Random& random) = delete;
public:
    static Random& getInstance();

};


#endif //ADVANCEDPROGRAMMING_PACMAN_RANDOM_H