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
    float xMin = get<0>(pac)-pacman->entity_width()/2.5;
    float xMax = get<0>(pac)+pacman->entity_width()/2.5;
    float yMin = get<1>(pac)+pacman->entity_height()/2.5;
    float yMax = get<1>(pac)-pacman->entity_height()/2.5;
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
bool World::canMove(char direction, float move, tuple<float,float> position) {
    auto pac = pacman->getPosition();
    float x = get<0>(position);
    float y = get<1>(position);
    switch (direction) {
        case 'u':
            y+=move;
            break;
        case 'd':
            y-=move;
            break;
        case 'l':
            x-=move;
            break;
        case 'r':
            x+=move;
            break;
    }
    float xMin = x-pacman->entity_width()/2.5;
    float xMax = x+pacman->entity_width()/2.5;
    float yMin = y+pacman->entity_height()/2.5;
    float yMax = y-pacman->entity_height()/2.5;
    for (auto entity: getEntities()) {
        if (entity->getSymbol()== '#') {
            auto wall = entity->getPosition();
            float wMinx = get<0>(wall)-entity->entity_width()/2;
            float wMaxx = get<0>(wall)+entity->entity_width()/2;
            float wMiny = get<1>(wall)+entity->entity_height()/2;
            float wMaxy = get<1>(wall)-entity->entity_height()/2;
            if (xMax > wMinx && xMin < wMaxx && yMax < wMiny && yMin > wMaxy) {
                return false;
            }
        }
    }
    return true;
}
void World::updatePacman(float deltaTime) {
    float speed = 0.3f;
    float step = speed * deltaTime;

    auto pos = pacman->getPosition();
    char dir = pacman->getnextDirection();

    float x = get<0>(pos);
    float y = get<1>(pos);

    tuple<float,float> nextPos = pos;

    switch (dir) {
        case 'u': nextPos = {x, y + step}; break;
        case 'd': nextPos = {x, y - step}; break;
        case 'l': nextPos = {x - step, y}; break;
        case 'r': nextPos = {x + step, y}; break;
        default: return;
    }

    float xMin = get<0>(nextPos) - pacman->entity_width()/2.0009;
    float xMax = get<0>(nextPos) + pacman->entity_width()/2.0009;
    float yMin = get<1>(nextPos) + pacman->entity_height()/2.0005;
    float yMax = get<1>(nextPos) - pacman->entity_height()/2.0005;

    for (auto& entity : entities) {
        if (entity->getSymbol() == '#') {
            auto wall = entity->getPosition();
            float wMinx = get<0>(wall) - entity->entity_width()/2.0009;
            float wMaxx = get<0>(wall) + entity->entity_width()/2.0009;
            float wMiny = get<1>(wall) + entity->entity_height()/2.0005;
            float wMaxy = get<1>(wall) - entity->entity_height()/2.0005;

            if (xMax > wMinx && xMin < wMaxx &&
                yMax < wMiny && yMin > wMaxy) {
                return;
                }
        }
    }

    pacman->setPrevPosition(pos);
    pacman->setPosition(nextPos);
}







