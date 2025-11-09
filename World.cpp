//
// Created by Youssef on 9/11/2025.
//

#include "World.h"
void World::addEntity(shared_ptr<Entity>& entity) {
    entities.push_back(entity);
}
void World::removeEntity(shared_ptr<Entity>& entity) {
    for (auto it = entities.begin(); it != entities.end(); ++it) {
        if (it->get() == entity.get()) {
            entities.erase(it);
            break;
        }
    }
}
void World::clearEntities() {
    entities.clear();
}

