//
// Created by Youssef on 13/11/2025.
//

#include "EntityModel.h"

void PacMan::update(float deltaTime) {
    auto position = getPosition();
    float speed = 0.2;
    float x = get<0>(position);
    float y = get<1>(position);
    switch (getnextDirection()) {
        case 'u':
            setPosition({x,y+(speed*deltaTime)});
            break;
        case 'd':
            setPosition({x,y-(speed*deltaTime)});
            break;
        case 'l':
            setPosition({x-(speed*deltaTime),y});
            break;
        case 'r':
            setPosition({x+(speed*deltaTime),y});
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
shared_ptr<EntityModel> Coin::interacts(shared_ptr<EntityModel> pacman) {
    if (pacman->getPosition() == this->getPosition()) {
        setInteracted(true);
    }
    return nullptr;
}

