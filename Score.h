//
// Created by Youssef on 20/12/2025.
//

#ifndef ADVANCEDPROGRAMMING_PACMAN_SCORE_H
#define ADVANCEDPROGRAMMING_PACMAN_SCORE_H
#include "Observer.h"


class Score : public Observer{
private:
    int score = 0;
public:
    [[nodiscard]] int getScore() const {
        return score;
    }
    void update(const Event &event) override;
};


#endif //ADVANCEDPROGRAMMING_PACMAN_SCORE_H