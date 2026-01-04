//
// Created by Youssef on 22/12/2025.
//

#include "Random.h"
/**
 * @Functionality Pacman eats coin
 *
 * @Explanation We use the same system as for walls only now the hitboxes are much smaller
 * so it only triggers when we are almost in the middle. We also make use of an event here.
 * To tell our view that the coin needs to disappear. The coin itself gets deleted from
 * eatenEntities and also all the entities.
 */
Random &Random::getInstance() {
    static Random instance;
    return instance;
}
/**
 * @Functionality Pacman eats coin
 *
 * @Explanation We use the same system as for walls only now the hitboxes are much smaller
 * so it only triggers when we are almost in the middle. We also make use of an event here.
 * To tell our view that the coin needs to disappear. The coin itself gets deleted from
 * eatenEntities and also all the entities.
 */
int Random::randomIndex(int start, int end) {
    std::uniform_int_distribution<int> dist(start,end);
    return dist(MersenneTw);
}
/**
 * @Functionality Pacman eats coin
 *
 * @Explanation We use the same system as for walls only now the hitboxes are much smaller
 * so it only triggers when we are almost in the middle. We also make use of an event here.
 * To tell our view that the coin needs to disappear. The coin itself gets deleted from
 * eatenEntities and also all the entities.
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

