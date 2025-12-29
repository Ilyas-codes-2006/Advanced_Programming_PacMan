//
// Created by Youssef on 20/12/2025.
//

#include "Score.h"

#include <iostream>

#include "Stopwatch.h"

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

