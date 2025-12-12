//
// Created by Youssef on 13/11/2025.
//

#include "EntityView.h"

#include "EntityModel.h"

void PacManRender::setSprite(const string &spritesheet) {
    spridesheet = spritesheet;
    if (!texture.loadFromFile(spritesheet)) {
        throw runtime_error("Failed to load texture: " + spritesheet);
    }
    float characterX = texture.getSize().x/19.0;
    float characterY = texture.getSize().y/19.0;
    xChar = characterX;
    yChar = characterY;
    /*sprite.setOrigin(xChar/2.0f,yChar/2.0f);*/
    currentImage = sf::IntRect(characterX*x,characterY*y,characterX,characterY);
    sprite.setTexture(texture);
    sprite.setTextureRect(currentImage);
    sprite.scale(2,2);
}

void PacManRender::render(sf::RenderWindow *window) {
    auto Position = link->getPosition();
    auto Pixels = camera.worldCoToPixelsCo(Position,0);
    float x = get<0>(Pixels);
    float y = get<1>(Pixels);
    sprite.setPosition(x,y);
    window->draw(sprite);
}

void PacManRender::update() {
    char direction = link->getnextDirection();
    switch (direction) {
        case 'u':
            y = 10;
            break;
        case 'd':
            y = 4;
            break;
        case 'l':
            y = 7;
            break;
        case 'r':
            y = 1;
            break;
    }
    currentImage = sf::IntRect(xChar*x,yChar*y,xChar,yChar);
    sprite.setTextureRect(currentImage);
    /*if (count >= 0 && count < 3) {
        spriteIndex = 1;
        y = y + spriteIndex;

        count++;
        spriteIndex = 0;
    }
    if (count >= 3 && count < 6) {
        spriteIndex = 2;
        y = y + spriteIndex;
        currentImage = sf::IntRect(xChar*x,yChar*y,xChar,yChar);
        sprite.setTexture(texture);
        sprite.scale(2,2);
        sprite.setTextureRect(currentImage);
        count++;
        spriteIndex = 0;
    }
    if (count >= 6 && count < 9) {
        spriteIndex = 0;
        y = y + spriteIndex;
        currentImage = sf::IntRect(xChar*x,yChar*y,xChar,yChar);
        sprite.setTexture(texture);
        sprite.scale(2,2);
        sprite.setTextureRect(currentImage);
        count++;
        spriteIndex = 0;
        if (count == 9) {
            count = 0;
        }
    }*/
}

void WallRender::render(sf::RenderWindow *window) {
    auto Position = link->getPosition();
    auto Pixels = camera.worldCoToPixelsCo(Position,0);
    float x = get<0>(Pixels);
    float y = get<1>(Pixels);
    /*wall.setOrigin(wall.getSize().x/2,wall.getSize().y/2);*/
    wall.setPosition(x,y);
    window->draw(wall);
}
void FloorRender::render(sf::RenderWindow *window) {
    auto Position = link->getPosition();
    auto Pixels = camera.worldCoToPixelsCo(Position,0);
    float x = get<0>(Pixels);
    float y = get<1>(Pixels);
    /*floor.setOrigin(floor.getSize().x/2,floor.getSize().y/2);*/
    floor.setPosition(x,y);
    window->draw(floor);
}
void FruitRender::setSprite(const string &spritesheet) {
    if (!texture.loadFromFile(spritesheet)) {
        throw runtime_error("Failed to load texture: " + spritesheet);
    }
    float characterX = texture.getSize().x/19.0;
    float characterY = texture.getSize().y/19.0;
    currentImage = sf::IntRect(characterX*x,characterY*y,characterX,characterY);
    sprite.setTexture(texture);
    sprite.setTextureRect(currentImage);
    sprite.setScale(2.7,2.7);
}
void FruitRender::render(sf::RenderWindow *window) {
    auto Position = link->getPosition();
    auto Pixels = camera.worldCoToPixelsCo(Position,0);
    float x = get<0>(Pixels);
    float y = get<1>(Pixels);
    /*sprite.setOrigin(currentImage.width/2,currentImage.height/2);*/
    sprite.setPosition(x,y);
    window->draw(sprite);
}
void CoinRender::setSprite(const string &spritesheet) {
    if (!texture.loadFromFile(spritesheet)) {
        throw runtime_error("Failed to load texture: " + spritesheet);
    }
    float characterX = texture.getSize().x/19.0;
    float characterY = texture.getSize().y/19.0;
    currentImage = sf::IntRect(characterX*x,characterY*y,characterX,characterY);
    sprite.setTexture(texture);
    sprite.setTextureRect(currentImage);
    sprite.setScale(1.2,1.2);
}
void CoinRender::render(sf::RenderWindow *window) {
    if (link->getInteracted()) {
        return;
    }
    auto Position = link->getPosition();
    auto Pixels = camera.worldCoToPixelsCo(Position,0);
    float x = get<0>(Pixels);
    float y = get<1>(Pixels);
    /*sprite.setOrigin(currentImage.width/2,currentImage.height/2);*/
    sprite.setPosition(x,y);
    window->draw(sprite);
}
/*auto worldPos = link->getPosition();
    auto [pixelX,pixelY] = camera.worldCoToPixelsCo(worldPos,100);
    float halfSize = 50.0f;
    sprite.setPosition(pixelX-halfSize-15,pixelY-halfSize+5);
    window->draw(sprite);*/





