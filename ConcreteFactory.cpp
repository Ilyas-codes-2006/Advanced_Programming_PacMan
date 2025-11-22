//
// Created by Youssef on 14/11/2025.
//

#include "ConcreteFactory.h"
shared_ptr<PacMan> ConcreteFactory::PacManEntity(const tuple<float, float> &positie) {
    return make_shared<PacMan>(positie);
}
shared_ptr<Wall> ConcreteFactory::WallEntity(const tuple<float, float> &positie) {
    return make_shared<Wall>(positie);
}
/*shared_ptr<Ghost> ConcreteFactory::GhostEntity(const tuple<float, float> &positie) {
    return make_shared<Ghost>(positie);
}*/


