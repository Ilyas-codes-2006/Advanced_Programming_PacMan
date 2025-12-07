//
// Created by Youssef on 22/11/2025.
//

#include "Mapreader.h"

vector<tuple<float, float, char>> Mapreader::readMap(Camera camera) const {
    ifstream input(filename);
    if (!input.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return {};
    }
    vector<tuple<float,float,char>> level;
    string line;
    int x = 0;
    int y = 0;
    vector<string> levelCount;
    while (getline(input,line)) {
        levelCount.push_back(line);
        x = line.size();
        y++;
    }
    for (int j = 0; j < y; j++) {
        for (int i = 0; i < x; i++) {
            auto coord = make_tuple(i*100,j*100);
            auto NormCoord = camera.PixelCoToWorldCo(coord);
            level.push_back({get<0>(NormCoord),get<1>(NormCoord),levelCount[j][i]});
        }
    }
    return level;
}
