//
// Created by Youssef on 18/10/2025.
//

#ifndef ADVANCEDPROGRAMMING_PACMAN_GAME_H
#define ADVANCEDPROGRAMMING_PACMAN_GAME_H

#include "State.h"
#include "ConcreteFactory.h"
#include "World.h"
#include "Level.h"
#include "Camera.h"
#include "EntityView.h"
#include "StateManager.h"
#include <SFML/Graphics.hpp>
class Game {
private:
    sf::RenderWindow* window;
    StateManager stateManager;
public:
    Game(sf::RenderWindow* window);
    void update();

};


#endif //ADVANCEDPROGRAMMING_PACMAN_GAME_H