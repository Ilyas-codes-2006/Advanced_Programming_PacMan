//
// Created by Youssef on 14/11/2025.
//

#include "ConcreteFactory.h"

#include "EntityView.h"

shared_ptr<EntityModel> ConcreteFactory::PacManEntity(const tuple<float, float> &positie) {
    return make_shared<PacMan>(positie);
}
shared_ptr<EntityModel> ConcreteFactory::WallEntity(const tuple<float, float> &positie) {
    return make_shared<Wall>(positie);
}
shared_ptr<EntityModel> ConcreteFactory::FloorEntity(const tuple<float, float> &positie) {
    return make_shared<Floor>(positie);
}
shared_ptr<EntityView> ConcreteFactory::PacManView(shared_ptr<EntityModel> model, Camera &camera) {
    return make_shared<PacManRender>(model,camera);
}
shared_ptr<EntityView> ConcreteFactory::WallView(shared_ptr<EntityModel> model, Camera &camera) {
    return make_shared<WallRender>(model,camera);
}
shared_ptr<EntityView> ConcreteFactory::FloorView(shared_ptr<EntityModel> model, Camera &camera) {
    return make_shared<FloorRender>(model,camera);
}



