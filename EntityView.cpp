//
// Created by Youssef on 13/11/2025.
//

#include "EntityView.h"

#include "EntityModel.h"

void PacManRender::setSprite(const string &spritesheet,float c, float r) {
    if (!texture.loadFromFile(spritesheet)) {
        throw runtime_error("Failed to load texture: " + spritesheet);
    }
    float characterX = texture.getSize().x/19.0;
    float characterY = texture.getSize().y/19.0;
    currentImage = sf::IntRect(characterX*c,characterY*r,characterX,characterY);
    sprite.setTexture(texture);
    sprite.setTextureRect(currentImage);
}

void PacManRender::render(sf::RenderWindow *window) {
    auto Position = link->getPosition();
    auto Pixels = camera.worldCoToPixelsCo(Position,0);
    float x = get<0>(Pixels);
    float y = get<1>(Pixels);
    sprite.setOrigin(currentImage.width/2.0,currentImage.height/2.0);
    sprite.setPosition(x,y);
    window->draw(sprite);
}

void WallRender::render(sf::RenderWindow *window) {
    auto Position = link->getPosition();
    auto Pixels = camera.worldCoToPixelsCo(Position,0);
    float x = get<0>(Pixels);
    float y = get<1>(Pixels);
    wall.setOrigin(wall.getSize().x/2,wall.getSize().y/2);
    wall.setPosition(x,y);
    window->draw(wall);
}
void FloorRender::render(sf::RenderWindow *window) {
    auto Position = link->getPosition();
    auto Pixels = camera.worldCoToPixelsCo(Position,0);
    float x = get<0>(Pixels);
    float y = get<1>(Pixels);
    floor.setOrigin(floor.getSize().x/2,floor.getSize().y/2);
    floor.setPosition(x,y);
    window->draw(floor);
}
void FruitRender::setSprite(const string &spritesheet, float c, float r) {
    if (!texture.loadFromFile(spritesheet)) {
        throw runtime_error("Failed to load texture: " + spritesheet);
    }
    float characterX = texture.getSize().x/19.0;
    float characterY = texture.getSize().y/19.0;
    currentImage = sf::IntRect(characterX*c,characterY*r,characterX,characterY);
    sprite.setTexture(texture);
    sprite.setTextureRect(currentImage);
    sprite.setScale(2.7,2.7);
}
void FruitRender::render(sf::RenderWindow *window) {
    auto Position = link->getPosition();
    auto Pixels = camera.worldCoToPixelsCo(Position,0);
    float x = get<0>(Pixels);
    float y = get<1>(Pixels);
    sprite.setOrigin(currentImage.width/2,currentImage.height/2);
    sprite.setPosition(x,y);
    window->draw(sprite);
}
void CoinRender::setSprite(const string &spritesheet, float c, float r) {
    if (!texture.loadFromFile(spritesheet)) {
        throw runtime_error("Failed to load texture: " + spritesheet);
    }
    float characterX = texture.getSize().x/19.0;
    float characterY = texture.getSize().y/19.0;
    currentImage = sf::IntRect(characterX*c,characterY*r,characterX,characterY);
    sprite.setTexture(texture);
    sprite.setTextureRect(currentImage);
    sprite.setScale(1.2,1.2);
}
void CoinRender::render(sf::RenderWindow *window) {
    auto Position = link->getPosition();
    auto Pixels = camera.worldCoToPixelsCo(Position,0);
    float x = get<0>(Pixels);
    float y = get<1>(Pixels);
    sprite.setOrigin(currentImage.width/2,currentImage.height/2);
    sprite.setPosition(x,y);
    window->draw(sprite);
}
/*auto worldPos = link->getPosition();
    auto [pixelX,pixelY] = camera.worldCoToPixelsCo(worldPos,100);
    float halfSize = 50.0f;
    sprite.setPosition(pixelX-halfSize-15,pixelY-halfSize+5);
    window->draw(sprite);*/





