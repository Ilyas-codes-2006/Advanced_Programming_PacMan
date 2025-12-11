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
    float width = float(x)-1;
    float height = float(y)-1;
    for (int j = 0; j < y; j++) {
        float coordy = 1-2*(float(j)/height);
        for (int i = 0; i < x; i++) {
            float coordx = -1+2*(float(i)/width);
            level.push_back({coordx,coordy,levelCount[j][i]});
        }
    }
    return level;
}
