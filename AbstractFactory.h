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
/**
 * @Functionality Pacman eats coin
 *
 * @Explanation We use the same system as for walls only now the hitboxes are much smaller
 * so it only triggers when we are almost in the middle. We also make use of an event here.
 * To tell our view that the coin needs to disappear. The coin itself gets deleted from
 * eatenEntities and also all the entities.
 */
class AbstractFactory {
public:
    virtual shared_ptr<EntityModel> FloorEntity(const tuple<float,float>& positie,char symbol,const tuple<float, float> &original) = 0;
    virtual shared_ptr<EntityModel> PacManEntity(const tuple<float,float>& positie,char symbol,const tuple<float, float> &original) = 0;
    virtual shared_ptr<EntityModel> WallEntity(const tuple<float,float>& positie,char symbol,const tuple<float, float> &original) = 0;
    virtual shared_ptr<EntityModel> CoinEntity(const tuple<float,float>& positie,char symbol,const tuple<float, float> &original) = 0;
    virtual shared_ptr<EntityModel> FruitEntity(const tuple<float,float>& positie,char symbol,const tuple<float, float> &original) = 0;
    virtual shared_ptr<EntityModel> GhostEntity(const tuple<float,float>& positie,char symbol,const tuple<float, float> &original) = 0;
    virtual shared_ptr<EntityModel> SpawnEntity(const tuple<float,float>& positie,char symbol,const tuple<float, float> &original) = 0;
    virtual shared_ptr<EntityView> PacManView(shared_ptr<EntityModel> model, Camera& camera) = 0;
    virtual shared_ptr<EntityView> WallView(shared_ptr<EntityModel> model, Camera& camera) = 0;
    virtual shared_ptr<EntityView> FloorView(shared_ptr<EntityModel> model, Camera& camera) = 0;
    virtual shared_ptr<EntityView> CoinView(shared_ptr<EntityModel> model, Camera& camera) = 0;
    virtual shared_ptr<EntityView> FruitView(shared_ptr<EntityModel> model, Camera& camera) = 0;
    virtual shared_ptr<EntityView> GhostView(shared_ptr<EntityModel> model, Camera& camera) = 0;
    virtual shared_ptr<EntityView> SpawnView(shared_ptr<EntityModel> model, Camera& camera) = 0;


    virtual ~AbstractFactory() = default;
};


#endif //ADVANCEDPROGRAMMING_PACMAN_ABSTRACTFACTORY_H