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
public:
    explicit Mapreader(const string &filename)
        : filename(filename) {
    }

    vector<tuple<float,float,char>> readMap(Camera camera) const;
};


#endif //ADVANCEDPROGRAMMING_PACMAN_MAPREADER_H