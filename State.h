//
// Created by Youssef on 19/10/2025.
//

#ifndef ADVANCEDPROGRAMMING_PACMAN_STATE_H
#define ADVANCEDPROGRAMMING_PACMAN_STATE_H

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
class StateManager;
class State {
protected:
    sf::RenderWindow* window;
    StateManager* stateManager;
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
    sf::Text titleText;
    sf::Font font;
public:
    LevelState(sf::RenderWindow *window, StateManager *stateManager);
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