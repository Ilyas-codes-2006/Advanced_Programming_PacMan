//
// Created by Youssef on 13/11/2025.
//

#include "EntityView.h"

#include "EntityModel.h"
/**
 * @Functionality We take the right sprite for Pacman in the beginning of the game.
 *
 * @Explanation /
 */
void PacManRender::setSprite(const string &spritesheet) {
    spridesheet = spritesheet;
    if (!texture.loadFromFile(spritesheet)) {
        throw runtime_error("Failed to load texture: " + spritesheet);
    }
    //the spritesheet is a 19x19 with 19 sprites per line so if divide it with 19 we get the correct size of 1 sprite
    //with that we can find the correct sprite with x and y who are the column and row!
    float characterX = texture.getSize().x/19.0;
    float characterY = texture.getSize().y/19.0;
    xChar = characterX;
    yChar = characterY;
    currentImage = sf::IntRect(characterX*x,characterY*y,characterX,characterY);
    sprite.setTexture(texture);
    sprite.setTextureRect(currentImage);
    sprite.scale(2,2);
}
/**
 * @Functionality We render Pacman on the screen
 *
 * @Explanation We change the coord of the entity to pixels and we set the right position on the window
 */
void PacManRender::render(sf::RenderWindow *window) {
    auto Position = link->getPosition();
    auto Pixels = camera.worldCoToPixelsCo(Position,0);
    float x = get<0>(Pixels);
    float y = get<1>(Pixels);
    sprite.setPosition(x-16,y+3);
    window->draw(sprite);
}
/**
 * @Functionality We check the direction of pacman and based on that we give the right sprites.
 *
 * @Explanation In this function the mouth needs to close and open while moving. I did discuss how to do this with chatGPT and he
 * advised me to make use of a cycle that loops through the three sprites. You cqn also see the use of Event only if the even type is
 * move we move and cycle the sprite but when were not moving it doesnt cycle.
 */
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
}
/**
 * @Functionality We render wall on the screen
 *
 * @Explanation We change the coord of the entity to pixels and we set the right position on the window
 */
void WallRender::render(sf::RenderWindow *window) {
    auto Position = link->getPosition();
    auto Pixels = camera.worldCoToPixelsCo(Position,0);
    float x = get<0>(Pixels);
    float y = get<1>(Pixels);
    /*wall.setOrigin(wall.getSize().x/2,wall.getSize().y/2);*/
    wall.setPosition(x,y);
    window->draw(wall);
}
/**
 * @Functionality We render the spawnpoint on the screen
 *
 * @Explanation We change the coord of the entity to pixels and we set the right position on the window
 */
void SpawnRender::render(sf::RenderWindow *window) {
    auto Position = link->getPosition();
    auto Pixels = camera.worldCoToPixelsCo(Position,0);
    float x = get<0>(Pixels);
    float y = get<1>(Pixels);
    /*floor.setOrigin(floor.getSize().x/2,floor.getSize().y/2);*/
    floor.setPosition(x,y);
    window->draw(floor);
}
/**
 * @Functionality We render floor on the screen
 *
 * @Explanation We change the coord of the entity to pixels and we set the right position on the window
 */
void FloorRender::render(sf::RenderWindow *window) {
    auto Position = link->getPosition();
    auto Pixels = camera.worldCoToPixelsCo(Position,0);
    float x = get<0>(Pixels);
    float y = get<1>(Pixels);
    /*floor.setOrigin(floor.getSize().x/2,floor.getSize().y/2);*/
    floor.setPosition(x,y);
    window->draw(floor);
}
/**
 * @Functionality We take the right sprite for the fruit in the beginning of the game.
 *
 * @Explanation /
 */
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
/**
 * @Functionality We render fruit on the screen
 *
 * @Explanation We change the coord of the entity to pixels and we set the right position on the window
 */
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
/**
 * @Functionality We take the right sprite for the coin in the beginning of the game.
 *
 * @Explanation /
 */
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
/**
 * @Functionality We render coin on the screen
 *
 * @Explanation We change the coord of the entity to pixels and we set the right position on the window
 */
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
/**
 * @Functionality We take the right sprite for the ghost in the beginning of the game.
 *
 * @Explanation /
 */
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
    currentImage = sf::IntRect(characterX*x,characterY*y,characterX,characterY);
    sprite.setTexture(texture);
    sprite.setTextureRect(currentImage);
    sprite.scale(1.8,1.8);
}
/**
 * @Functionality We render ghost on the screen
 *
 * @Explanation We change the coord of the entity to pixels and we set the right position on the window
 */
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
/**
 * @Functionality We check the direction of the ghost and based on that we give the right sprites.
 *
 * @Explanation The ghost uses multiple events to change the sprites. Namely the fear sprites and the normal sprites.
 * So when based on the event given in World the sprites changes. I wanted to use the same implementation for changing the sprites to seem like
 * they float but it doesn't work and due to ti,e restrictions I could not fix it. SO they move like a static sprite in the right direction.
 */
void GhostRender::update(const Event& event) {
    if (link->getFearmode()==true) {
        if (event.type==WhichEvent::FearMode) {
            x = 0;
            y = 11;
            currentImage = sf::IntRect(xChar*x,yChar*y,xChar,yChar);
            sprite.setTextureRect(currentImage);
        }
    }
    else {
        if (event.type==WhichEvent::Moved) {
            if (link->getFearmode()==true) {
                x = 0;
                y = 11;
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
                switch (direction) {
                    case 'u':
                        y = 6;
                        break;
                    case 'd':
                        y = 2;
                        break;
                    case 'l':
                        y = 4;
                        break;
                    case 'r':
                        y = 0;
                        break;
                }
                currentImage = sf::IntRect(xChar*x,yChar*y,xChar,yChar);
                sprite.setTextureRect(currentImage);
            }
        }
        else if (event.type==WhichEvent::changeGhost){
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
            switch (direction) {
                case 'u':
                    y = 6;
                    break;
                case 'd':
                    y = 2;
                    break;
                case 'l':
                    y = 4;
                    break;
                case 'r':
                    y = 0;
                    break;
            }
            currentImage = sf::IntRect(xChar*x,yChar*y,xChar,yChar);
            sprite.setTextureRect(currentImage);
        }
    }
}





