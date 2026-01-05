//
// Created by Youssef on 22/12/2025.
//

#include "Random.h"
/**
 * @Functionality We return the instance needed for a Singleton.
 *
 * @Explanation /
 */
Random &Random::getInstance() {
    static Random instance;
    return instance;
}
/**
 * @Functionality We return a random number between start and end.
 *
 * @Explanation We use this function while were doing the ghost AI. The ghost gives how many ways he can go to. Stores them in a vector.
 * Then we retun a random index for that vector and the way is chosen.
 */
int Random::randomIndex(int start, int end) {
    std::uniform_int_distribution<int> dist(start,end);
    return dist(MersenneTw);
}
/**
 * @Functionality The 50/50 for changing ways.
 *
 * @Explanation We also use this function for ghost AI. SO we call this function to see the 50/50 chance if a ghost wants to change
 * ways or not.
 */
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

