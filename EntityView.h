//
// Created by Youssef on 13/11/2025.
//

#ifndef ADVANCEDPROGRAMMING_PACMAN_ENTITYVIEW_H
#define ADVANCEDPROGRAMMING_PACMAN_ENTITYVIEW_H

#include <memory>
#include <SFML/Graphics.hpp>
using namespace std;
class EntityModel;
class PacMan;

class EntityView {
protected:
    shared_ptr<EntityModel> link;
public:
    explicit EntityView(const shared_ptr<EntityModel> &link)
        : link(link) {
    }
    virtual void render(sf::RenderWindow* window) = 0;
};
class PacManRender : public EntityView {
private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::IntRect currentImage;
public:
    void setSprite(const string& spritesheet);
    void render(sf::RenderWindow *window) override;
};
class WallRender : public EntityView {
private:
    sf::RectangleShape wall;
public:
    WallRender(shared_ptr<EntityModel> model) : EntityView(model) {
        wall.setSize(sf::Vector2f(19, 19));
        wall.setFillColor(sf::Color::Blue);
    }
    void render(sf::RenderWindow* window) override;
};


#endif //ADVANCEDPROGRAMMING_PACMAN_ENTITYVIEW_H