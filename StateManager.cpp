//
// Created by Youssef on 18/10/2025.
//

#include "StateManager.h"
void StateManager::push(unique_ptr<State> state) {
    states.push(move(state));
}
void StateManager::pop() {
    if (!states.empty()) {
        states.pop();
    }
}
void StateManager::whichInput(sf::Event *event) {
    if (!states.empty()) {
        states.top()->Input(event);
    }
}
void StateManager::whichUpdate() {
    if (!states.empty()) {
        states.top()->update();
    }
}
void StateManager::whichRender() {
    if (!states.empty()) {
        states.top()->render();
    }
}




