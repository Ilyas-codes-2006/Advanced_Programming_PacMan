//
// Created by Youssef on 22/11/2025.
//

#include "Mapreader.h"
/**
 * @Functionality Pacman eats coin
 *
 * @Explanation We use the same system as for walls only now the hitboxes are much smaller
 * so it only triggers when we are almost in the middle. We also make use of an event here.
 * To tell our view that the coin needs to disappear. The coin itself gets deleted from
 * eatenEntities and also all the entities.
 */
vector<tuple<float, float, char>> Mapreader::readMap(Camera camera) {
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
    float width = float(x);
    float height = float(y);
    xs = x;
    ys = y;
    int gotit = 0;
    float tileWidth;
    float tileHeight;
    for (int j = 0; j < y; j++) {
        float coordy = 1-2*(float(j)/height);
        float coordy2 = 1-2*(float(j+1)/height);
        if (gotit==0) {
            for (int i = 0; i < x; i++) {
                float coordx = -1+2*(float(i)/width);
                float coordx2 = -1+2*(float(i+1)/width);
                auto tup2 = camera.worldCoToPixelsCo({coordx2,coordy2},0);
                auto tup1 = camera.worldCoToPixelsCo({coordx,coordy},0);
                tileWidth = get<0>(tup2)-get<0>(tup1);
                tileHeight = get<1>(tup2)-get<1>(tup1);
                level.push_back({coordx,coordy,levelCount[j][i]});
            }
            gotit = 1;
        }
        else {
            for (int i = 0; i < x; i++) {
                float coordx = -1+2*(float(i)/width);
                level.push_back({coordx,coordy,levelCount[j][i]});
            }
        }
    }
    tilewidth = tileWidth;
    tileheight = tileHeight;
    return level;
}