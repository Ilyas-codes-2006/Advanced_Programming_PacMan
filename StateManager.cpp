//
// Created by Youssef on 18/10/2025.
//

#include "StateManager.h"
/**
 * @Functionality Push the state.
 *
 * @Explanation /
 */
void StateManager::push(unique_ptr<State> state) {
    states.push(move(state));
}
/**
 * @Functionality Pop a state.
 *
 * @Explanation /
 */
void StateManager::pop() {
    if (!states.empty()) {
        states.pop();
    }
}
/**
 * @Functionality Get the top state.
 *
 * @Explanation We check which state is at the top and we check the correct implementation.
 */
void StateManager::whichInput(sf::Event *event) {
    if (!states.empty()) {
        states.top()->Input(event);
    }
}
/**
 * @Functionality Get the top state.
 *
 * @Explanation We check which state is at the top and we check the correct implementation.
 */
void StateManager::whichUpdate() {
    if (!states.empty()) {
        states.top()->update();
    }
}
/**
 * @Functionality Get the top state.
 *
 * @Explanation We check which state is at the top and we check the correct implementation.
 */
void StateManager::whichRender() {
    if (!states.empty()) {
        states.top()->render();
    }
}




