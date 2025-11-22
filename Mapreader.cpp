//
// Created by Youssef on 22/11/2025.
//

#include "Mapreader.h"

vector<tuple<int, int, char> > Mapreader::readMap() const {
    string debugFile = "levelTest.txt";
    ifstream input(debugFile);
    if (!input.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return {};
    }
    vector<tuple<int,int,char>> level;
    string line;
    while (getline(input,line)) {

    }
}
