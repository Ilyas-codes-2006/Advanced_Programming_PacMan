//
// Created by Youssef on 14/11/2025.
//

#ifndef ADVANCEDPROGRAMMING_PACMAN_ABSTRACTFACTORY_H
#define ADVANCEDPROGRAMMING_PACMAN_ABSTRACTFACTORY_H
#include <memory>
using namespace std;
class PacMan;
class Wall;
class Ghost;
class Collectable;

class AbstractFactory {
public:
    /*virtual std::shared_ptr<PacMan> PacManEntity(const tuple<float,float>& positie) = 0;
    virtual std::shared_ptr<Wall> WallEntity(const tuple<float,float>& positie) = 0;*/
    /*virtual std::shared_ptr<Ghost> GhostEntity(const tuple<float,float>& positie) = 0;
    virtual std::shared_ptr<Collectable> CoinEntity(const tuple<float,float>& positie) = 0;
    virtual std::shared_ptr<Collectable> FruitEntity(const tuple<float,float>& positie) = 0;*/
};


#endif //ADVANCEDPROGRAMMING_PACMAN_ABSTRACTFACTORY_H