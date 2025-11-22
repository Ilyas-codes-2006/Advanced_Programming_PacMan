//
// Created by Youssef on 22/11/2025.
//

#ifndef ADVANCEDPROGRAMMING_PACMAN_OBSERVER_H
#define ADVANCEDPROGRAMMING_PACMAN_OBSERVER_H


class Observer {
public:
    virtual void update() = 0;
    virtual ~Observer() = default;
};


#endif //ADVANCEDPROGRAMMING_PACMAN_OBSERVER_H