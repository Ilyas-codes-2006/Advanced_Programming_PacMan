//
// Created by Youssef on 14/11/2025.
//

#include "ConcreteFactory.h"

#include "EntityView.h"

shared_ptr<EntityModel> ConcreteFactory::PacManEntity(const tuple<float, float> &positie,char symbol,const tuple<float, float> &original) {
    return make_shared<PacMan>(positie,symbol,original);
}
shared_ptr<EntityModel> ConcreteFactory::WallEntity(const tuple<float, float> &positie,char symbol,const tuple<float, float> &original) {
    return make_shared<Wall>(positie,symbol,original);
}
shared_ptr<EntityModel> ConcreteFactory::FloorEntity(const tuple<float, float> &positie,char symbol,const tuple<float, float> &original) {
    return make_shared<Floor>(positie,symbol,original);
}
shared_ptr<EntityModel> ConcreteFactory::CoinEntity(const tuple<float, float> &positie,char symbol,const tuple<float, float> &original) {
    return make_shared<Coin>(positie,symbol,original);
}
shared_ptr<EntityModel> ConcreteFactory::FruitEntity(const tuple<float, float> &positie, char symbol,const tuple<float, float> &original) {
    return make_shared<Fruit>(positie,symbol,original);
}
shared_ptr<EntityModel> ConcreteFactory::GhostEntity(const tuple<float, float> &positie, char symbol,const tuple<float, float> &original) {
    return make_shared<Ghost>(positie,symbol,original);
}
shared_ptr<EntityModel> ConcreteFactory::SpawnEntity(const tuple<float, float> &positie, char symbol,const tuple<float, float> &original) {
    return make_shared<Spawn>(positie,symbol,original);
}
shared_ptr<PacManRender> ConcreteFactory::PacManView(shared_ptr<EntityModel> model, Camera &camera) {
    return make_shared<PacManRender>(model,camera);
}
shared_ptr<WallRender> ConcreteFactory::WallView(shared_ptr<EntityModel> model, Camera &camera) {
    return make_shared<WallRender>(model,camera);
}
shared_ptr<FloorRender> ConcreteFactory::FloorView(shared_ptr<EntityModel> model, Camera &camera) {
    return make_shared<FloorRender>(model,camera);
}
shared_ptr<CoinRender> ConcreteFactory::CoinView(shared_ptr<EntityModel> model, Camera &camera) {
    return make_shared<CoinRender>(model,camera);
}
shared_ptr<FruitRender> ConcreteFactory::FruitView(shared_ptr<EntityModel> model, Camera &camera) {
    return make_shared<FruitRender>(model,camera);
}
shared_ptr<GhostRender> ConcreteFactory::GhostView(shared_ptr<EntityModel> model, Camera &camera) {
    return make_shared<GhostRender>(model,camera);
}
shared_ptr<SpawnRender> ConcreteFactory::SpawnView(shared_ptr<EntityModel> model, Camera &camera) {
    return make_shared<SpawnRender>(model,camera);
}






