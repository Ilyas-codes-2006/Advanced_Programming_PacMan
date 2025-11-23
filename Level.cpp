//
// Created by Youssef on 23/11/2025.
//

#include "Level.h"

#include "Mapreader.h"

Level::Level(const string &filename) {
    Mapreader read(filename);
    levelmapping = read.readMap();
}
