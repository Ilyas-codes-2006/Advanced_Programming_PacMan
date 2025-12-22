//
// Created by Youssef on 20/12/2025.
//

#include "Score.h"
void Score::update(const Event &event) {
    if (event.type == WhichEvent::CoinPoint) {
        score+=100;
    }
    else if (event.type == WhichEvent::FruitGone) {
        score+=500;
    }
}

