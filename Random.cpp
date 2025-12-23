//
// Created by Youssef on 22/12/2025.
//

#include "Random.h"

Random &Random::getInstance() {
    static Random instance;
    return instance;
}