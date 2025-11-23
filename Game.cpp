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
    auto concreteFactory = make_shared<ConcreteFactory>();
    World world(concreteFactory);
    auto level = make_shared<Level>("../levelTest.txt");
    world.makeLevel(level);
    /*for (auto& entity : world.getEntities()) {
        auto pos = entity->getPosition();
        cout << "Entity at (" << get<0>(pos) << ", " << get<1>(pos) << ")" << entity->getSymbol() <<  endl;
    }*/
    Camera camera(window->getSize().x,window->getSize().y);
    vector<shared_ptr<EntityView>> views;
    for (auto& entity : world.getEntities()) {
        char symbol = entity->getSymbol();
        if (symbol == 'P') {
            views.push_back(concreteFactory->FloorView(entity, camera));
            auto pacView = concreteFactory->PacManView(entity, camera);
            pacView->setSprite("../PacMan.png",17,1);
            views.push_back(pacView);
        }
        else if (symbol == '#') {
            views.push_back(concreteFactory->WallView(entity, camera));
        }
        else if (symbol == ' ') {
            views.push_back(concreteFactory->FloorView(entity, camera));
        }
    }
    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
            }
        }

        window->clear(sf::Color::White);

        for (auto& view : views) {
            view->render(window);
        }

        window->display();
    }

    /*stateManager.push(make_unique<MenuState>(window,&stateManager));
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
    }*/
}
