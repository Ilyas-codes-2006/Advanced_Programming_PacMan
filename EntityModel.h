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
    float entityWidth;
    float entityHeight;
    bool interacted = false;
    char symbol;
public:
    EntityModel(const tuple<float, float> &position, char symbol)
        : position(position),
          symbol(symbol) {
    }

    [[nodiscard]] bool getInteracted() const {
        return interacted;
    }

    [[nodiscard]] float entity_width() const {
        return entityWidth;
    }

    void set_entity_width(float entity_width) {
        entityWidth = entity_width;
    }

    [[nodiscard]] float entity_height() const {
        return entityHeight;
    }

    void set_entity_height(float entity_height) {
        entityHeight = entity_height;
    }

    void setInteracted(bool interacted) {
        this->interacted = interacted;
    }

    [[nodiscard]] virtual char getcurrentDirection() const = 0;

    virtual void setCurrentDirection(char currentDirection) = 0;

    [[nodiscard]] virtual char getnextDirection() = 0;

    virtual void setnextDirection(char nextDirection) = 0;

    [[nodiscard]] virtual tuple<float,float> getcurrentPosition() = 0;

    virtual void setCurrentPosition(tuple<float,float> cur) = 0;

    [[nodiscard]] virtual tuple<float,float> getPrevPosition() = 0;

    virtual void setPrevPosition(tuple<float,float> prev) = 0;

    [[nodiscard]] virtual bool getFearmode() = 0;

    virtual void setFearmode(bool fear) = 0;

    virtual void update(float deltaTime) = 0;

    tuple<float, float> getPosition() const {
        return position;
    }

    void setPosition(const tuple<float, float> &position) {
        this->position = position;
        /*notify();*/
    }

    [[nodiscard]] char getSymbol() const {
        return symbol;
    }
};

class PacMan: public EntityModel {
    char currentDirection = 'N';
    char nextDirection = 'N';
    tuple<float,float> current_position;
    tuple<float,float> previous_position;
public:

    PacMan(const tuple<float, float> &position, char symbol)
        : EntityModel(position, symbol) {
    }
    [[nodiscard]] char getcurrentDirection() const override;

    void setCurrentDirection(char currentDirection) override;

    [[nodiscard]] char getnextDirection() override;

    void setnextDirection(char nextDirection) override;

    [[nodiscard]] tuple<float,float> getcurrentPosition() override;

    void setCurrentPosition(tuple<float,float> cur) override;

    [[nodiscard]]  tuple<float,float> getPrevPosition() override;

    void setPrevPosition(tuple<float,float> prev) override;

    [[nodiscard]] bool getFearmode() override {}

    void setFearmode(bool fear) override {}

    void update(float deltaTime) override;
};
class Ghost: public EntityModel {
    char currentDirection = 'N';
    tuple<float,float> current_position;
    tuple<float,float> previous_position;
    bool fearmode = false;
public:
    Ghost(const tuple<float, float> &position, char symbol)
        : EntityModel(position, symbol) {
        if (getSymbol()=='r') {
            currentDirection = 'l';
        }
        else if (getSymbol()=='p') {
            currentDirection = 'r';
        }
        else if (getSymbol()=='b') {
            currentDirection = 'r';
        }
        else if (getSymbol()=='o') {
            currentDirection = 'l';
        }
    }
    [[nodiscard]] char getcurrentDirection() const override;

    void setCurrentDirection(char currentDirection) override;

    [[nodiscard]] char getnextDirection() override {}

    void setnextDirection(char nextDirection) override {}

    [[nodiscard]] tuple<float,float> getcurrentPosition() override;

    void setCurrentPosition(tuple<float,float> cur) override;

    [[nodiscard]]  tuple<float,float> getPrevPosition() override;

    void setPrevPosition(tuple<float,float> prev) override;

    [[nodiscard]] bool getFearmode() override;

    void setFearmode(bool fear) override;

    void update(float deltaTime) override;
};
class Wall: public EntityModel {
public:
    Wall(const tuple<float, float> &position, char symbol)
        : EntityModel(position, symbol) {
    }

    [[nodiscard]] char getcurrentDirection() const override{}

    void setCurrentDirection(char currentDirection) override{}

    [[nodiscard]] tuple<float,float> getcurrentPosition() override{}

    void setCurrentPosition(tuple<float,float> cur) override {}

    [[nodiscard]]  tuple<float,float> getPrevPosition() override {}

    void setPrevPosition(tuple<float,float> prev) override {}

    [[nodiscard]] char getnextDirection() override{}

    void setnextDirection(char nextDirection) override{}

    [[nodiscard]] bool getFearmode() override {}

    void setFearmode(bool fear) override {}

    void update(float deltaTime) override {}
};
class Floor: public EntityModel {
public:
    Floor(const tuple<float, float> &position, char symbol)
        : EntityModel(position, symbol) {
    }

    [[nodiscard]] char getcurrentDirection() const override{}

    void setCurrentDirection(char currentDirection) override{}

    [[nodiscard]] tuple<float,float> getcurrentPosition() override{}

    void setCurrentPosition(tuple<float,float> cur) override {}

    [[nodiscard]]  tuple<float,float> getPrevPosition() override {}

    void setPrevPosition(tuple<float,float> prev) override {}

    [[nodiscard]] char getnextDirection() override{}

    void setnextDirection(char nextDirection) override{}

    [[nodiscard]] bool getFearmode() override {}

    void setFearmode(bool fear) override {}

    void update(float deltaTime) override {}
};
class Fruit: public EntityModel {
public:
    Fruit(const tuple<float, float> &position, char symbol)
        : EntityModel(position, symbol) {
    }

    [[nodiscard]] char getcurrentDirection() const override{}

    void setCurrentDirection(char currentDirection) override{}

    [[nodiscard]] char getnextDirection() override{}

    [[nodiscard]] tuple<float,float> getcurrentPosition() override{}

    void setCurrentPosition(tuple<float,float> cur) override {}

    [[nodiscard]]  tuple<float,float> getPrevPosition() override {}

    void setPrevPosition(tuple<float,float> prev) override {}

    void setnextDirection(char nextDirection) override{}

    [[nodiscard]] bool getFearmode() override {}

    void setFearmode(bool fear) override {}

    void update(float deltaTime) override {}
};
class Coin: public EntityModel {
public:
    Coin(const tuple<float, float> &position, char symbol)
        : EntityModel(position, symbol) {
    }


    [[nodiscard]] char getcurrentDirection() const override{}

    void setCurrentDirection(char currentDirection) override{}

    [[nodiscard]] tuple<float,float> getcurrentPosition() override{}

    void setCurrentPosition(tuple<float,float> cur) override {}

    [[nodiscard]]  tuple<float,float> getPrevPosition() override {}

    void setPrevPosition(tuple<float,float> prev) override {}

    [[nodiscard]] char getnextDirection() override{}

    void setnextDirection(char nextDirection) override{}

    [[nodiscard]] bool getFearmode() override {}

    void setFearmode(bool fear) override {}

    void update(float deltaTime) override {}
};


#endif //ADVANCEDPROGRAMMING_PACMAN_ENTITYMODEL_H