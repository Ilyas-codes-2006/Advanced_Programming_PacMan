//
// Created by Youssef on 9/11/2025.
//

#ifndef ADVANCEDPROGRAMMING_PACMAN_WORLD_H
#define ADVANCEDPROGRAMMING_PACMAN_WORLD_H
#include <memory>
#include <vector>
#include <iostream>
using namespace std;
class AbstractFactory;
class EntityModel;
class World {
private:
    shared_ptr<AbstractFactory> factory;
    vector<shared_ptr<EntityModel>> entities;
public:
    explicit World(const shared_ptr<AbstractFactory> &factory)
        : factory(factory) {
    }
    void addEntity(shared_ptr<EntityModel>& entity);
    void removeEntity(shared_ptr<EntityModel>& entity);
    void clearEntities();
};


#endif //ADVANCEDPROGRAMMING_PACMAN_WORLD_H