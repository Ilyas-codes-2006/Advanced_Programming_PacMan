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

    virtual void setSprite(const string& spritesheet) = 0;

    virtual void render(sf::RenderWindow* window) = 0;

    virtual void update(const Event& event) override {}
    ~EntityView() override {
        link->detach(this);
    }
};
class PacManRender : public EntityView {
private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::IntRect currentImage;
    string spridesheet;
    float xChar;
    float yChar;
    int x = 17;
    int y = 0;
    int cycle = 0;
    float count = 0.0f;
    float switchMouth = 0.003f;
public:
    PacManRender(const shared_ptr<EntityModel> &link, Camera &camera)
        : EntityView(link, camera) {
    }
    void update(const Event& event) override;
    void setSprite(const string& spritesheet) override;
    void render(sf::RenderWindow *window) override;
};
class FloorRender : public EntityView {
private:
    sf::RectangleShape floor;
public:
    FloorRender(shared_ptr<EntityModel> model, Camera &camera) : EntityView(model, camera) {
        floor.setSize(sf::Vector2f(95, 91));
        floor.setFillColor(sf::Color::Black);
    }
    void setSprite(const string& spritesheet) override {}
    void update(const Event& event) override {}
    void render(sf::RenderWindow* window) override;
};
class WallRender : public EntityView {
private:
    sf::RectangleShape wall;
public:
    WallRender(shared_ptr<EntityModel> model, Camera &camera) : EntityView(model, camera) {
        wall.setSize(sf::Vector2f(95, 91));
        wall.setFillColor(sf::Color::Blue);
    }
    void setSprite(const string& spritesheet) override {}
    void update(const Event& event) override {}
    void render(sf::RenderWindow* window) override;
};
class SpawnRender : public EntityView {
private:
    sf::RectangleShape floor;
public:
    SpawnRender(shared_ptr<EntityModel> model, Camera &camera) : EntityView(model, camera) {
        floor.setSize(sf::Vector2f(95, 91));
        floor.setFillColor(sf::Color::Black);
    }
    void setSprite(const string& spritesheet) override {}
    void update(const Event& event) override {}
    void render(sf::RenderWindow* window) override;
};
class CoinRender : public EntityView {
private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::IntRect currentImage;
    int x = 8;
    int y = 5;
public:
    CoinRender(const shared_ptr<EntityModel> &link, Camera &camera)
        : EntityView(link, camera) {
    }
    void update(const Event& event) override {}
    void setSprite(const string& spritesheet) override;
    void render(sf::RenderWindow *window) override;
};
class FruitRender : public EntityView {
private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::IntRect currentImage;
    int x = 8;
    int y = 5;
public:
    FruitRender(const shared_ptr<EntityModel> &link, Camera &camera)
        : EntityView(link, camera) {
    }
    void update(const Event& event) override {}
    void setSprite(const string& spritesheet) override;
    void render(sf::RenderWindow *window) override;
};
class GhostRender : public EntityView {
private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::IntRect currentImage;
    string spridesheet;
    float xChar;
    float yChar;
    int x;
    int y;
    int cycle = 0;
    float count = 0.0f;
    float switchMouth = 0.008f;
    int cycle2 = 0;
    float count2 = 0.0f;
    float switchMouth2 = 0.008f;
public:
    GhostRender(const shared_ptr<EntityModel> &link, Camera &camera)
        : EntityView(link, camera) {
    }
    void update(const Event& event) override;
    void setSprite(const string& spritesheet) override;
    void render(sf::RenderWindow *window) override;
};


#endif //ADVANCEDPROGRAMMING_PACMAN_ENTITYVIEW_H