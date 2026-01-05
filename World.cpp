//
// Created by Youssef on 9/11/2025.
//

#include "World.h"
#include <cmath>
#include "AbstractFactory.h"
#include "Level.h"
#include "Random.h"
#include "Score.h"

using namespace std;

void World::addEntity(shared_ptr<EntityModel>& entity) {
    entities.push_back(entity);
}
void World::removeEntity(shared_ptr<EntityModel>& entity) {
    for (auto it = entities.begin(); it != entities.end(); it++) {
        if (it->get() == entity.get()) {
            entities.erase(it);
            break;
        }
    }
}
void World::clearEntities() {
    entities.clear();
}
/**
 * @Functionality Gives the currentLevel
 *
 * @Explanation /
 */
shared_ptr<Level> World::getCurrentLevel() {
    return levels[currentLevel];
}
/**
 * @Functionality Adds a new level
 *
 * @Explanation /
 */
void World::addLevel(shared_ptr<Level> &level) {
    levels.push_back(level);
}
void World::levelFinished() {
    currentLevel++;
}
/**
 * @Functionality Makes a new Level
 *
 * @Explanation Level gives me the coordinate of every character.
 * Based on the character it makes the right entity.
 */
void World::makeLevel(shared_ptr<Level> level) {
    auto map = level->getLevelMapping();
    for (auto coord: map) {
        shared_ptr<EntityModel> entity;
        float coordX = get<0>(coord);
        float coordY = get<1>(coord);
        char charEntity = get<2>(coord);
        switch (charEntity) {
            case '#':
                entity = factory->WallEntity({coordX,coordY},'#',{coordX,coordY});
                entity->set_entity_height(level->entity_height());
                entity->set_entity_width(level->entity_width());
                addEntity(entity);
                break;
            case 'P':
                if (currentLevel == 0) {
                    entity = factory->PacManEntity({coordX,coordY},'P',{coordX,coordY});
                    entity->set_entity_height(level->entity_height());
                    entity->set_entity_width(level->entity_width());
                    pacman = entity;
                    addEntity(entity);
                }
                else {
                    entity = factory->PacManEntity({coordX,coordY},'P',{coordX,coordY});
                    entity->set_entity_height(level->entity_height());
                    entity->set_entity_width(level->entity_width());
                    entity->setLives(pacmanlives);
                    pacman = entity;
                    addEntity(pacman);
                }
                break;
            case '_':
                entity = factory->FloorEntity({coordX,coordY},'_',{coordX,coordY});
                entity->set_entity_height(level->entity_height());
                entity->set_entity_width(level->entity_width());
                addEntity(entity);
                break;
            case 'F':
                entity = factory->FruitEntity({coordX,coordY},'F',{coordX,coordY});
                entity->set_entity_height(level->entity_height());
                entity->set_entity_width(level->entity_width());
                ToBeEaten.push_back(entity);
                addEntity(entity);
                break;
            case '-':
                entity = factory->CoinEntity({coordX,coordY},'-',{coordX,coordY});
                entity->set_entity_height(level->entity_height());
                entity->set_entity_width(level->entity_width());
                ToBeEaten.push_back(entity);
                addEntity(entity);
                break;
            case 'r':
                entity = factory->GhostEntity({coordX,coordY},'r',{coordX,coordY});
                entity->set_entity_height(level->entity_height());
                entity->set_entity_width(level->entity_width());
                ghosts.push_back(entity);
                addEntity(entity);
                break;
            case 'p':
                entity = factory->GhostEntity({coordX,coordY},'p',{coordX,coordY});
                entity->set_entity_height(level->entity_height());
                entity->set_entity_width(level->entity_width());
                ghosts.push_back(entity);
                addEntity(entity);
                break;
            case 'b':
                entity = factory->GhostEntity({coordX,coordY},'b',{coordX,coordY});
                entity->set_entity_height(level->entity_height());
                entity->set_entity_width(level->entity_width());
                ghosts.push_back(entity);
                addEntity(entity);
                break;
            case 'o':
                entity = factory->GhostEntity({coordX,coordY},'o',{coordX,coordY});
                entity->set_entity_height(level->entity_height());
                entity->set_entity_width(level->entity_width());
                ghosts.push_back(entity);
                addEntity(entity);
                break;
            case 'S':
                entity = factory->WallEntity({coordX,coordY},'S',{coordX,coordY});
                entity->set_entity_height(level->entity_height());
                entity->set_entity_width(level->entity_width());
                Spawn.push_back(entity);
                addEntity(entity);
                break;
        }
    }
}
/**
 * @Functionality We will check if PacMan collides with a wall
 *
 * @Explanation I make use of 2 hitboxes, one is for pacman and one is for the wall
 * If pacman just touches the other hitbox he will stop by giving himself his previous
 * position. We won't only use this function to make the full collision though.
 */
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
/**
 * @Functionality This function erases de Entity from all the entities that
 * can be eaten.
 *
 * @Explanation /
 */
void World::removeEatenEntity(shared_ptr<EntityModel> &entity) {
    for (auto it = ToBeEaten.begin(); it != ToBeEaten.end(); it++) {
        if (it->get() == entity.get()) {
            ToBeEaten.erase(it);
            break;
        }
    }
}
/**
 * @Functionality Pacman eats coin
 *
 * @Explanation We use the same system as for walls only now the hitboxes are much smaller
 * so it only triggers when we are almost in the middle. We also make use of an event here.
 * To tell our view that the coin needs to disappear. The coin itself gets deleted from
 * eatenEntities and also all the entities.
 */
void World::checkEaten() {
    bool eaten = false;
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
                eaten = true;
                entity->setInteracted(true);
                Event event(WhichEvent::CoinPoint,entity.get());
                entity->notify(event);
                coins.push_back(entity);
                /*score.addPoints();*/
            }
        }
    }
    if (eaten) {
        for (auto coin: coins) {
            removeEatenEntity(coin);
        }
        for (auto coin: coins) {
            removeEntity(coin);
        }
    }
    else {
        Event event(WhichEvent::NotEaten,pacman.get());
        pacman->notify(event);
    }
    if (ToBeEaten.empty()) {
        levelDone = true;
        won = true;
    }
}
/**
 * @Functionality Pacman eats coin
 *
 * @Explanation We use the same system as for walls only now the hitboxes are much smaller
 * so it only triggers when we are almost in the middle. We also make use of an event here.
 * To tell our view that the coin needs to disappear. The coin itself gets deleted from
 * eatenEntities and also all the entities.
 */
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
/**
 * @Functionality Pacman eats coin
 *
 * @Explanation We use the same system as for walls only now the hitboxes are much smaller
 * so it only triggers when we are almost in the middle. We also make use of an event here.
 * To tell our view that the coin needs to disappear. The coin itself gets deleted from
 * eatenEntities and also all the entities.
 */
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
/**
 * @Functionality Pacman eats coin
 *
 * @Explanation We use the same system as for walls only now the hitboxes are much smaller
 * so it only triggers when we are almost in the middle. We also make use of an event here.
 * To tell our view that the coin needs to disappear. The coin itself gets deleted from
 * eatenEntities and also all the entities.
 */
void World::updatePacman(float deltaTime) {
    float speed = 0.65;
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
/**
 * @Functionality Pacman eats coin
 *
 * @Explanation We use the same system as for walls only now the hitboxes are much smaller
 * so it only triggers when we are almost in the middle. We also make use of an event here.
 * To tell our view that the coin needs to disappear. The coin itself gets deleted from
 * eatenEntities and also all the entities.
 */
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
/**
 * @Functionality Pacman eats coin
 *
 * @Explanation We use the same system as for walls only now the hitboxes are much smaller
 * so it only triggers when we are almost in the middle. We also make use of an event here.
 * To tell our view that the coin needs to disappear. The coin itself gets deleted from
 * eatenEntities and also all the entities.
 */
bool World::wallinDirectionGhost(char dir, tuple<float, float> pos, shared_ptr<EntityModel> ghost) {
    float x = get<0>(pos);
    float y = get<1>(pos);
    float entityW = ghost->entity_width();
    float entityH = ghost->entity_height();
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
            float wMinx = get<0>(wall)-entity->entity_width()/1.9978;
            float wMaxx = get<0>(wall)+entity->entity_width()/1.9978;
            float wMiny = get<1>(wall)-entity->entity_height()/1.9978;
            float wMaxy = get<1>(wall)+entity->entity_height()/1.9978;
            if (x >= wMinx && x <= wMaxx && y >= wMiny && y <= wMaxy) {
                return true;
            }
        }
    }
    return false;
}
/**
 * @Functionality Pacman eats coin
 *
 * @Explanation We use the same system as for walls only now the hitboxes are much smaller
 * so it only triggers when we are almost in the middle. We also make use of an event here.
 * To tell our view that the coin needs to disappear. The coin itself gets deleted from
 * eatenEntities and also all the entities.
 */
bool World::checkIntersection(char dir, tuple<float, float> pos, shared_ptr<EntityModel> ghost) {
    float x = get<0>(pos);
    float y = get<1>(pos);
    float entityW = ghost->entity_width();
    float entityH = ghost->entity_height();
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
            float wMinx = get<0>(wall)-entity->entity_width()/1.001;
            float wMaxx = get<0>(wall)+entity->entity_width()/1.001;
            float wMiny = get<1>(wall)-entity->entity_height()/1.001;
            float wMaxy = get<1>(wall)+entity->entity_height()/1.001;
            if (x >= wMinx && x <= wMaxx && y >= wMiny && y <= wMaxy) {
                return true;
            }
        }
    }
    return false;
}
/**
 * @Functionality Pacman eats coin
 *
 * @Explanation We use the same system as for walls only now the hitboxes are much smaller
 * so it only triggers when we are almost in the middle. We also make use of an event here.
 * To tell our view that the coin needs to disappear. The coin itself gets deleted from
 * eatenEntities and also all the entities.
 */
float World::manhattanDistance(tuple<float, float> pos, tuple<float, float> pos2) {
    float x2 = get<0>(pos2);
    float y2 = get<1>(pos2);
    float x1 = get<0>(pos);
    float y1 = get<1>(pos);

    float manhattendistance = abs(x2-x1)+abs(y2-y1);
    return manhattendistance;
}
/**
 * @Functionality Pacman eats coin
 *
 * @Explanation We use the same system as for walls only now the hitboxes are much smaller
 * so it only triggers when we are almost in the middle. We also make use of an event here.
 * To tell our view that the coin needs to disappear. The coin itself gets deleted from
 * eatenEntities and also all the entities.
 */
tuple<float, float> World::pacmanNextpos(float step) {
    auto pacpos = pacman->getPosition();
    auto dir = pacman->getcurrentDirection();
    if (dir == 'N') {
        return pacpos;
    }
    else {
        auto next = calcDirection(step,dir,pacpos);
        return next;
    }
}
void World::redMovement(char s, float deltatime, float difficulty, float step) {
    for (auto ghost: ghosts) {
        if (ghost->getSymbol() == s) {
            if (countr == 0) {
                ghost->setPosition(Spawn[0]->original_pos());
                countr++;
            }
            if (ghost->getFearmode()) {
                step = (0.4f + difficulty/10) * deltatime;
                auto pos = ghost->getPosition();
                char dir = ghost->getcurrentDirection();
                vector<char> possible;
                for (auto way: directions) {
                    if (!checkIntersection(way,pos,ghost)) {
                        possible.push_back(way);
                    }
                }
                if (wallinDirectionGhost(dir,pos,ghost)) {
                    /*cout << "wall" << endl;*/
                    vector<char> possibleWays;
                    for (auto way: directions) {
                        if (!wallinDirectionGhost(way,pos,ghost)) {
                            possibleWays.push_back(way);
                        }
                    }
                    cout << possibleWays.size() << endl;
                    char cur;
                    if (possibleWays.size() == 2) {
                        int num = Random::getInstance().randomIndex(0,1);
                        cur = possibleWays[num];
                    }
                    else if (possibleWays.size() == 1) {
                        cur = possibleWays[0];
                    }
                    else if (possibleWays.size() == 3) {
                        int num = Random::getInstance().randomIndex(0,2);
                        cur = possibleWays[num];
                    }
                    auto nextpos = calcDirection(step,cur,pos);
                    if (!canMovethroughcorridor(2.09,nextpos)) {
                        return;
                    }
                    ghost->setPrevPosition(pos);
                    ghost->setPosition(nextpos);
                    ghost->setCurrentDirection(cur);
                    Event event(WhichEvent::Moved,ghost.get());
                    ghost->notify(event);
                }
                else if (possible.size()>=3) {
                    char cur = dir;
                    possible.erase(std::remove(possible.begin(), possible.end(), dir), possible.end());
                    if (Random::getInstance().probSwitch(0.5f)) {
                        int num = Random::getInstance().randomIndex(0,2);
                        cur = possible[num];
                        auto nextpos = calcDirection(step,cur,pos);
                        if (!canMovethroughcorridor(2.09,nextpos)) {
                            return;
                        }
                        ghost->setPrevPosition(pos);
                        ghost->setPosition(nextpos);
                        ghost->setCurrentDirection(cur);
                        Event event(WhichEvent::Moved,ghost.get());
                        ghost->notify(event);
                    }
                    else {
                        auto nextpos = calcDirection(step,dir,pos);
                        if (!canMovethroughcorridor(2.09,nextpos)) {
                            return;
                        }
                        ghost->setPrevPosition(pos);
                        ghost->setPosition(nextpos);
                        ghost->setCurrentDirection(dir);
                        Event event(WhichEvent::Moved,ghost.get());
                        ghost->notify(event);
                    }
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
                        cout << "wall" << endl;
                        return;
                    }
                    ghost->setPrevPosition(pos);
                    ghost->setPosition(nextPos);
                    Event event(WhichEvent::Moved,ghost.get());
                    ghost->notify(event);
                }
            }
            else {
                auto pos = ghost->getPosition();
                char dir = ghost->getcurrentDirection();
                vector<char> possible;
                for (auto way: directions) {
                    if (!checkIntersection(way,pos,ghost)) {
                        possible.push_back(way);
                    }
                }
                if (wallinDirectionGhost(dir,pos,ghost)) {
                    vector<char> possibleWays;
                    for (auto way: directions) {
                        if (!wallinDirectionGhost(way,pos,ghost)) {
                            possibleWays.push_back(way);
                        }
                    }
                    char cur;
                    if (possibleWays.size() == 2) {
                        int num = Random::getInstance().randomIndex(0,1);
                        cur = possibleWays[num];
                    }
                    else if (possibleWays.size() == 1) {
                        cur = possibleWays[0];
                    }
                    else if (possibleWays.size() == 3) {
                        int num = Random::getInstance().randomIndex(0,2);
                        cur = possibleWays[num];
                    }
                    auto nextpos = calcDirection(step,cur,pos);
                    if (!canMovethroughcorridor(2.09,nextpos)) {
                        return;
                    }
                    ghost->setPrevPosition(pos);
                    ghost->setPosition(nextpos);
                    ghost->setCurrentDirection(cur);
                    Event event(WhichEvent::Moved,ghost.get());
                    ghost->notify(event);
                }
                else if (possible.size()>=3) {
                    char cur = dir;
                    possible.erase(std::remove(possible.begin(), possible.end(), dir), possible.end());
                    if (Random::getInstance().probSwitch(0.5f)) {
                        /*cout << "chose to switch" << endl;*/
                        int num = Random::getInstance().randomIndex(0,2);
                        cur = possible[num];
                        /*cout << "to: " << cur << endl;*/
                        auto nextpos = calcDirection(step,cur,pos);
                        if (!canMovethroughcorridor(2.09,nextpos)) {
                            return;
                        }
                        ghost->setPrevPosition(pos);
                        ghost->setPosition(nextpos);
                        ghost->setCurrentDirection(cur);
                        Event event(WhichEvent::Moved,ghost.get());
                        ghost->notify(event);
                    }
                    else {
                        auto nextpos = calcDirection(step,dir,pos);
                        if (!canMovethroughcorridor(2.09,nextpos)) {
                            return;
                        }
                        ghost->setPrevPosition(pos);
                        ghost->setPosition(nextpos);
                        ghost->setCurrentDirection(dir);
                        Event event(WhichEvent::Moved,ghost.get());
                        ghost->notify(event);
                    }
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
                    Event event(WhichEvent::Moved,ghost.get());
                    ghost->notify(event);
                }
            }
        }
    }
}

void World::pinkMovement(char s, float deltatime, float difficulty, float step) {
    for (auto ghost: ghosts) {
        if (ghost->getSymbol() == s) {
            if (countp == 0) {
                ghost->setPosition(Spawn[1]->original_pos());
                countp++;
            }
            if (ghost->getFearmode()) {
                step = (0.4f + difficulty/10) * deltatime;
                auto pos = ghost->getPosition();
                char dir = ghost->getcurrentDirection();
                auto pacmanPos = pacmanNextpos(step);
                vector<char> possible;
                for (auto way: directions) {
                    if (!checkIntersection(way,pos,ghost)) {
                        possible.push_back(way);
                    }
                }
                if (wallinDirectionGhost(dir,pos,ghost)) {
                    cout << "wall" << endl;
                    vector<char> possibleWays;
                    for (auto way: directions) {
                        if (!wallinDirectionGhost(way,pos,ghost)) {
                            possibleWays.push_back(way);
                        }
                    }
                    cout << possibleWays.size() << endl;
                    char cur;
                    vector<tuple<char,float>> manhattenD;
                    for (auto next: possibleWays) {
                        auto ghostpos = ghost->getPosition();
                        auto nextGhost = calcDirection(step,next,ghostpos);
                        float distance = manhattanDistance(nextGhost,pacmanPos);
                        manhattenD.push_back({next,distance});
                    }
                    vector<char> maxManhatten;
                    float max = get<1>(manhattenD[0]);
                    for (auto fast: manhattenD) {
                        char symb = get<0>(fast);
                        float manh = get<1>(fast);
                        if (manh > max) {
                            maxManhatten.clear();
                            max = get<1>(fast);
                            maxManhatten.push_back(symb);
                        }
                        else if (manh == max) {
                            maxManhatten.push_back(symb);
                        }
                    }
                    if (maxManhatten.size() == 1) {
                        cur = maxManhatten[0];
                    }
                    else {
                        int num = Random::getInstance().randomIndex(0,maxManhatten.size()-1);
                        cur = maxManhatten[num];
                    }
                    auto nextpos = calcDirection(step,cur,pos);
                    if (!canMovethroughcorridor(2.09,nextpos)) {
                        return;
                    }
                    ghost->setPrevPosition(pos);
                    ghost->setPosition(nextpos);
                    ghost->setCurrentDirection(cur);
                    Event event(WhichEvent::Moved,ghost.get());
                    ghost->notify(event);
                }
                else if (possible.size()>=3) {
                    cout << possible.size() << endl;
                    char cur;
                    vector<tuple<char,float>> manhattenD;
                    for (auto next: possible) {
                        auto ghostpos = ghost->getPosition();
                        auto nextGhost = calcDirection(step,next,ghostpos);
                        float distance = manhattanDistance(nextGhost,pacmanPos);
                        manhattenD.push_back({next,distance});
                    }
                    vector<char> maxManhatten;
                    float max = get<1>(manhattenD[0]);
                    for (auto fast: manhattenD) {
                        char symb = get<0>(fast);
                        float manh = get<1>(fast);
                        if (manh > max) {
                            maxManhatten.clear();
                            max = get<1>(fast);
                            maxManhatten.push_back(symb);
                        }
                        else if (manh == max) {
                            maxManhatten.push_back(symb);
                        }
                    }
                    if (maxManhatten.size() == 1) {
                        cur = maxManhatten[0];
                    }
                    else {
                        int num = Random::getInstance().randomIndex(0,maxManhatten.size()-1);
                        cur = maxManhatten[num];
                    }
                    cout << "best way = " << cur << endl;
                    auto nextpos = calcDirection(step,cur,pos);
                    if (!canMovethroughcorridor(2.09,nextpos)) {
                        return;
                    }
                    ghost->setPrevPosition(pos);
                    ghost->setPosition(nextpos);
                    ghost->setCurrentDirection(cur);
                    Event event(WhichEvent::Moved,ghost.get());
                    ghost->notify(event);
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
                        cout << "wall" << endl;
                        return;
                    }
                    ghost->setPrevPosition(pos);
                    ghost->setPosition(nextPos);
                    Event event(WhichEvent::Moved,ghost.get());
                    ghost->notify(event);
                }
            }
            else {
                auto pos = ghost->getPosition();
                char dir = ghost->getcurrentDirection();
                auto pacmanPos = pacmanNextpos(step);
                vector<char> possible;
                for (auto way: directions) {
                    if (!checkIntersection(way,pos,ghost)) {
                        possible.push_back(way);
                    }
                }
                if (wallinDirectionGhost(dir,pos,ghost)) {
                    cout << "wall" << endl;
                    vector<char> possibleWays;
                    for (auto way: directions) {
                        if (!wallinDirectionGhost(way,pos,ghost)) {
                            possibleWays.push_back(way);
                        }
                    }
                    cout << possibleWays.size() << endl;
                    char cur;
                    vector<tuple<char,float>> manhattenD;
                    for (auto next: possibleWays) {
                        auto ghostpos = ghost->getPosition();
                        auto nextGhost = calcDirection(step,next,ghostpos);
                        float distance = manhattanDistance(nextGhost,pacmanPos);
                        manhattenD.push_back({next,distance});
                    }
                    vector<char> minManhatten;
                    float min = get<1>(manhattenD[0]);
                    for (auto fast: manhattenD) {
                        char symb = get<0>(fast);
                        float manh = get<1>(fast);
                        if (manh < min) {
                            minManhatten.clear();
                            min = get<1>(fast);
                            minManhatten.push_back(symb);
                        }
                        else if (manh == min) {
                            minManhatten.push_back(symb);
                        }
                    }
                    if (minManhatten.size() == 1) {
                        cur = minManhatten[0];
                    }
                    else {
                        int num = Random::getInstance().randomIndex(0,minManhatten.size()-1);
                        cur = minManhatten[num];
                    }
                    auto nextpos = calcDirection(step,cur,pos);
                    if (!canMovethroughcorridor(2.09,nextpos)) {
                        return;
                    }
                    ghost->setPrevPosition(pos);
                    ghost->setPosition(nextpos);
                    ghost->setCurrentDirection(cur);
                    Event event(WhichEvent::Moved,ghost.get());
                    ghost->notify(event);
                }
                else if (possible.size()>=3) {
                    cout << possible.size() << endl;
                    char cur;
                    vector<tuple<char,float>> manhattenD;
                    for (auto next: possible) {
                        auto ghostpos = ghost->getPosition();
                        auto nextGhost = calcDirection(step,next,ghostpos);
                        float distance = manhattanDistance(nextGhost,pacmanPos);
                        manhattenD.push_back({next,distance});
                    }
                    vector<char> minManhatten;
                    float min = get<1>(manhattenD[0]);
                    for (auto fast: manhattenD) {
                        char symb = get<0>(fast);
                        float manh = get<1>(fast);
                        if (manh < min) {
                            minManhatten.clear();
                            min = get<1>(fast);
                            minManhatten.push_back(symb);
                        }
                        else if (manh == min) {
                            minManhatten.push_back(symb);
                        }
                    }
                    if (minManhatten.size() == 1) {
                        cur = minManhatten[0];
                    }
                    else {
                        int num = Random::getInstance().randomIndex(0,minManhatten.size()-1);
                        cur = minManhatten[num];
                    }
                    cout << "best way = " << cur << endl;
                    auto nextpos = calcDirection(step,cur,pos);
                    if (!canMovethroughcorridor(2.09,nextpos)) {
                        return;
                    }
                    ghost->setPrevPosition(pos);
                    ghost->setPosition(nextpos);
                    ghost->setCurrentDirection(cur);
                    Event event(WhichEvent::Moved,ghost.get());
                    ghost->notify(event);
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
                        cout << "wall" << endl;
                        return;
                    }
                    ghost->setPrevPosition(pos);
                    ghost->setPosition(nextPos);
                    Event event(WhichEvent::Moved,ghost.get());
                    ghost->notify(event);
                }
            }
        }
    }
}
void World::blueMovement(char s, float deltatime, float difficulty, float step) {
    for (auto ghost: ghosts) {
        if (ghost->getSymbol() == s) {
            if (countb == 0) {
                ghost->setPosition(Spawn[0]->original_pos());
                countb++;
            }
            if (ghost->getFearmode()) {
                step = (0.4f +difficulty/10) * deltatime;
                auto pos = ghost->getPosition();
                char dir = ghost->getcurrentDirection();
                auto pacmanPos = pacmanNextpos(step);
                vector<char> possible;
                for (auto way: directions) {
                    if (!checkIntersection(way,pos,ghost)) {
                        possible.push_back(way);
                    }
                }
                if (wallinDirectionGhost(dir,pos,ghost)) {
                    cout << "wall" << endl;
                    vector<char> possibleWays;
                    for (auto way: directions) {
                        if (!wallinDirectionGhost(way,pos,ghost)) {
                            possibleWays.push_back(way);
                        }
                    }
                    cout << possibleWays.size() << endl;
                    char cur;
                    vector<tuple<char,float>> manhattenD;
                    for (auto next: possibleWays) {
                        auto ghostpos = ghost->getPosition();
                        auto nextGhost = calcDirection(step,next,ghostpos);
                        float distance = manhattanDistance(nextGhost,pacmanPos);
                        manhattenD.push_back({next,distance});
                    }
                    vector<char> maxManhatten;
                    float max = get<1>(manhattenD[0]);
                    for (auto fast: manhattenD) {
                        char symb = get<0>(fast);
                        float manh = get<1>(fast);
                        if (manh > max) {
                            maxManhatten.clear();
                            max = get<1>(fast);
                            maxManhatten.push_back(symb);
                        }
                        else if (manh == max) {
                            maxManhatten.push_back(symb);
                        }
                    }
                    if (maxManhatten.size() == 1) {
                        cur = maxManhatten[0];
                    }
                    else {
                        int num = Random::getInstance().randomIndex(0,maxManhatten.size()-1);
                        cur = maxManhatten[num];
                    }
                    auto nextpos = calcDirection(step,cur,pos);
                    if (!canMovethroughcorridor(2.09,nextpos)) {
                        return;
                    }
                    ghost->setPrevPosition(pos);
                    ghost->setPosition(nextpos);
                    ghost->setCurrentDirection(cur);
                    Event event(WhichEvent::Moved,ghost.get());
                    ghost->notify(event);
                }
                else if (possible.size()>=3) {
                    cout << possible.size() << endl;
                    char cur;
                    vector<tuple<char,float>> manhattenD;
                    for (auto next: possible) {
                        auto ghostpos = ghost->getPosition();
                        auto nextGhost = calcDirection(step,next,ghostpos);
                        float distance = manhattanDistance(nextGhost,pacmanPos);
                        manhattenD.push_back({next,distance});
                    }
                    vector<char> maxManhatten;
                    float max = get<1>(manhattenD[0]);
                    for (auto fast: manhattenD) {
                        char symb = get<0>(fast);
                        float manh = get<1>(fast);
                        if (manh > max) {
                            maxManhatten.clear();
                            max = get<1>(fast);
                            maxManhatten.push_back(symb);
                        }
                        else if (manh == max) {
                            maxManhatten.push_back(symb);
                        }
                    }
                    if (maxManhatten.size() == 1) {
                        cur = maxManhatten[0];
                    }
                    else {
                        int num = Random::getInstance().randomIndex(0,maxManhatten.size()-1);
                        cur = maxManhatten[num];
                    }
                    cout << "best way = " << cur << endl;
                    auto nextpos = calcDirection(step,cur,pos);
                    if (!canMovethroughcorridor(2.09,nextpos)) {
                        return;
                    }
                    ghost->setPrevPosition(pos);
                    ghost->setPosition(nextpos);
                    ghost->setCurrentDirection(cur);
                    Event event(WhichEvent::Moved,ghost.get());
                    ghost->notify(event);
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
                        cout << "wall" << endl;
                        return;
                    }
                    ghost->setPrevPosition(pos);
                    ghost->setPosition(nextPos);
                    Event event(WhichEvent::Moved,ghost.get());
                    ghost->notify(event);
                }
            }
            else {
                auto pos = ghost->getPosition();
                char dir = ghost->getcurrentDirection();
                auto pacmanPos = pacmanNextpos(step);
                vector<char> possible;
                for (auto way: directions) {
                    if (!checkIntersection(way,pos,ghost)) {
                        possible.push_back(way);
                    }
                }
                if (wallinDirectionGhost(dir,pos,ghost)) {
                    cout << "wall" << endl;
                    vector<char> possibleWays;
                    for (auto way: directions) {
                        if (!wallinDirectionGhost(way,pos,ghost)) {
                            possibleWays.push_back(way);
                        }
                    }
                    cout << possibleWays.size() << endl;
                    char cur;
                    vector<tuple<char,float>> manhattenD;
                    for (auto next: possibleWays) {
                        auto ghostpos = ghost->getPosition();
                        auto nextGhost = calcDirection(step,next,ghostpos);
                        float distance = manhattanDistance(nextGhost,pacmanPos);
                        manhattenD.push_back({next,distance});
                    }
                    vector<char> minManhatten;
                    float min = get<1>(manhattenD[0]);
                    for (auto fast: manhattenD) {
                        char symb = get<0>(fast);
                        float manh = get<1>(fast);
                        if (manh < min) {
                            minManhatten.clear();
                            min = get<1>(fast);
                            minManhatten.push_back(symb);
                        }
                        else if (manh == min) {
                            minManhatten.push_back(symb);
                        }
                    }
                    if (minManhatten.size() == 1) {
                        cur = minManhatten[0];
                    }
                    else {
                        int num = Random::getInstance().randomIndex(0,minManhatten.size()-1);
                        cur = minManhatten[num];
                    }
                    auto nextpos = calcDirection(step,cur,pos);
                    if (!canMovethroughcorridor(2.09,nextpos)) {
                        return;
                    }
                    ghost->setPrevPosition(pos);
                    ghost->setPosition(nextpos);
                    ghost->setCurrentDirection(cur);
                    Event event(WhichEvent::Moved,ghost.get());
                    ghost->notify(event);
                }
                else if (possible.size()>=3) {
                    cout << possible.size() << endl;
                    char cur;
                    vector<tuple<char,float>> manhattenD;
                    for (auto next: possible) {
                        auto ghostpos = ghost->getPosition();
                        auto nextGhost = calcDirection(step,next,ghostpos);
                        float distance = manhattanDistance(nextGhost,pacmanPos);
                        manhattenD.push_back({next,distance});
                    }
                    vector<char> minManhatten;
                    float min = get<1>(manhattenD[0]);
                    for (auto fast: manhattenD) {
                        char symb = get<0>(fast);
                        float manh = get<1>(fast);
                        if (manh < min) {
                            minManhatten.clear();
                            min = get<1>(fast);
                            minManhatten.push_back(symb);
                        }
                        else if (manh == min) {
                            minManhatten.push_back(symb);
                        }
                    }
                    if (minManhatten.size() == 1) {
                        cur = minManhatten[0];
                    }
                    else {
                        int num = Random::getInstance().randomIndex(0,minManhatten.size()-1);
                        cur = minManhatten[num];
                    }
                    cout << "best way = " << cur << endl;
                    auto nextpos = calcDirection(step,cur,pos);
                    if (!canMovethroughcorridor(2.09,nextpos)) {
                        return;
                    }
                    ghost->setPrevPosition(pos);
                    ghost->setPosition(nextpos);
                    ghost->setCurrentDirection(cur);
                    Event event(WhichEvent::Moved,ghost.get());
                    ghost->notify(event);
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
                        cout << "wall" << endl;
                        return;
                    }
                    ghost->setPrevPosition(pos);
                    ghost->setPosition(nextPos);
                    Event event(WhichEvent::Moved,ghost.get());
                    ghost->notify(event);
                }
            }
        }
    }
}
void World::orangeMovement(char s, float deltatime, float difficulty, float step) {
    for (auto ghost: ghosts) {
        if (ghost->getSymbol() == s) {
            if (counto == 0) {
                ghost->setPosition(Spawn[1]->original_pos());
                counto++;
            }
            if (ghost->getFearmode()) {
                step = (0.4f + difficulty/10) * deltatime;
                auto pos = ghost->getPosition();
                char dir = ghost->getcurrentDirection();
                auto pacmanPos = pacman->getPosition();
                vector<char> possible;
                for (auto way: directions) {
                    if (!checkIntersection(way,pos,ghost)) {
                        possible.push_back(way);
                    }
                }
                if (wallinDirectionGhost(dir,pos,ghost)) {
                    cout << "wall" << endl;
                    vector<char> possibleWays;
                    for (auto way: directions) {
                        if (!wallinDirectionGhost(way,pos,ghost)) {
                            possibleWays.push_back(way);
                        }
                    }
                    cout << possibleWays.size() << endl;
                    char cur;
                    vector<tuple<char,float>> manhattenD;
                    for (auto next: possibleWays) {
                        auto ghostpos = ghost->getPosition();
                        auto nextGhost = calcDirection(step,next,ghostpos);
                        float distance = manhattanDistance(nextGhost,pacmanPos);
                        manhattenD.push_back({next,distance});
                    }
                    vector<char> maxManhatten;
                    float max = get<1>(manhattenD[0]);
                    for (auto fast: manhattenD) {
                        char symb = get<0>(fast);
                        float manh = get<1>(fast);
                        if (manh > max) {
                            maxManhatten.clear();
                            max = get<1>(fast);
                            maxManhatten.push_back(symb);
                        }
                        else if (manh == max) {
                            maxManhatten.push_back(symb);
                        }
                    }
                    if (maxManhatten.size() == 1) {
                        cur = maxManhatten[0];
                    }
                    else {
                        int num = Random::getInstance().randomIndex(0,maxManhatten.size()-1);
                        cur = maxManhatten[num];
                    }
                    auto nextpos = calcDirection(step,cur,pos);
                    if (!canMovethroughcorridor(2.09,nextpos)) {
                        return;
                    }
                    ghost->setPrevPosition(pos);
                    ghost->setPosition(nextpos);
                    ghost->setCurrentDirection(cur);
                    Event event(WhichEvent::Moved,ghost.get());
                    ghost->notify(event);
                }
                else if (possible.size()>=3) {
                    cout << possible.size() << endl;
                    char cur;
                    vector<tuple<char,float>> manhattenD;
                    for (auto next: possible) {
                        auto ghostpos = ghost->getPosition();
                        auto nextGhost = calcDirection(step,next,ghostpos);
                        float distance = manhattanDistance(nextGhost,pacmanPos);
                        manhattenD.push_back({next,distance});
                    }
                    vector<char> maxManhatten;
                    float max = get<1>(manhattenD[0]);
                    for (auto fast: manhattenD) {
                        char symb = get<0>(fast);
                        float manh = get<1>(fast);
                        if (manh > max) {
                            maxManhatten.clear();
                            max = get<1>(fast);
                            maxManhatten.push_back(symb);
                        }
                        else if (manh == max) {
                            maxManhatten.push_back(symb);
                        }
                    }
                    if (maxManhatten.size() == 1) {
                        cur = maxManhatten[0];
                    }
                    else {
                        int num = Random::getInstance().randomIndex(0,maxManhatten.size()-1);
                        cur = maxManhatten[num];
                    }
                    cout << "best way = " << cur << endl;
                    auto nextpos = calcDirection(step,cur,pos);
                    if (!canMovethroughcorridor(2.09,nextpos)) {
                        return;
                    }
                    ghost->setPrevPosition(pos);
                    ghost->setPosition(nextpos);
                    ghost->setCurrentDirection(cur);
                    Event event(WhichEvent::Moved,ghost.get());
                    ghost->notify(event);
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
                        cout << "wall" << endl;
                        return;
                    }
                    ghost->setPrevPosition(pos);
                    ghost->setPosition(nextPos);
                    Event event(WhichEvent::Moved,ghost.get());
                    ghost->notify(event);
                }
            }
            else {
                auto pos = ghost->getPosition();
                char dir = ghost->getcurrentDirection();
                auto pacmanPos = pacman->getPosition();
                vector<char> possible;
                for (auto way: directions) {
                    if (!checkIntersection(way,pos,ghost)) {
                        possible.push_back(way);
                    }
                }
                if (wallinDirectionGhost(dir,pos,ghost)) {
                    cout << "wall" << endl;
                    vector<char> possibleWays;
                    for (auto way: directions) {
                        if (!wallinDirectionGhost(way,pos,ghost)) {
                            possibleWays.push_back(way);
                        }
                    }
                    cout << possibleWays.size() << endl;
                    char cur;
                    vector<tuple<char,float>> manhattenD;
                    for (auto next: possibleWays) {
                        auto ghostpos = ghost->getPosition();
                        auto nextGhost = calcDirection(step,next,ghostpos);
                        float distance = manhattanDistance(nextGhost,pacmanPos);
                        manhattenD.push_back({next,distance});
                    }
                    vector<char> minManhatten;
                    float min = get<1>(manhattenD[0]);
                    for (auto fast: manhattenD) {
                        char symb = get<0>(fast);
                        float manh = get<1>(fast);
                        if (manh < min) {
                            minManhatten.clear();
                            min = get<1>(fast);
                            minManhatten.push_back(symb);
                        }
                        else if (manh == min) {
                            minManhatten.push_back(symb);
                        }
                    }
                    if (minManhatten.size() == 1) {
                        cur = minManhatten[0];
                    }
                    else {
                        int num = Random::getInstance().randomIndex(0,minManhatten.size()-1);
                        cur = minManhatten[num];
                    }
                    auto nextpos = calcDirection(step,cur,pos);
                    if (!canMovethroughcorridor(2.09,nextpos)) {
                        return;
                    }
                    ghost->setPrevPosition(pos);
                    ghost->setPosition(nextpos);
                    ghost->setCurrentDirection(cur);
                    Event event(WhichEvent::Moved,ghost.get());
                    ghost->notify(event);
                }
                else if (possible.size()>=3) {
                    cout << possible.size() << endl;
                    char cur;
                    vector<tuple<char,float>> manhattenD;
                    for (auto next: possible) {
                        auto ghostpos = ghost->getPosition();
                        auto nextGhost = calcDirection(step,next,ghostpos);
                        float distance = manhattanDistance(nextGhost,pacmanPos);
                        manhattenD.push_back({next,distance});
                    }
                    vector<char> minManhatten;
                    float min = get<1>(manhattenD[0]);
                    for (auto fast: manhattenD) {
                        char symb = get<0>(fast);
                        float manh = get<1>(fast);
                        if (manh < min) {
                            minManhatten.clear();
                            min = get<1>(fast);
                            minManhatten.push_back(symb);
                        }
                        else if (manh == min) {
                            minManhatten.push_back(symb);
                        }
                    }
                    if (minManhatten.size() == 1) {
                        cur = minManhatten[0];
                    }
                    else {
                        int num = Random::getInstance().randomIndex(0,minManhatten.size()-1);
                        cur = minManhatten[num];
                    }
                    cout << "best way = " << cur << endl;
                    auto nextpos = calcDirection(step,cur,pos);
                    if (!canMovethroughcorridor(2.09,nextpos)) {
                        return;
                    }
                    ghost->setPrevPosition(pos);
                    ghost->setPosition(nextpos);
                    ghost->setCurrentDirection(cur);
                    Event event(WhichEvent::Moved,ghost.get());
                    ghost->notify(event);
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
                        cout << "wall" << endl;
                        return;
                    }
                    ghost->setPrevPosition(pos);
                    ghost->setPosition(nextPos);
                    Event event(WhichEvent::Moved,ghost.get());
                    ghost->notify(event);
                }
            }
        }
    }
}
/**
 * @Functionality Pacman eats coin
 *
 * @Explanation We use the same system as for walls only now the hitboxes are much smaller
 * so it only triggers when we are almost in the middle. We also make use of an event here.
 * To tell our view that the coin needs to disappear. The coin itself gets deleted from
 * eatenEntities and also all the entities.
 */
void World::GhostMovement(float deltatime) {
    float difficultytime = currentLevel;
    float difficulty = currentLevel/0.9-0.5*(currentLevel);
    float step = (0.5f + difficulty/10) * deltatime;
    time += deltatime;
    for (auto ghost: ghosts) {
        if (ghost->getFearmode()) {
            ghost->setFeartime(ghost->getFeartime()+deltatime);
            if (ghost->getFeartime() >= 5-difficultytime) {
                ghost->setFeartime(0.0);
                ghost->setFearmode(false);
                Event event(WhichEvent::changeGhost,ghost.get());
                ghost->notify(event);
            }
        }
    }
    for (auto ghost: ghosts) {
        if (ghost->getSymbol()=='r') {
            redMovement('r',deltatime,difficulty,step);
        }
        else if (ghost->getSymbol() == 'p') {
            pinkMovement('p',deltatime,difficulty,step);
        }
        else if (ghost->getSymbol() == 'b' && time >= 5.0f) {
            blueMovement('b',deltatime,difficulty,step);
        }
        else if (ghost->getSymbol() == 'o' && time >= 10.0f) {
            orangeMovement('o',deltatime,difficulty,step);
        }
    }
}
/**
 * @Functionality Pacman eats coin
 *
 * @Explanation We use the same system as for walls only now the hitboxes are much smaller
 * so it only triggers when we are almost in the middle. We also make use of an event here.
 * To tell our view that the coin needs to disappear. The coin itself gets deleted from
 * eatenEntities and also all the entities.
 */
void World::checkEatenFruit() {
    auto pac = pacman->getPosition();
    float xMin = get<0>(pac)-pacman->entity_width()/6;
    float xMax = get<0>(pac)+pacman->entity_width()/6;
    float yMin = get<1>(pac)+pacman->entity_height()/6;
    float yMax = get<1>(pac)-pacman->entity_height()/6;
    vector<shared_ptr<EntityModel>> fruits;
    for (auto entity: entities) {
        if (entity->getSymbol()== 'F') {
            auto coin = entity->getPosition();
            float wMinx = get<0>(coin)-entity->entity_width()/6;
            float wMaxx = get<0>(coin)+entity->entity_width()/6;
            float wMiny = get<1>(coin)+entity->entity_height()/6;
            float wMaxy = get<1>(coin)-entity->entity_height()/6;
            if (xMax > wMinx && xMin < wMaxx && yMax < wMiny && yMin > wMaxy) {
                cout << "fruit eaten" << endl;
                entity->setInteracted(true);
                Event event(WhichEvent::FruitGone,entity.get());
                entity->notify(event);
                fruits.push_back(entity);
                for (auto ghost: ghosts) {
                    ghost->setFearmode(true);
                    ghost->setFeartime(0.0);
                    Event event2(WhichEvent::FearMode,entity.get());
                    ghost->notify(event2);
                }
            }
        }
    }
    for (auto fruit: fruits) {
        removeEatenEntity(fruit);
    }
    for (auto fruit: fruits) {
        removeEntity(fruit);
    }
    if (ToBeEaten.empty()) {
        levelDone = true;
        won = true;
    }
}
/**
 * @Functionality Pacman eats coin
 *
 * @Explanation We use the same system as for walls only now the hitboxes are much smaller
 * so it only triggers when we are almost in the middle. We also make use of an event here.
 * To tell our view that the coin needs to disappear. The coin itself gets deleted from
 * eatenEntities and also all the entities.
 */
void World::reset() {
    countr = 0;
    countp = 0;
    countb = 0;
    counto = 0;
    for (auto ghost: ghosts) {
        time  = 0;
        ghost->setFearmode(false);
        Event event(WhichEvent::Moved,ghost.get());
        ghost->notify(event);
        ghost->setPosition(ghost->original_pos());
        ghost->setCurrentDirection('u');
    }
    pacman->setPosition(pacman->original_pos());
    pacman->setLives(pacman->getlives()-1);
    pacmanlives = pacman->getlives();
    pacman->setCurrentDirection('N');
    pacman->setnextDirection('N');
}
/**
 * @Functionality Pacman eats coin
 *
 * @Explanation We use the same system as for walls only now the hitboxes are much smaller
 * so it only triggers when we are almost in the middle. We also make use of an event here.
 * To tell our view that the coin needs to disappear. The coin itself gets deleted from
 * eatenEntities and also all the entities.
 */
void World::CheckGhost() {
    auto pac = pacman->getPosition();
    float xMin = get<0>(pac)-pacman->entity_width()/6;
    float xMax = get<0>(pac)+pacman->entity_width()/6;
    float yMin = get<1>(pac)+pacman->entity_height()/6;
    float yMax = get<1>(pac)-pacman->entity_height()/6;
    vector<shared_ptr<EntityModel>> ghosttodelete;
    for (auto ghost: ghosts) {
        auto ghostpos = ghost->getPosition();
        float wMinx = get<0>(ghostpos)-ghost->entity_width()/6;
        float wMaxx = get<0>(ghostpos)+ghost->entity_width()/6;
        float wMiny = get<1>(ghostpos)+ghost->entity_height()/6;
        float wMaxy = get<1>(ghostpos)-ghost->entity_height()/6;
        if (xMax > wMinx && xMin < wMaxx && yMax < wMiny && yMin > wMaxy) {
            if (ghost->getFearmode()) {
                ghost->setPosition(ghost->original_pos());
                switch (ghost->getSymbol()) {
                    case 'r':
                        countr = 0;
                        break;
                    case 'p':
                        countp = 0;
                        break;
                    case 'b':
                        countb = 0;
                        break;
                    case 'o':
                        counto = 0;
                        break;
                }
                ghost->setFearmode(false);
                Event event(WhichEvent::Moved,ghost.get());
                Event event2(WhichEvent::GhostEaten,ghost.get());
                ghost->notify(event);
                ghost->notify(event2);
            }
            else {
                reset();
            }
        }
    }
}