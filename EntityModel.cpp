//
// Created by Youssef on 13/11/2025.
//

#include "EntityModel.h"

#include <iostream>

void PacMan::update(float deltaTime) {
    /*auto position = getPosition();
    this->setPrevPosition(position);
    float speed = 0.3;
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
    this->setCurrentPosition(getPosition());*/
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
tuple<float,float> PacMan::getcurrentPosition() {
    return current_position;
}

void PacMan::setCurrentPosition(tuple<float,float> cur) {
    current_position = cur;
}

tuple<float,float> PacMan::getPrevPosition() {
    return previous_position;
}

void PacMan::setPrevPosition(tuple<float,float> prev) {
    previous_position = prev;
}
void Ghost::update(float deltaTime) {
    /*auto position = getPosition();
    this->setPrevPosition(position);
    float speed = 0.3;
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
    this->setCurrentPosition(getPosition());*/
}
char Ghost::getcurrentDirection() const {
    return currentDirection;
}

void Ghost::setCurrentDirection(char current_direction) {
    currentDirection = current_direction;
}

tuple<float,float> Ghost::getcurrentPosition() {
    return current_position;
}

void Ghost::setCurrentPosition(tuple<float,float> cur) {
    current_position = cur;
}

tuple<float,float> Ghost::getPrevPosition() {
    return previous_position;
}

void Ghost::setPrevPosition(tuple<float,float> prev) {
    previous_position = prev;
}
bool Ghost::getFearmode() {
    return fearmode;
}
void Ghost::setFearmode(bool fear) {
    fearmode = fear;
}
void Ghost::setFeartime(float fear) {
    feartime = fear;
}
float Ghost::getFeartime() {
    return feartime;
}




/*shared_ptr<EntityModel> Coin::interacts(shared_ptr<EntityModel> pacman) {
    if (pacman->getPosition() == this->getPosition()) {
        setInteracted(true);
    }
    return nullptr;
}
shared_ptr<EntityModel> Wall::interacts(shared_ptr<EntityModel> PacMan) {
    auto pac = PacMan->getPosition();
    auto wall = getPosition();
    if (wall == pac) {
        auto prevpes = PacMan->getPrevPosition();
        PacMan->setPosition(prevpes);
    }
    return nullptr;
}*/


