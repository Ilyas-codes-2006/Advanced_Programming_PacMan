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
    shared_ptr<EntityModel> FloorEntity(const tuple<float, float> &positie,char symbol,const tuple<float, float> &original) override;
    shared_ptr<EntityModel> PacManEntity(const tuple<float, float> &positie,char symbol,const tuple<float, float> &original) override;
    shared_ptr<EntityModel> WallEntity(const tuple<float, float> &positie,char symbol,const tuple<float, float> &original) override;
    shared_ptr<EntityModel> CoinEntity(const tuple<float, float> &positie,char symbol,const tuple<float, float> &original) override;
    shared_ptr<EntityModel> FruitEntity(const tuple<float, float> &positie,char symbol,const tuple<float, float> &original) override;
    shared_ptr<EntityModel> GhostEntity(const tuple<float, float> &positie,char symbol,const tuple<float, float> &original) override;
    shared_ptr<EntityModel> SpawnEntity(const tuple<float, float> &positie,char symbol,const tuple<float, float> &original) override;
    shared_ptr<EntityView> WallView(shared_ptr<EntityModel> model, Camera &camera) override;
    shared_ptr<EntityView> PacManView(shared_ptr<EntityModel> model, Camera &camera) override;
    shared_ptr<EntityView> FloorView(shared_ptr<EntityModel> model, Camera &camera) override;
    shared_ptr<EntityView> CoinView(shared_ptr<EntityModel> model, Camera &camera) override;
    shared_ptr<EntityView> FruitView(shared_ptr<EntityModel> model, Camera &camera) override;
    shared_ptr<EntityView> GhostView(shared_ptr<EntityModel> model, Camera &camera) override;
    shared_ptr<EntityView> SpawnView(shared_ptr<EntityModel> model, Camera &camera) override;
    ~ConcreteFactory() override = default;
};


#endif //ADVANCEDPROGRAMMING_PACMAN_CONCRETEFACTORY_H