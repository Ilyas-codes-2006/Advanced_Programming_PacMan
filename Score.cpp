//
// Created by Youssef on 20/12/2025.
//

#include "Score.h"

#include <iostream>

#include "Stopwatch.h"
/**
 * @Functionality Pacman eats coin
 *
 * @Explanation We use the same system as for walls only now the hitboxes are much smaller
 * so it only triggers when we are almost in the middle. We also make use of an event here.
 * To tell our view that the coin needs to disappear. The coin itself gets deleted from
 * eatenEntities and also all the entities.
 */
void Score::update(const Event &event) {
    if (event.type == WhichEvent::CoinPoint) {
        if (timeLasteaten < 5.0) {
            add += 10;
            timeLasteaten = 0;
        }
        score += add;
    }
    else if (event.type == WhichEvent::FruitGone) {
        score += add+500;
    }
    else if (event.type == WhichEvent::GhostEaten) {
        score += add+1000;
    }
    else if (event.type == WhichEvent::LevelCleared) {
        if (oneTime==0) {
            score += add+5000;
            oneTime = 1;
        }
    }
    else if (event.type == WhichEvent::NotEaten) {
        timeLasteaten += Stopwatch::getInstance().tick();
        if (timeLasteaten >= 1.0) {
            std::cout << "did not eat" << std::endl;
            std::cout << add << std::endl;
            add = add/10;
            std::cout << add << std::endl;
            timeLasteaten = 0;
        }
    }
}

