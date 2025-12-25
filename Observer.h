//
// Created by Youssef on 22/11/2025.
//

#ifndef ADVANCEDPROGRAMMING_PACMAN_OBSERVER_H
#define ADVANCEDPROGRAMMING_PACMAN_OBSERVER_H
#include <memory>


class EntityModel;

enum class WhichEvent {
    Moved,
    CoinPoint,
    CoinEaten,
    FruitGone,
    FearMode,
    DirectionSwitch,
};
struct Event {
    WhichEvent type;
    EntityModel* entity;
};
class Observer {
public:
    virtual void update(const Event& event) = 0;
    virtual ~Observer() = default;
};


#endif //ADVANCEDPROGRAMMING_PACMAN_OBSERVER_H