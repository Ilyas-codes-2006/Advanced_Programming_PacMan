//
// Created by Youssef on 18/10/2025.
//

#ifndef ADVANCEDPROGRAMMING_PACMAN_STATEMANAGER_H
#define ADVANCEDPROGRAMMING_PACMAN_STATEMANAGER_H

#include <vector>
#include <memory>
#include <stack>
#include "State.h"
#include <utility>
#include <SFML/Graphics.hpp>
using namespace std;
class StateManager {
private:
    stack<unique_ptr<State>> states;
public:
    void push(unique_ptr<State> state);
    void pop();
    void whichInput(sf::Event *event);
    void whichUpdate();
    void whichRender();
};


#endif //ADVANCEDPROGRAMMING_PACMAN_STATEMANAGER_H