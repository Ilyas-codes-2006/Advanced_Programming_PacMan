//
// Created by Youssef on 9/11/2025.
//

#ifndef ADVANCEDPROGRAMMING_PACMAN_WORLD_H
#define ADVANCEDPROGRAMMING_PACMAN_WORLD_H
#include <memory>
#include <vector>
#include <iostream>
using namespace std;
class Entity;
class World {
private:
    vector<shared_ptr<Entity>> entities;
public:
    void addEntity(shared_ptr<Entity>& entity);
    void removeEntity(shared_ptr<Entity>& entity);
    void clearEntities();
};


#endif //ADVANCEDPROGRAMMING_PACMAN_WORLD_H