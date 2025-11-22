//
// Created by Youssef on 14/11/2025.
//

#ifndef ADVANCEDPROGRAMMING_PACMAN_CAMERA_H
#define ADVANCEDPROGRAMMING_PACMAN_CAMERA_H

#include <tuple>
using namespace std;
class Camera {
private:
    float width;
    float height;
public:
    Camera(float width, float height)
        : width(width),
          height(height) {
    }
    tuple<float,float> worldCoToPixelsCo(const tuple<float,float>& worldCo) const;
    tuple<float,float> PixelCoToWorldCo(const tuple<float,float>& pixelCo) const;
};


#endif //ADVANCEDPROGRAMMING_PACMAN_CAMERA_H