//
// Created by Youssef on 14/11/2025.
//

#ifndef ADVANCEDPROGRAMMING_PACMAN_ABSTRACTFACTORY_H
#define ADVANCEDPROGRAMMING_PACMAN_ABSTRACTFACTORY_H
#include <memory>

#include "EntityView.h"
using namespace std;
class EntityModel;
class EntityView;
class Camera;
class Wall;
class Ghost;
class Collectable;

class AbstractFactory {
public:
    virtual shared_ptr<EntityModel> FloorEntity(const tuple<float,float>& positie,char symbol) = 0;
    virtual shared_ptr<EntityModel> PacManEntity(const tuple<float,float>& positie,char symbol) = 0;
    virtual shared_ptr<EntityModel> WallEntity(const tuple<float,float>& positie,char symbol) = 0;
    virtual std::shared_ptr<EntityModel> CoinEntity(const tuple<float,float>& positie,char symbol) = 0;
    virtual std::shared_ptr<EntityModel> FruitEntity(const tuple<float,float>& positie,char symbol) = 0;
    virtual shared_ptr<PacManRender> PacManView(shared_ptr<EntityModel> model, Camera& camera) = 0;
    virtual shared_ptr<WallRender> WallView(shared_ptr<EntityModel> model, Camera& camera) = 0;
    virtual shared_ptr<FloorRender> FloorView(shared_ptr<EntityModel> model, Camera& camera) = 0;
    virtual shared_ptr<CoinRender> CoinView(shared_ptr<EntityModel> model, Camera& camera) = 0;
    virtual shared_ptr<FruitRender> FruitView(shared_ptr<EntityModel> model, Camera& camera) = 0;
    /*virtual std::shared_ptr<Ghost> GhostEntity(const tuple<float,float>& positie) = 0;*/
    virtual ~AbstractFactory() = default;
};


#endif //ADVANCEDPROGRAMMING_PACMAN_ABSTRACTFACTORY_H