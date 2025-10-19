//
// Created by Youssef on 19/10/2025.
//

#ifndef ADVANCEDPROGRAMMING_PACMAN_STATE_H
#define ADVANCEDPROGRAMMING_PACMAN_STATE_H

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
class State {
protected:
    sf::RenderWindow* window;
public:
    explicit State(sf::RenderWindow *window)
        : window(window) {
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
    MenuState(sf::RenderWindow* window);
    void Input(sf::Event *event) override;
    void update() override;
    void render() override;
};


#endif //ADVANCEDPROGRAMMING_PACMAN_STATE_H