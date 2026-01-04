//
// Created by Youssef on 13/11/2025.
//

#include "EntityView.h"

#include "EntityModel.h"
#
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
    sprite.setPosition(x-16,y+3);
    window->draw(sprite);
}

void PacManRender::update(const Event& event) {
    if (event.type==WhichEvent::Moved) {
        char direction = link->getcurrentDirection();
        int pos = 0;
        switch (direction) {
            case 'u':
                pos = 9;
                break;
            case 'd':
                pos = 4;
                break;
            case 'l':
                pos = 7;
                break;
            case 'r':
                pos = 1;
                break;
        }
        count+=Stopwatch::getInstance().tick();
        if (count >= switchMouth) {
            switch (cycle) {
                case 0:
                    y = pos+1;
                    cycle++;
                    break;
                case 1:
                    y = pos+2;
                    cycle++;
                    break;
                case 2:
                    y = pos;
                    cycle = 0;
                    break;
            }
            count = 0.0f;
        }
        currentImage = sf::IntRect(xChar*x,yChar*y,xChar,yChar);
        sprite.setTextureRect(currentImage);
    }
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

void SpawnRender::render(sf::RenderWindow *window) {
    auto Position = link->getPosition();
    auto Pixels = camera.worldCoToPixelsCo(Position,0);
    float x = get<0>(Pixels);
    float y = get<1>(Pixels);
    /*floor.setOrigin(floor.getSize().x/2,floor.getSize().y/2);*/
    floor.setPosition(x,y);
    window->draw(floor);
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
    if (link->getInteracted()) {
        return;
    }
    auto Position = link->getPosition();
    auto Pixels = camera.worldCoToPixelsCo(Position,0);
    float x = get<0>(Pixels);
    float y = get<1>(Pixels);
    /*sprite.setOrigin(link->entity_width()/2,link->entity_height()/2);*/
    sprite.setPosition(x-23,y-15);
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
    /*sprite.setOrigin(link->entity_width()/2,link->entity_height()/2);*/
    sprite.setPosition(x+15,y+15);
    window->draw(sprite);
}
void GhostRender::setSprite(const string &spritesheet) {
    spridesheet = spritesheet;
    if (!texture.loadFromFile(spritesheet)) {
        throw runtime_error("Failed to load texture: " + spritesheet);
    }
    float characterX = texture.getSize().x/19.0;
    float characterY = texture.getSize().y/19.0;
    xChar = characterX;
    yChar = characterY;
    char ghost = link->getSymbol();
    switch (ghost) {
        case 'r':
            x = 0;
            y = 6;
            break;
        case 'p':
            x = 1;
            y = 6;
            break;
        case 'b':
            x = 2;
            y = 6;
            break;
        case 'o':
            x = 3;
            y = 6;
            break;
    }
    /*sprite.setOrigin(xChar/2.0f,yChar/2.0f);*/
    currentImage = sf::IntRect(characterX*x,characterY*y,characterX,characterY);
    sprite.setTexture(texture);
    sprite.setTextureRect(currentImage);
    sprite.scale(1.8,1.8);
}
void GhostRender::render(sf::RenderWindow *window) {
    if (link->getInteracted()) {
        return;
    }
    auto Position = link->getPosition();
    auto Pixels = camera.worldCoToPixelsCo(Position,0);
    float x = get<0>(Pixels);
    float y = get<1>(Pixels);
    sprite.setPosition(x+12,y);
    window->draw(sprite);
}
void GhostRender::update(const Event& event) {
    if (link->getFearmode()==true) {
        if (event.type==WhichEvent::FearMode) {
            int pos = 0;
            x = 0;
            y = 11;
            /*count2+=Stopwatch::getInstance().tick();
            if (count2 >= switchMouth2) {
                switch (cycle2) {
                    case 0:
                        y = pos+1;
                        cycle2++;
                        break;
                    case 1:
                        y = pos;
                        cycle2 = 0;
                        break;
                }
                count2 = 0.0f;
            }*/
            currentImage = sf::IntRect(xChar*x,yChar*y,xChar,yChar);
            sprite.setTextureRect(currentImage);
        }
    }
    else {
        if (event.type==WhichEvent::Moved) {
            if (link->getFearmode()==true) {
                int pos = 0;
                x = 0;
                y = 11;
                /*count2+=Stopwatch::getInstance().tick();
                if (count2 >= switchMouth2) {
                    switch (cycle2) {
                        case 0:
                            y = pos+1;
                            cycle2++;
                            break;
                        case 1:
                            y = pos;
                            cycle2 = 0;
                            break;
                    }
                    count2 = 0.0f;
                }*/
                currentImage = sf::IntRect(xChar*x,yChar*y,xChar,yChar);
                sprite.setTextureRect(currentImage);
            }
            else {
                char direction = link->getcurrentDirection();
                char ghost = link->getSymbol();
                switch (ghost) {
                    case 'r':
                        x = 0;
                        break;
                    case 'p':
                        x = 1;
                        break;
                    case 'b':
                        x = 2;
                        break;
                    case 'o':
                        x = 3;
                        break;
                }
                int pos = 0;
                switch (direction) {
                    case 'u':
                        pos = 6;
                        break;
                    case 'd':
                        pos = 2;
                        break;
                    case 'l':
                        pos = 4;
                        break;
                    case 'r':
                        pos = 0;
                        break;
                }
                count+=Stopwatch::getInstance().tick();
                if (count >= switchMouth) {
                    switch (cycle) {
                        case 0:
                            y = pos+1;
                            cycle++;
                            break;
                        case 1:
                            y = pos;
                            cycle = 0;
                            break;
                    }
                    count = 0.0f;
                }
                currentImage = sf::IntRect(xChar*x,yChar*y,xChar,yChar);
                sprite.setTextureRect(currentImage);
            }
        }
    }
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
/*auto worldPos = link->getPosition();
    auto [pixelX,pixelY] = camera.worldCoToPixelsCo(worldPos,100);
    float halfSize = 50.0f;
    sprite.setPosition(pixelX-halfSize-15,pixelY-halfSize+5);
    window->draw(sprite);*/





