//
// Created by Youssef on 9/11/2025.
//

#include "World.h"

#include "AbstractFactory.h"
#include "Level.h"

void World::addEntity(shared_ptr<EntityModel>& entity) {
    entities.push_back(entity);
}
void World::removeEntity(shared_ptr<EntityModel>& entity) {
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
shared_ptr<Level> World::getCurrentLevel() {
    return levels[currentLevel];
}
void World::addLevel(shared_ptr<Level> &level) {
    levels.push_back(level);
}
void World::levelFinished() {
    currentLevel++;
}
void World::makeLevel(shared_ptr<Level> level) {
    clearEntities();
    auto map = level->getLevelMapping();
    for (auto coord: map) {
        shared_ptr<EntityModel> entity;
        float coordX = get<0>(coord);
        float coordY = get<1>(coord);
        char charEntity = get<2>(coord);
        switch (charEntity) {
            case '#':
                entity = factory->WallEntity({coordX,coordY},'#');
                break;
            case 'P':
                entity = factory->PacManEntity({coordX,coordY},'P');
                break;
            case '_':
                entity = factory->FloorEntity({coordX,coordY},'_');
                break;
            case 'F':
                entity = factory->FruitEntity({coordX,coordY},'F');
                break;
            case '-':
                entity = factory->CoinEntity({coordX,coordY},'-');
                break;
        }
        addEntity(entity);
    }
}




