//
// Created by Youssef on 13/11/2025.
//

#include "EntityView.h"

#include "EntityModel.h"

void PacManRender::setSprite(const string &spritesheet) {
    if (!texture.loadFromFile(spritesheet)) {
        throw runtime_error("Failed to load texture: " + spritesheet);
    }
    sprite.setTexture(texture);
    currentImage = sf::IntRect(893,0,19,19);
    sprite.setTextureRect(currentImage);
}

void PacManRender::render(sf::RenderWindow *window) {
    auto [x, y] = link->getPosition();
    sprite.setPosition(x,y);
    window->draw(sprite);
}

void WallRender::render(sf::RenderWindow *window) {
    auto [x, y] = link->getPosition();
    wall.setPosition(x, y);
    window->draw(wall);
}



