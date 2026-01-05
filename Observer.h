//
// Created by Youssef on 22/11/2025.
//

#ifndef ADVANCEDPROGRAMMING_PACMAN_OBSERVER_H
#define ADVANCEDPROGRAMMING_PACMAN_OBSERVER_H
#include <memory>


class EntityModel;

/**
* @Functionality The logic of an event.
*
* @Explanation THe enum class WhichEvent works together with the struct Event. AN event is defined by its description.
* A.k.a. the Whichevent type. We also need to know which entity caused this event so we also return a raw pointer to the correct
* entity.
*/
enum class WhichEvent {
    Moved,
    CoinPoint,
    CoinEaten,
    FruitGone,
    FearMode,
    DirectionSwitch,
    GhostEaten,
    LevelCleared,
    NotEaten,
    ResetGhost,
    changeGhost
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