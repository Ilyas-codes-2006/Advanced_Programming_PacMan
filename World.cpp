//
// Created by Youssef on 9/11/2025.
//

#include "World.h"

#include <cmath>

#include "AbstractFactory.h"
#include "Level.h"
#include "Score.h"

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
            case 'r':
                entity = factory->GhostEntity({coordX,coordY},'r');
                entity->set_entity_height(level->entity_height());
                entity->set_entity_width(level->entity_width());
                ghosts.push_back(entity);
                break;
            case 'p':
                entity = factory->GhostEntity({coordX,coordY},'p');
                entity->set_entity_height(level->entity_height());
                entity->set_entity_width(level->entity_width());
                ghosts.push_back(entity);
                break;
            case 'b':
                entity = factory->GhostEntity({coordX,coordY},'b');
                entity->set_entity_height(level->entity_height());
                entity->set_entity_width(level->entity_width());
                ghosts.push_back(entity);
                break;
            case 'o':
                entity = factory->GhostEntity({coordX,coordY},'o');
                entity->set_entity_height(level->entity_height());
                entity->set_entity_width(level->entity_width());
                ghosts.push_back(entity);
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
            float wMinx = get<0>(wall)-entity->entity_width()/2.5;
            float wMaxx = get<0>(wall)+entity->entity_width()/2.5;
            float wMiny = get<1>(wall)+entity->entity_height()/2.5;
            float wMaxy = get<1>(wall)-entity->entity_height()/2.5;
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
    for (auto entity: entities) {
        if (entity->getSymbol()== '-') {
            auto coin = entity->getPosition();
            float wMinx = get<0>(coin)-entity->entity_width()/6;
            float wMaxx = get<0>(coin)+entity->entity_width()/6;
            float wMiny = get<1>(coin)+entity->entity_height()/6;
            float wMaxy = get<1>(coin)-entity->entity_height()/6;
            if (xMax > wMinx && xMin < wMaxx && yMax < wMiny && yMin > wMaxy) {
                cout << "eaten" << endl;
                entity->setInteracted(true);
                Event event(WhichEvent::CoinPoint,entity.get());
                entity->notify(event);
                coins.push_back(entity);
                /*score.addPoints();*/
            }
        }
    }
    for (auto coin: coins) {
        removeEntity(coin);
    }
}
/*float World::findCorridorCenter(char dir, tuple<float,float> position) {
    float entityW = pacman->entity_width();
    float entityH = pacman->entity_height();
    if (dir == 'u' || dir == 'd') {

    }
    else if (dir == 'l' || dir == 'r') {

    }
}*/


bool World::wallinDirection(char dir) {
    auto pos = pacman->getPosition();
    float x = get<0>(pos);
    float y = get<1>(pos);
    float entityW = pacman->entity_width();
    float entityH = pacman->entity_height();
    switch (dir) {
        case 'u':
            y+=entityH/2;
            break;
        case 'd':
            y-=entityH/2;
            break;
        case 'l':
            x-=entityW/2;
            break;
        case 'r':
            x+=entityW/2;
            break;
    }
    for (auto& entity : entities) {
        if (entity->getSymbol() == '#') {
            auto wall = entity->getPosition();
            float wMinx = get<0>(wall)-entity->entity_width()/1.022;
            float wMaxx = get<0>(wall)+entity->entity_width()/1.022;
            float wMiny = get<1>(wall)-entity->entity_height()/1.022;
            float wMaxy = get<1>(wall)+entity->entity_height()/1.022;
            if (x >= wMinx && x <= wMaxx && y >= wMiny && y <= wMaxy) {
                return true;
            }
        }
    }
    return false;
}

bool World::canMovethroughcorridor(float hitbox, tuple<float,float> position) {
    float x = get<0>(position);
    float y = get<1>(position);
    float xMin = x-pacman->entity_width()/hitbox;
    float xMax = x+pacman->entity_width()/hitbox;
    float yMin = y+pacman->entity_height()/hitbox;
    float yMax = y-pacman->entity_height()/hitbox;
    for (auto entity: entities) {
        if (entity->getSymbol()== '#') {
            auto wall = entity->getPosition();
            float wMinx = get<0>(wall)-entity->entity_width()/2;
            float wMaxx = get<0>(wall)+entity->entity_width()/2;
            float wMiny = get<1>(wall)+entity->entity_height()/2;
            float wMaxy = get<1>(wall)-entity->entity_height()/2;
            if (xMax >= wMinx && xMin <= wMaxx && yMax <= wMiny && yMin >= wMaxy) {
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
    if (wallinDirection(dir)) {
        if (pacman->getcurrentDirection() == 'N') {
            return;
        }
        else {
            char cur = pacman->getcurrentDirection();
            float x = get<0>(pos);
            float y = get<1>(pos);
            tuple<float,float> nextPos = pos;
            switch (cur) {
                case 'u': nextPos = {x,y+step}; break;
                case 'd': nextPos = {x,y-step}; break;
                case 'l': nextPos = {x-step,y}; break;
                case 'r': nextPos = {x+step,y}; break;
                default: return;
            }
            if (!canMovethroughcorridor(2.09,nextPos)) {
                return;
            }

            pacman->setPrevPosition(pos);
            pacman->setPosition(nextPos);
            Event event(WhichEvent::Moved,pacman.get());
            pacman->notify(event);
        }
    }
    else {
        pacman->setCurrentDirection(dir);
        char cur = pacman->getcurrentDirection();
        float x = get<0>(pos);
        float y = get<1>(pos);
        tuple<float,float> nextPos = pos;
        switch (cur) {
            case 'u': nextPos = {x,y+step}; break;
            case 'd': nextPos = {x,y-step}; break;
            case 'l': nextPos = {x-step,y}; break;
            case 'r': nextPos = {x+step,y}; break;
            default: return;
        }
        if (!canMovethroughcorridor(2.09,nextPos)) {
            return;
        }
        pacman->setPrevPosition(pos);
        pacman->setPosition(nextPos);
        Event event(WhichEvent::Moved,pacman.get());
        pacman->notify(event);
    }
}
tuple<float, float> World::calcDirection(float step, char dir, tuple<float, float> pos) {
    float x = get<0>(pos);
    float y = get<1>(pos);
    tuple<float,float> nextPos = pos;
    switch (dir) {
        case 'u': nextPos = {x,y+step}; break;
        case 'd': nextPos = {x,y-step}; break;
        case 'l': nextPos = {x-step,y}; break;
        case 'r': nextPos = {x+step,y}; break;
    }
    return nextPos;
}

void World::GhostMovement(float deltatime) {
    time += deltatime;
    for (auto ghost: ghosts) {
        if (ghost->getSymbol()=='r') {
            float speed = 0.3f;
            float step = speed * deltatime;
            auto pos = ghost->getPosition();
            char dir = ghost->getcurrentDirection();
            if (wallinDirection(dir)) {
                vector<char> possibleWays;
                for (auto way: directions) {
                    auto nextPos = calcDirection(step,way,pos);
                    if (canMovethroughcorridor(2.09,nextPos)) {
                        possibleWays.push_back(way);
                    }
                }
                char cur = ghost->getcurrentDirection();
                /*if (possibleWays.size() ==2) {
                    cur = possibleWays[0];
                }
                else if (possibleWays.size() ==3) {
                    cur = possibleWays[1];
                }*/
                /*ghost->setCurrentDirection()
                char cur = possibleWays[0];
                ghost->setCurrentDirection()*/
                auto nextpos = calcDirection(step,cur,pos);
                if (!canMovethroughcorridor(2.09,nextpos)) {
                    return;
                }
                ghost->setPrevPosition(pos);
                ghost->setPosition(nextpos);
                ghost->setCurrentDirection(cur);
                /*Event event(WhichEvent::Moved,ghost.get());
                ghost->notify(event);*/
            }
            else {
                float x = get<0>(pos);
                float y = get<1>(pos);
                tuple<float,float> nextPos = pos;
                switch (dir) {
                    case 'u': nextPos = {x,y+step}; break;
                    case 'd': nextPos = {x,y-step}; break;
                    case 'l': nextPos = {x-step,y}; break;
                    case 'r': nextPos = {x+step,y}; break;
                    default: return;
                }
                if (!canMovethroughcorridor(2.09,nextPos)) {
                    return;
                }
                ghost->setPrevPosition(pos);
                ghost->setPosition(nextPos);
                /*Event event(WhichEvent::Moved,pacman.get());
                pacman->notify(event);*/
            }
        }
        /*if (ghost->getSymbol()=='p') {
            float speed = 0.3f;
            float step = speed * deltatime;
            auto pos = ghost->getPosition();
            char dir = ghost->getnextDirection();
            if (wallinDirection(dir)) {
                if (ghost->getcurrentDirection() == 'N') {
                    return;
                }
                else {
                    char cur = ghost->getcurrentDirection();
                    float x = get<0>(pos);
                    float y = get<1>(pos);
                    tuple<float,float> nextPos = pos;
                    switch (cur) {
                        case 'u': nextPos = {x,y+step}; break;
                        case 'd': nextPos = {x,y-step}; break;
                        case 'l': nextPos = {x-step,y}; break;
                        case 'r': nextPos = {x+step,y}; break;
                        default: return;
                    }
                    if (!canMovethroughcorridor(2.09,nextPos)) {
                        return;
                    }

                    ghost->setPrevPosition(pos);
                    ghost->setPosition(nextPos);
                    /*Event event(WhichEvent::Moved,ghost.get());
                    ghost->notify(event);#1#
                }
            }
            else {
                ghost->setCurrentDirection(dir);
                char cur = ghost->getcurrentDirection();
                float x = get<0>(pos);
                float y = get<1>(pos);
                tuple<float,float> nextPos = pos;
                switch (cur) {
                    case 'u': nextPos = {x,y+step}; break;
                    case 'd': nextPos = {x,y-step}; break;
                    case 'l': nextPos = {x-step,y}; break;
                    case 'r': nextPos = {x+step,y}; break;
                    default: return;
                }
                if (!canMovethroughcorridor(2.09,nextPos)) {
                    return;
                }
                ghost->setPrevPosition(pos);
                ghost->setPosition(nextPos);
                /*Event event(WhichEvent::Moved,pacman.get());
                pacman->notify(event);#1#
            }
        }
        if (ghost->getSymbol()=='b') {
            if (time >= 5.0f) {
                float speed = 0.3f;
            float step = speed * deltatime;
            auto pos = ghost->getPosition();
            char dir = ghost->getnextDirection();
            if (wallinDirection(dir)) {
                if (ghost->getcurrentDirection() == 'N') {
                    return;
                }
                else {
                    char cur = ghost->getcurrentDirection();
                    float x = get<0>(pos);
                    float y = get<1>(pos);
                    tuple<float,float> nextPos = pos;
                    switch (cur) {
                        case 'u': nextPos = {x,y+step}; break;
                        case 'd': nextPos = {x,y-step}; break;
                        case 'l': nextPos = {x-step,y}; break;
                        case 'r': nextPos = {x+step,y}; break;
                        default: return;
                    }
                    if (!canMovethroughcorridor(2.09,nextPos)) {
                        return;
                    }

                    ghost->setPrevPosition(pos);
                    ghost->setPosition(nextPos);
                    /*Event event(WhichEvent::Moved,ghost.get());
                    ghost->notify(event);#1#
                }
            }
            else {
                ghost->setCurrentDirection(dir);
                char cur = ghost->getcurrentDirection();
                float x = get<0>(pos);
                float y = get<1>(pos);
                tuple<float,float> nextPos = pos;
                switch (cur) {
                    case 'u': nextPos = {x,y+step}; break;
                    case 'd': nextPos = {x,y-step}; break;
                    case 'l': nextPos = {x-step,y}; break;
                    case 'r': nextPos = {x+step,y}; break;
                    default: return;
                }
                if (!canMovethroughcorridor(2.09,nextPos)) {
                    return;
                }
                ghost->setPrevPosition(pos);
                ghost->setPosition(nextPos);
                /*Event event(WhichEvent::Moved,pacman.get());
                pacman->notify(event);#1#
            }

            }
        }
        if (ghost->getSymbol()=='o') {
            if (time >= 10.0f) {
              float speed = 0.3f;
            float step = speed * deltatime;
            auto pos = ghost->getPosition();
            char dir = ghost->getnextDirection();
            if (wallinDirection(dir)) {
                if (ghost->getcurrentDirection() == 'N') {
                    return;
                }
                else {
                    char cur = ghost->getcurrentDirection();
                    float x = get<0>(pos);
                    float y = get<1>(pos);
                    tuple<float,float> nextPos = pos;
                    switch (cur) {
                        case 'u': nextPos = {x,y+step}; break;
                        case 'd': nextPos = {x,y-step}; break;
                        case 'l': nextPos = {x-step,y}; break;
                        case 'r': nextPos = {x+step,y}; break;
                        default: return;
                    }
                    if (!canMovethroughcorridor(2.09,nextPos)) {
                        return;
                    }

                    ghost->setPrevPosition(pos);
                    ghost->setPosition(nextPos);
                    /*Event event(WhichEvent::Moved,ghost.get());
                    ghost->notify(event);#1#
                }
            }
            else {
                ghost->setCurrentDirection(dir);
                char cur = ghost->getcurrentDirection();
                float x = get<0>(pos);
                float y = get<1>(pos);
                tuple<float,float> nextPos = pos;
                switch (cur) {
                    case 'u': nextPos = {x,y+step}; break;
                    case 'd': nextPos = {x,y-step}; break;
                    case 'l': nextPos = {x-step,y}; break;
                    case 'r': nextPos = {x+step,y}; break;
                    default: return;
                }
                if (!canMovethroughcorridor(2.09,nextPos)) {
                    return;
                }
                ghost->setPrevPosition(pos);
                ghost->setPosition(nextPos);
                /*Event event(WhichEvent::Moved,pacman.get());
                pacman->notify(event);#1#
            }
            }
        }*/
    }
}