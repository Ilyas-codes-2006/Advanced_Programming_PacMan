//
// Created by Youssef on 13/11/2025.
//

#ifndef ADVANCEDPROGRAMMING_PACMAN_ENTITYVIEW_H
#define ADVANCEDPROGRAMMING_PACMAN_ENTITYVIEW_H

#include <memory>
#include <SFML/Graphics.hpp>

#include "EntityModel.h"
#include "Camera.h"
#include "Observer.h"
using namespace std;
class EntityModel;

class EntityView: public Observer {
protected:
    shared_ptr<EntityModel> link;
    Camera& camera;
public:
    EntityView(const shared_ptr<EntityModel> &link, Camera &camera)
        : link(link),
          camera(camera) {
        link->attach(this);
    }

    [[nodiscard]] shared_ptr<EntityModel> getLink() const {
        return link;
    }

    virtual void render(sf::RenderWindow* window) = 0;

    virtual void update() override{}
    ~EntityView() override {
        link->detach(this);
    }
};
class PacManRender : public EntityView {
private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::IntRect currentImage;
public:
    PacManRender(const shared_ptr<EntityModel> &link, Camera &camera)
        : EntityView(link, camera) {
    }
    void update() override {}
    void setSprite(const string& spritesheet);
    void render(sf::RenderWindow *window) override;
};
class FloorRender : public EntityView {
private:
    sf::RectangleShape floor;
public:
    FloorRender(shared_ptr<EntityModel> model, Camera &camera) : EntityView(model, camera) {
        floor.setSize(sf::Vector2f(100, 100));
        floor.setFillColor(sf::Color::Black);
    }
    void update() override {}
    void render(sf::RenderWindow* window) override;
};
class WallRender : public EntityView {
private:
    sf::RectangleShape wall;
public:
    WallRender(shared_ptr<EntityModel> model, Camera &camera) : EntityView(model, camera) {
        wall.setSize(sf::Vector2f(100, 100));
        wall.setFillColor(sf::Color::Blue);
    }
    void update() override {}
    void render(sf::RenderWindow* window) override;
};


#endif //ADVANCEDPROGRAMMING_PACMAN_ENTITYVIEW_H