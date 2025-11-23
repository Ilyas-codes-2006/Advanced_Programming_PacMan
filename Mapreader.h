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

class Mapreader {
private:
    string filename;
    int width = 0;
    int height = 0;
public:
    explicit Mapreader(const string &filename)
        : filename(filename) {
    }

    [[nodiscard]] int getWidth() const {
        return width;
    }

    [[nodiscard]] int getHeight() const {
        return height;
    }

    vector<tuple<float,float,char>> readMap() const;
};


#endif //ADVANCEDPROGRAMMING_PACMAN_MAPREADER_H