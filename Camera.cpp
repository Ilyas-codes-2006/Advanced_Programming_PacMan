//
// Created by Youssef on 14/11/2025.
//

#include "Camera.h"

#include <cmath>
/**
 * @Functionality From normalized coordinates to pixel coordinates.
 *
 * @Explanation /
 */
tuple<float, float> Camera::worldCoToPixelsCo(const tuple<float, float> &worldCo,int a) const {
    float worldX = get<0>(worldCo);
    float worldY = get<1>(worldCo);
    //I just did the reverse of the other calculation.
    float PixelX = round(((worldX+1)/2)*(width));
    float PixelY = round(-((worldY-1)/2)*(height));
    return {PixelX,PixelY};
}
/**
 * @Functionality From pixel coordinates to normalized coordinates.
 *
 * @Explanation /
 */
tuple<float, float> Camera::PixelCoToWorldCo(const tuple<float, float> &pixelCo,int a) const {
    float PixelX = get<0>(pixelCo);
    float PixelY = get<1>(pixelCo);
    //Calculation to set every type of coordinate to a normalized coordinate.
    float worldX = -1+(2*(PixelX/(width)));
    float worldY = 1-(2*(PixelY/(height)));
    return {worldX,worldY};
}

