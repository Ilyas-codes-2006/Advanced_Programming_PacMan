//
// Created by Youssef on 14/11/2025.
//

#include "Camera.h"
tuple<float, float> Camera::worldCoToPixelsCo(const tuple<float, float> &worldCo) const {
    float worldX = get<0>(worldCo);
    float worldY = get<1>(worldCo);
    float PixelX = (worldX + 1.0f)/2.0f * width;
    float PixelY = (1.0f - (worldY + 1.0f)/2.0f)*height;
    return {PixelX,PixelY};
}
tuple<float, float> Camera::PixelCoToWorldCo(const tuple<float, float> &pixelCo) const {
    float PixelX = get<0>(pixelCo);
    float PixelY = get<1>(pixelCo);
    float worldX = PixelX/width * 2.0f -1.0f;
    float worldY = (1.0f - PixelY/height)* 2.0f -1.0f;
    return {worldX,worldY};
}

