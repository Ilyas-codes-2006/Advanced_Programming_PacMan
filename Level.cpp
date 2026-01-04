//
// Created by Youssef on 23/11/2025.
//

#include "Level.h"

#include "Mapreader.h"
/**
 * @Functionality Pacman eats coin
 *
 * @Explanation We use the same system as for walls only now the hitboxes are much smaller
 * so it only triggers when we are almost in the middle. We also make use of an event here.
 * To tell our view that the coin needs to disappear. The coin itself gets deleted from
 * eatenEntities and also all the entities.
 */
Level::Level(const string &filename,Camera camera) {
    Mapreader read(filename);
    levelmapping = read.readMap(camera);
    entityWidth = 2.0f/read.xs1();
    entityHeight = 2.0f/read.ys1();
}
