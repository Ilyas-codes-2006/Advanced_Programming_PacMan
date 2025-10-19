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
    MenuState menu(window);
    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
            }
            menu.Input(&event);
        }
        menu.update();
        window->clear(sf::Color::Blue);
        menu.render();
        window->display();
    }
}
