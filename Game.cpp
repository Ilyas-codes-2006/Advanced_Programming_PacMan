//
// Created by Youssef on 18/10/2025.
//

#include "Game.h"
#include <iostream>
using namespace std;
/**
 * @Functionality Pacman eats coin
 *
 * @Explanation We use the same system as for walls only now the hitboxes are much smaller
 * so it only triggers when we are almost in the middle. We also make use of an event here.
 * To tell our view that the coin needs to disappear. The coin itself gets deleted from
 * eatenEntities and also all the entities.
 */
Game::Game(sf::RenderWindow* window) {
    this->window = window;
}
/**
 * @Functionality Pacman eats coin
 *
 * @Explanation We use the same system as for walls only now the hitboxes are much smaller
 * so it only triggers when we are almost in the middle. We also make use of an event here.
 * To tell our view that the coin needs to disappear. The coin itself gets deleted from
 * eatenEntities and also all the entities.
 */
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
        window->clear(sf::Color(0,0,180));
        stateManager.whichRender();
        window->display();
    }
}
