//
// Created by Youssef on 13/11/2025.
//

#ifndef ADVANCEDPROGRAMMING_PACMAN_SUBJECT_H
#define ADVANCEDPROGRAMMING_PACMAN_SUBJECT_H
#include <vector>
#include <algorithm>
#include "Observer.h"

class Subject {
private:
    std::vector<Observer *> observers;
public:
    virtual ~Subject() = default;
    void attach(Observer * observer);
    void detach(Observer* observer);
    void notify();
};


#endif //ADVANCEDPROGRAMMING_PACMAN_SUBJECT_H