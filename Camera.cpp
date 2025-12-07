//
// Created by Youssef on 14/11/2025.
//

#include "Camera.h"

#include <cmath>

tuple<float, float> Camera::worldCoToPixelsCo(const tuple<float, float> &worldCo) const {
    float worldX = get<0>(worldCo);
    float worldY = get<1>(worldCo);
    float PixelX = round(((worldX+1)/2)*width);
    float PixelY = round(-((worldY-1)/2)*height);
    if (PixelX == -0){
        PixelX=0;
    }
    if (PixelY == -0){
        PixelY=0;
    }
    return {PixelX,PixelY};
}
tuple<float, float> Camera::PixelCoToWorldCo(const tuple<float, float> &pixelCo) const {
    float PixelX = get<0>(pixelCo);
    float PixelY = get<1>(pixelCo);
    float worldX = -1+(2*(PixelX/width));
    float worldY = 1-(2*(PixelY/height));
    return {worldX,worldY};
}

