//
// Created by Youssef on 13/11/2025.
//

#include "EntityModel.h"

void PacMan::update(float deltaTime) {
    auto position = getPosition();
    float speed = 0.002;
    switch (getnextDirection()) {
        case 'u':
            setPosition({get<0>(position)*deltaTime,get<1>(position)-speed*deltaTime});
            break;
        case 'l':
            setPosition({get<0>(position)-speed*deltaTime,get<1>(position)*deltaTime});
            break;
        case 'r':
            setPosition({get<0>(position)+speed*deltaTime,get<1>(position)*deltaTime});
            break;
        case 'd':
            setPosition({get<0>(position)*deltaTime,get<1>(position)+speed*deltaTime});
            break;
    }
}
char PacMan::getcurrentDirection() const {
    return currentDirection;
}

void PacMan::setCurrentDirection(char current_direction) {
    currentDirection = current_direction;
}

char PacMan::getnextDirection() {
    return nextDirection;
}

void PacMan::setnextDirection(char next_direction) {
    nextDirection = next_direction;
}
