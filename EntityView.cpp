//
// Created by Youssef on 13/11/2025.
//

#include "EntityView.h"

#include "EntityModel.h"

void PacManRender::setSprite(const string &spritesheet,float c, float r) {
    if (!texture.loadFromFile(spritesheet)) {
        throw runtime_error("Failed to load texture: " + spritesheet);
    }
    sprite.setTexture(texture);
    float spriteCountX = 19;
    float spriteCountY = 19;
    float beginspriteX = 18;
    float beginspriteY = 1;

    float spriteWidth = texture.getSize().x/spriteCountX;
    float spriteHeight = texture.getSize().y/spriteCountY;
    int col = c;
    int row = r;
    currentImage = sf::IntRect(col*spriteWidth,row*spriteHeight,spriteWidth,spriteHeight);
    float scaleX = 100.0f/spriteWidth;
    float scaleY = 100.0f/spriteHeight;
    sprite.setScale(scaleX,scaleY);
    sprite.setTextureRect(currentImage);
}

void PacManRender::render(sf::RenderWindow *window) {
    auto worldPos = link->getPosition();
    auto [pixelX,pixelY] = camera.worldCoToPixelsCo(worldPos);
    float halfSize = 50.0f;
    sprite.setPosition(pixelX-halfSize,pixelY-halfSize);
    window->draw(sprite);
}

void WallRender::render(sf::RenderWindow *window) {
    auto worldPos = link->getPosition();
    auto [pixelX,pixelY] = camera.worldCoToPixelsCo(worldPos);
    float halfSize = 50.0f;
    wall.setPosition(pixelX-halfSize,pixelY-halfSize);
    window->draw(wall);
}
void FloorRender::render(sf::RenderWindow *window) {
    auto worldPos = link->getPosition();
    auto [pixelX,pixelY] = camera.worldCoToPixelsCo(worldPos);
    float halfSize = 50.0f;
    floor.setPosition(pixelX-halfSize,pixelY-halfSize);
    window->draw(floor);
}



