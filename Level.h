//
// Created by Youssef on 23/11/2025.
//

#ifndef ADVANCEDPROGRAMMING_PACMAN_LEVEL_H
#define ADVANCEDPROGRAMMING_PACMAN_LEVEL_H

#include <vector>
#include <string>
using namespace std;

class Level {
private:
    vector<tuple<float,float,char>> levelmapping;
public:
    explicit Level(const string& filename);

    [[nodiscard]] vector<tuple<float, float, char>> getLevelMapping() const {
        return levelmapping;
    }
};


#endif //ADVANCEDPROGRAMMING_PACMAN_LEVEL_H