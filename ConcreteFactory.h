//
// Created by Youssef on 14/11/2025.
//

#ifndef ADVANCEDPROGRAMMING_PACMAN_CONCRETEFACTORY_H
#define ADVANCEDPROGRAMMING_PACMAN_CONCRETEFACTORY_H

#include "AbstractFactory.h"
#include "EntityModel.h"
#include "EntityView.h"

class ConcreteFactory: public AbstractFactory {
public:
    shared_ptr<EntityModel> FloorEntity(const tuple<float, float> &positie,char symbol) override;
    shared_ptr<EntityModel> PacManEntity(const tuple<float, float> &positie,char symbol) override;
    shared_ptr<EntityModel> WallEntity(const tuple<float, float> &positie,char symbol) override;
    shared_ptr<EntityModel> CoinEntity(const tuple<float, float> &positie,char symbol) override;
    shared_ptr<EntityModel> FruitEntity(const tuple<float, float> &positie,char symbol) override;
    shared_ptr<WallRender> WallView(shared_ptr<EntityModel> model, Camera &camera) override;
    shared_ptr<PacManRender> PacManView(shared_ptr<EntityModel> model, Camera &camera) override;
    shared_ptr<FloorRender> FloorView(shared_ptr<EntityModel> model, Camera &camera) override;
    shared_ptr<CoinRender> CoinView(shared_ptr<EntityModel> model, Camera &camera) override;
    shared_ptr<FruitRender> FruitView(shared_ptr<EntityModel> model, Camera &camera) override;
    /*shared_ptr<Ghost> GhostEntity(const tuple<float, float> &positie) override;*/
    ~ConcreteFactory() override = default;
};


#endif //ADVANCEDPROGRAMMING_PACMAN_CONCRETEFACTORY_H