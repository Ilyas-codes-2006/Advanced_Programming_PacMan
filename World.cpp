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
                entity->set_entity_height(level->entity_height());
                entity->set_entity_width(level->entity_width());
                break;
            case 'P':
                entity = factory->PacManEntity({coordX,coordY},'P');
                entity->set_entity_height(level->entity_height());
                entity->set_entity_width(level->entity_width());
                pacman = entity;
                break;
            case '_':
                entity = factory->FloorEntity({coordX,coordY},'_');
                entity->set_entity_height(level->entity_height());
                entity->set_entity_width(level->entity_width());
                break;
            case 'F':
                entity = factory->FruitEntity({coordX,coordY},'F');
                entity->set_entity_height(level->entity_height());
                entity->set_entity_width(level->entity_width());
                break;
            case '-':
                entity = factory->CoinEntity({coordX,coordY},'-');
                entity->set_entity_height(level->entity_height());
                entity->set_entity_width(level->entity_width());
                break;
        }
        addEntity(entity);
    }
}
void World::checkCollision() {
    auto pac = pacman->getPosition();
    float xMin = get<0>(pac)-pacman->entity_width()/2;
    float xMax = get<0>(pac)+pacman->entity_width()/2;
    float yMin = get<1>(pac)+pacman->entity_height()/2;
    float yMax = get<1>(pac)-pacman->entity_height()/2;
    for (auto entity: getEntities()) {
        if (entity->getSymbol()== '#') {
            auto wall = entity->getPosition();
            float wMinx = get<0>(wall)-entity->entity_width()/2;
            float wMaxx = get<0>(wall)+entity->entity_width()/2;
            float wMiny = get<1>(wall)+entity->entity_height()/2;
            float wMaxy = get<1>(wall)-entity->entity_height()/2;
            if (xMax > wMinx && xMin < wMaxx && yMax < wMiny && yMin > wMaxy) {
                auto pos = pacman->getPrevPosition();
                pacman->setPosition(pos);
            }
        }
    }
}
void World::checkEaten() {
    auto pac = pacman->getPosition();
    float xMin = get<0>(pac)-pacman->entity_width()/6;
    float xMax = get<0>(pac)+pacman->entity_width()/6;
    float yMin = get<1>(pac)+pacman->entity_height()/6;
    float yMax = get<1>(pac)-pacman->entity_height()/6;
    vector<shared_ptr<EntityModel>> coins;
    for (auto entity: getEntities()) {
        if (entity->getSymbol()== '-') {
            auto coin = entity->getPosition();
            float wMinx = get<0>(coin)-entity->entity_width()/6;
            float wMaxx = get<0>(coin)+entity->entity_width()/6;
            float wMiny = get<1>(coin)+entity->entity_height()/6;
            float wMaxy = get<1>(coin)-entity->entity_height()/6;
            if (xMax > wMinx && xMin < wMaxx && yMax < wMiny && yMin > wMaxy) {
                cout << "eaten" << endl;
                entity->setInteracted(true);
                coins.push_back(entity);
            }
        }
    }
    for (auto coin: coins) {
        removeEntity(coin);
    }
}






