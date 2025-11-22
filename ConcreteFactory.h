//
// Created by Youssef on 14/11/2025.
//

#ifndef ADVANCEDPROGRAMMING_PACMAN_CONCRETEFACTORY_H
#define ADVANCEDPROGRAMMING_PACMAN_CONCRETEFACTORY_H

#include "AbstractFactory.h"
#include "EntityModel.h"

class ConcreteFactory: public AbstractFactory {
public:
    shared_ptr<PacMan> PacManEntity(const tuple<float, float> &positie) override;
    shared_ptr<Wall> WallEntity(const tuple<float, float> &positie) override;
    /*shared_ptr<Ghost> GhostEntity(const tuple<float, float> &positie) override;*/
    /*shared_ptr<Collectable> CoinEntity(const tuple<float, float> &positie) override;
    shared_ptr<Collectable> FruitEntity(const tuple<float, float> &positie) override;*/
};


#endif //ADVANCEDPROGRAMMING_PACMAN_CONCRETEFACTORY_H