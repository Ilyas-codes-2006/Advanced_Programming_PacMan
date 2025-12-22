//
// Created by Youssef on 9/11/2025.
//

#ifndef ADVANCEDPROGRAMMING_PACMAN_WORLD_H
#define ADVANCEDPROGRAMMING_PACMAN_WORLD_H
#include <memory>
#include <vector>
#include <iostream>
#include "AbstractFactory.h"
using namespace std;
class Level;
class Score;
class EntityModel;
class World {
private:
    vector<shared_ptr<Level>> levels;
    shared_ptr<AbstractFactory> factory;
    vector<shared_ptr<EntityModel>> entities;
    float time = 0.0f;
    vector<shared_ptr<EntityModel>> ghosts;
    shared_ptr<EntityModel> pacman;
    int currentLevel = 0;
public:
    explicit World(const shared_ptr<AbstractFactory> &factory)
        : factory(factory) {
    }
    shared_ptr<Level> getCurrentLevel();
    void addLevel(shared_ptr<Level>& level);
    void makeLevel(shared_ptr<Level> level);

    [[nodiscard]] shared_ptr<EntityModel> getPacman() const {
        return pacman;
    }

    [[nodiscard]] vector<shared_ptr<EntityModel>> getEntities() const {
        return entities;
    }
    void levelFinished();
    void addEntity(shared_ptr<EntityModel>& entity);
    void removeEntity(shared_ptr<EntityModel>& entity);
    void clearEntities();
    void checkCollision();
    void checkEaten();
    void GhostMovement(float deltatime);
    bool wallinDirection(char dir);
    float findCorridorCenter(char dir, tuple<float,float> position);
    bool canMovethroughcorridor(float hitbox, tuple<float,float> position);
    void updatePacman(float deltaTime);
};


#endif //ADVANCEDPROGRAMMING_PACMAN_WORLD_H