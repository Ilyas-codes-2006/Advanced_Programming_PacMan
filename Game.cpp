//
// Created by Youssef on 18/10/2025.
//

#include "Game.h"
#include <iostream>
using namespace std;

Game::Game(sf::RenderWindow* window) {
    this->window = window;
}
void Game::update() {
    stateManager.push(make_unique<MenuState>(window,&stateManager));
    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
            }
            stateManager.whichInput(&event);
        }
        stateManager.whichUpdate();
        window->clear(sf::Color::Blue);
        stateManager.whichRender();
        window->display();
    }
}
