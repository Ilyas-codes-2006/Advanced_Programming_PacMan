//
// Created by Youssef on 13/11/2025.
//

#include "EntityModel.h"

#include <iostream>

/**
 * @Functionality Getters and Setters for the pacman entity.
 *
 * @Explanation /.
 */
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
int PacMan::getlives() {
    return lives;
}
void PacMan::setLives(int life) {
    lives = life;
}
/**
 * @Functionality Getters and Setters for the ghost entities.
 *
 * @Explanation /.
 */
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



