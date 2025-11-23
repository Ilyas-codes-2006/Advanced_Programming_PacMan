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
    currentImage = sf::IntRect(893,0,100,100);
    sprite.setTextureRect(currentImage);
}

void PacManRender::render(sf::RenderWindow *window) {
    auto worldPos = link->getPosition();
    auto [pixelX,pixelY] = camera.worldCoToPixelsCo(worldPos);
    sprite.setPosition(pixelX,pixelY);
    window->draw(sprite);
}

void WallRender::render(sf::RenderWindow *window) {
    auto worldPos = link->getPosition();
    auto [pixelX,pixelY] = camera.worldCoToPixelsCo(worldPos);
    wall.setPosition(pixelX,pixelY);
    window->draw(wall);
}
void FloorRender::render(sf::RenderWindow *window) {
    auto worldPos = link->getPosition();
    auto [pixelX,pixelY] = camera.worldCoToPixelsCo(worldPos);
    floor.setPosition(pixelX,pixelY);
    window->draw(floor);
}



