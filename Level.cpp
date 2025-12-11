//
// Created by Youssef on 23/11/2025.
//

#include "Level.h"

#include "Mapreader.h"

Level::Level(const string &filename,Camera camera) {
    Mapreader read(filename);
    levelmapping = read.readMap(camera);
    entityWidth = 2.0f/read.xs1();
    entityHeight = 2.0f/read.ys1();
}
