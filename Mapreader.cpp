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
        for (int i = 0; i < x; i++) {
            level.push_back({i,j,levelCount[j][i]});
        }
    }
    string test = "To see if its right";
    return level;
}
