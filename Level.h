//
// Created by Youssef on 23/11/2025.
//

#ifndef ADVANCEDPROGRAMMING_PACMAN_LEVEL_H
#define ADVANCEDPROGRAMMING_PACMAN_LEVEL_H

#include <vector>
#include <string>
using namespace std;
#include "Camera.h"
class Level {
private:
    vector<tuple<float,float,char>> levelmapping;
    float entityWidth;
    float entityHeight;
public:
    [[nodiscard]] float entity_width() const {
        return entityWidth;
    }

    void set_entity_width(float entity_width) {
        entityWidth = entity_width;
    }

    [[nodiscard]] float entity_height() const {
        return entityHeight;
    }

    void set_entity_height(float entity_height) {
        entityHeight = entity_height;
    }

    explicit Level(const string& filename,Camera camera);

    [[nodiscard]] vector<tuple<float, float, char>> getLevelMapping() const {
        return levelmapping;
    }
};


#endif //ADVANCEDPROGRAMMING_PACMAN_LEVEL_H