//
// Created by Youssef on 19/10/2025.
//

#ifndef ADVANCEDPROGRAMMING_PACMAN_STATE_H
#define ADVANCEDPROGRAMMING_PACMAN_STATE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

#include "ConcreteFactory.h"
#include "Highscore.h"
#include "Score.h"
#include "World.h"
class EntityView;
using namespace std;
class StateManager;
class Game;
class State {
protected:
    sf::RenderWindow* window;
    StateManager* stateManager;
    Highscore highscore;
public:
    State(sf::RenderWindow *window, StateManager *stateManager)
        : window(window),
          stateManager(stateManager) {
    }

    virtual void Input(sf::Event* event) = 0;
    virtual void update() = 0;
    virtual void render() = 0;
};
class MenuState: public State {
private:
    sf::Text titleText;
    sf::RectangleShape playButton;
    sf::Text playButtonText;
    sf::Text highScores;
    sf::Font font;
public:
    MenuState(sf::RenderWindow *window, StateManager *stateManager);
    void Input(sf::Event *event) override;
    void update() override;
    void render() override;
};
class LevelState: public State {
private:
    sf::Text scoreTxt;
    sf::Text lives;
    sf::Font font;
    shared_ptr<ConcreteFactory> factory;
    shared_ptr<World> world;
    Camera camera;
    shared_ptr<Score> score;
    vector<shared_ptr<EntityView>> views;
public:
    LevelState(sf::RenderWindow *window, StateManager *stateManager);
    [[nodiscard]] vector<shared_ptr<EntityView>> getViews() const {
        return views;
    }
    void Input(sf::Event *event) override;
    void update() override;
    void render() override;
};
class PausedState: public State {
private:
    sf::Text paused;
    sf::Text resume;
    sf::Text QuitGame;
    sf::Text ExitToDesktop;
    sf::Font font;
public:
    PausedState(sf::RenderWindow *window, StateManager *stateManager);
    void Input(sf::Event *event) override;
    void update() override;
    void render() override;
};


#endif //ADVANCEDPROGRAMMING_PACMAN_STATE_H