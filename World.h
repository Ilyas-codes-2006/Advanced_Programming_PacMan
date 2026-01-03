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
    vector<char> directions = {'u','d','l','r'};
    vector<shared_ptr<EntityModel>> entities;
    float time = 0.0f;
    float levelDone = false;
    vector<shared_ptr<EntityModel>> ghosts;
    vector<shared_ptr<EntityModel>> Spawn;
    vector<shared_ptr<EntityModel>> ToBeEaten;
    int pacmanlives;
    int pacHItOnce = 0;
    bool won = false;
    shared_ptr<EntityModel> pacman;
    int countr = 0;
    int countp = 0;
    int countb = 0;
    int counto = 0;
    int currentLevel = 0;
public:
    explicit World(const shared_ptr<AbstractFactory> &factory)
        : factory(factory) {
    }
    shared_ptr<Level> getCurrentLevel();

    [[nodiscard]] int getCurLevel() const {
        return currentLevel;
    }

    void setCurrentLevel(int current_level) {
        currentLevel = current_level;
    }

    void set_time(float time) {
        this->time = time;
    }

    void set_level_done(float level_done) {
        levelDone = level_done;
    }

    void set_ghosts(const vector<shared_ptr<EntityModel>> &ghosts) {
        this->ghosts = ghosts;
    }

    void set_spawn(const vector<shared_ptr<EntityModel>> &spawn) {
        Spawn = spawn;
    }

    void set_to_be_eaten(const vector<shared_ptr<EntityModel>> &to_be_eaten) {
        ToBeEaten = to_be_eaten;
    }

    void set_pac_h_it_once(int pac_h_it_once) {
        pacHItOnce = pac_h_it_once;
    }

    void set_won(bool won) {
        this->won = won;
    }

    void set_pacman(const shared_ptr<EntityModel> &pacman) {
        this->pacman = pacman;
    }

    void set_countr(int countr) {
        this->countr = countr;
    }

    void set_countp(int countp) {
        this->countp = countp;
    }

    void set_countb(int countb) {
        this->countb = countb;
    }

    void set_counto(int counto) {
        this->counto = counto;
    }

    [[nodiscard]] vector<shared_ptr<EntityModel>> getGhosts() const {
        return ghosts;
    }

    [[nodiscard]] vector<shared_ptr<EntityModel>> getSpawn() const {
        return Spawn;
    }

    [[nodiscard]] vector<shared_ptr<EntityModel>> getToBeEaten() const {
        return ToBeEaten;
    }

    void addLevel(shared_ptr<Level>& level);
    void makeLevel(shared_ptr<Level> level);

    [[nodiscard]] shared_ptr<EntityModel> getPacman() const {
        return pacman;
    }

    [[nodiscard]] bool getWon() const {
        return won;
    }

    [[nodiscard]] vector<shared_ptr<EntityModel>> getEntities() const {
        return entities;
    }

    void setEntities(const vector<shared_ptr<EntityModel>> &entities) {
        this->entities = entities;
    }

    [[nodiscard]] float getLevelDone() const {
        return levelDone;
    }

    void levelFinished();
    void reset();
    void addEntity(shared_ptr<EntityModel>& entity);
    void removeEntity(shared_ptr<EntityModel>& entity);
    void removeEatenEntity(shared_ptr<EntityModel>& entity);
    void clearEntities();
    void checkCollision();
    void checkEaten();
    void checkEatenFruit();
    void CheckGhost();
    tuple<float,float> calcDirection(float step, char dir,tuple<float,float> pos);
    void GhostMovement(float deltatime);
    bool wallinDirectionGhost(char dir, tuple<float,float> pos,shared_ptr<EntityModel> ghost);
    bool checkIntersection(char dir, tuple<float,float> pos,shared_ptr<EntityModel> ghost);
    float manhattanDistance(tuple<float,float> pos,tuple<float,float> pos2);
    tuple<float,float> pacmanNextpos(float step);
    bool wallinDirection(char dir);
    float findCorridorCenter(char dir, tuple<float,float> position);
    bool canMovethroughcorridor(float hitbox, tuple<float,float> position);
    void updatePacman(float deltaTime);
};


#endif //ADVANCEDPROGRAMMING_PACMAN_WORLD_H