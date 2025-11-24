//
// Created by Youssef on 13/11/2025.
//

#ifndef ADVANCEDPROGRAMMING_PACMAN_ENTITYMODEL_H
#define ADVANCEDPROGRAMMING_PACMAN_ENTITYMODEL_H

#include <string>
#include <tuple>
#include "Stopwatch.h"
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

    [[nodiscard]] virtual char getcurrentDirection() const = 0;

    virtual void setCurrentDirection(char currentDirection) = 0;

    [[nodiscard]] virtual char getnextDirection() = 0;

    virtual void setnextDirection(char nextDirection) = 0;

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

class PacMan: public EntityModel {
    char currentDirection = 'N';
    char nextDirection = 'N';
public:

    PacMan(const tuple<float, float> &position, char symbol)
        : EntityModel(position, symbol) {
    }

    [[nodiscard]] char getcurrentDirection() const override;

    void setCurrentDirection(char currentDirection) override;

    [[nodiscard]] char getnextDirection() override;

    void setnextDirection(char nextDirection) override;

    void update(float deltaTime) override;
};
class Ghost: public EntityModel {
public:
    Ghost(const tuple<float, float> &position, char symbol)
        : EntityModel(position, symbol) {
    }
    [[nodiscard]] char getcurrentDirection() const override{}

    void setCurrentDirection(char currentDirection) override{}

    [[nodiscard]] char getnextDirection() override{}

    void setnextDirection(char nextDirection) override{}
    void update(float deltaTime) override {}
};
class Wall: public EntityModel {
public:
    Wall(const tuple<float, float> &position, char symbol)
        : EntityModel(position, symbol) {
    }
    [[nodiscard]] char getcurrentDirection() const override{}

    void setCurrentDirection(char currentDirection) override{}

    [[nodiscard]] char getnextDirection() override{}

    void setnextDirection(char nextDirection) override{}

    void update(float deltaTime) override {}
};
class Floor: public EntityModel {
public:
    Floor(const tuple<float, float> &position, char symbol)
        : EntityModel(position, symbol) {
    }
    [[nodiscard]] char getcurrentDirection() const override{}

    void setCurrentDirection(char currentDirection) override{}

    [[nodiscard]] char getnextDirection() override{}

    void setnextDirection(char nextDirection) override{}
    void update(float deltaTime) override {}
};
class Collectable: public EntityModel {
public:
    Collectable(const tuple<float, float> &position, char symbol)
        : EntityModel(position, symbol) {
    }
    [[nodiscard]] char getcurrentDirection() const override{}

    void setCurrentDirection(char currentDirection) override{}

    [[nodiscard]] char getnextDirection() override{}

    void setnextDirection(char nextDirection) override{}

    void update(float deltaTime) override {}
};


#endif //ADVANCEDPROGRAMMING_PACMAN_ENTITYMODEL_H