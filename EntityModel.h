//
// Created by Youssef on 13/11/2025.
//

#ifndef ADVANCEDPROGRAMMING_PACMAN_ENTITYMODEL_H
#define ADVANCEDPROGRAMMING_PACMAN_ENTITYMODEL_H

#include <string>
#include <tuple>
#include "Subject.h"
using namespace std;

class EntityModel: public Subject {
private:
    tuple<float,float> position;
    char symbol;
public:
    EntityModel(const tuple<float, float> &position, char symbol)
        : position(position),
          symbol(symbol) {
    }

    virtual void update(float deltaTime) = 0;

    tuple<float, float> getPosition() const {
        return position;
    }

    void setPosition(const tuple<float, float> &position) {
        this->position = position;
        notify();
    }

    [[nodiscard]] char getSymbol() const {
        return symbol;
    }
};
enum class Direction {
    None,
    Up,
    Down,
    Left,
    Right
};
class PacMan: public EntityModel {
private:
    Direction currentDirection = Direction::None;
    Direction nextDirection = Direction::None;
public:
    PacMan(const tuple<float, float> &position, char symbol)
        : EntityModel(position, symbol) {
    }

    void update(float deltaTime) override;
};
class Ghost: public EntityModel {
public:
    Ghost(const tuple<float, float> &position, char symbol)
        : EntityModel(position, symbol) {
    }

    void update(float deltaTime) override {}
};
class Wall: public EntityModel {
public:
    Wall(const tuple<float, float> &position, char symbol)
        : EntityModel(position, symbol) {
    }

    void update(float deltaTime) override {}
};
class Floor: public EntityModel {
public:
    Floor(const tuple<float, float> &position, char symbol)
        : EntityModel(position, symbol) {
    }

    void update(float deltaTime) override {}
};
class Collectable: public EntityModel {
public:
    Collectable(const tuple<float, float> &position, char symbol)
        : EntityModel(position, symbol) {
    }

    void update(float deltaTime) override {}
};


#endif //ADVANCEDPROGRAMMING_PACMAN_ENTITYMODEL_H