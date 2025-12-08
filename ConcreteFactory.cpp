//
// Created by Youssef on 14/11/2025.
//

#include "ConcreteFactory.h"

#include "EntityView.h"

shared_ptr<EntityModel> ConcreteFactory::PacManEntity(const tuple<float, float> &positie,char symbol) {
    return make_shared<PacMan>(positie,symbol);
}
shared_ptr<EntityModel> ConcreteFactory::WallEntity(const tuple<float, float> &positie,char symbol) {
    return make_shared<Wall>(positie,symbol);
}
shared_ptr<EntityModel> ConcreteFactory::FloorEntity(const tuple<float, float> &positie,char symbol) {
    return make_shared<Floor>(positie,symbol);
}
shared_ptr<EntityModel> ConcreteFactory::CoinEntity(const tuple<float, float> &positie,char symbol) {
    return make_shared<Coin>(positie,symbol);
}
shared_ptr<EntityModel> ConcreteFactory::FruitEntity(const tuple<float, float> &positie, char symbol) {
    return make_shared<Fruit>(positie,symbol);
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






