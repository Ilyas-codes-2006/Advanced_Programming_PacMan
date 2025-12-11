//
// Created by Youssef on 22/11/2025.
//

#ifndef ADVANCEDPROGRAMMING_PACMAN_MAPREADER_H
#define ADVANCEDPROGRAMMING_PACMAN_MAPREADER_H
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
#include "Camera.h"

class Mapreader {
private:
    string filename;
    int xs;
    int ys;
public:
    explicit Mapreader(const string &filename)
        : filename(filename) {
    }

    [[nodiscard]] int xs1() const {
        return xs;
    }

    void set_xs(int xs) {
        this->xs = xs;
    }

    [[nodiscard]] int ys1() const {
        return ys;
    }

    void set_ys(int ys) {
        this->ys = ys;
    }

    vector<tuple<float,float,char>> readMap(Camera camera);
};


#endif //ADVANCEDPROGRAMMING_PACMAN_MAPREADER_H