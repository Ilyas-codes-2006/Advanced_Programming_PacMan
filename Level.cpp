//
// Created by Youssef on 23/11/2025.
//

#include "Level.h"

#include "Mapreader.h"
/**
 * @Functionality We make a level (character-wise).
 *
 * @Explanation We make use of the mapreader class who returns the .txt map into a vector.
 * The vector consists of a character and its corrdinates. We also store the width and height of one Entity in
 * normalized coordinates.
 */
Level::Level(const string &filename,Camera camera) {
    Mapreader read(filename);
    levelmapping = read.readMap(camera);
    entityWidth = 2.0f/read.xs1();
    entityHeight = 2.0f/read.ys1();
}
