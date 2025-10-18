//
// Created by Youssef on 18/10/2025.
//

#ifndef ADVANCEDPROGRAMMING_PACMAN_GAME_H
#define ADVANCEDPROGRAMMING_PACMAN_GAME_H


#include <SFML/Graphics.hpp>

class Game {
private:
    sf::RenderWindow* window;
public:
    Game(sf::RenderWindow* window);
    void update();

};


#endif //ADVANCEDPROGRAMMING_PACMAN_GAME_H