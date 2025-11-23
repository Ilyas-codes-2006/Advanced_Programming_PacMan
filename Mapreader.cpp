//
// Created by Youssef on 22/11/2025.
//

#include "Mapreader.h"

vector<tuple<float, float, char> > Mapreader::readMap() const {
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
        int invertedY = y - 1 - j;
        for (int i = 0; i < x; i++) {
            float coordX = -1.0f + 2.0f*(i + 0.5f)/x;
            float coordY = -1.0f + 2.0f*(invertedY + 0.5f)/y;
            level.push_back({coordX,coordY,levelCount[j][i]});
        }
    }
    return level;
}
