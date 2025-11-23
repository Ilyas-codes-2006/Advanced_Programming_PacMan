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
public:
    explicit EntityModel(const tuple<float, float> &position)
        : position(position) {
    }
    virtual void update(float deltaTime) = 0;

    tuple<float, float> getPosition() const {
        return position;
    }

    void setPosition(const tuple<float, float> &position) {
        this->position = position;
        notify();
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
    explicit PacMan(const tuple<float, float> &position)
        : EntityModel(position) {
    }
    void update(float deltaTime) override;
};
class Ghost: public EntityModel {
public:
    explicit Ghost(const tuple<float, float> &position)
        : EntityModel(position) {
    }
    void update(float deltaTime) override {}
};
class Wall: public EntityModel {
public:
    explicit Wall(const tuple<float, float> &position)
        : EntityModel(position) {
    }
    void update(float deltaTime) override {}
};
class Floor: public EntityModel {
public:
    explicit Floor(const tuple<float, float> &position)
        : EntityModel(position) {
    }
    void update(float deltaTime) override {}
};
class Collectable: public EntityModel {
public:
    explicit Collectable(const tuple<float, float> &position)
        : EntityModel(position) {
    }
    void update(float deltaTime) override {}
};


#endif //ADVANCEDPROGRAMMING_PACMAN_ENTITYMODEL_H