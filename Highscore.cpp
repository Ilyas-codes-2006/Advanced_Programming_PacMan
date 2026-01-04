//
// Created by Youssef on 31/12/2025.
//

#include "Highscore.h"

#include <algorithm>
#include <fstream>
#include <iostream>

/**
 * @Functionality Pacman eats coin
 *
 * @Explanation We use the same system as for walls only now the hitboxes are much smaller
 * so it only triggers when we are almost in the middle. We also make use of an event here.
 * To tell our view that the coin needs to disappear. The coin itself gets deleted from
 * eatenEntities and also all the entities.
 */
Highscore::Highscore() {
    ifstream filename(highscores);
    if (!filename.is_open()) {
        cerr << "cant open file" << endl;
        return;
    }
    string line;
    vector<int> test;
    while (getline(filename,line)) {
        int score = stoi(line);
        test.push_back(score);
    }
    sort(test.begin(),test.end(), greater<>{});
    highscoresVector = test;
    filename.close();
}
/**
 * @Functionality Pacman eats coin
 *
 * @Explanation We use the same system as for walls only now the hitboxes are much smaller
 * so it only triggers when we are almost in the middle. We also make use of an event here.
 * To tell our view that the coin needs to disappear. The coin itself gets deleted from
 * eatenEntities and also all the entities.
 */
void Highscore::change(int highscore) {
    vector<int> backup;
    vector<int> newScore;
    bool add = false;
    int vectorlength = 4;
    for (auto score: highscoresVector) {
        if (score > highscore) {
            newScore.push_back(score);
            vectorlength--;
        }
        else if (highscore >= score) {
            add = true;
            backup.push_back(score);
        }
    }
    if (add) {
        newScore.push_back(highscore);
        sort(backup.begin(),backup.end(),greater<>{});
        for (int i = 0; i < vectorlength; i++) {
            newScore.push_back(backup[i]);
        }
        sort(newScore.begin(),newScore.end(),greater<>{});
        changeFile(newScore);
    }
}
/**
 * @Functionality Pacman eats coin
 *
 * @Explanation We use the same system as for walls only now the hitboxes are much smaller
 * so it only triggers when we are almost in the middle. We also make use of an event here.
 * To tell our view that the coin needs to disappear. The coin itself gets deleted from
 * eatenEntities and also all the entities.
 */
void Highscore::changeFile(vector<int> newHighScores) {
    ofstream filename(highscores);
    for (auto score: newHighScores) {
        filename << score << "\n";
    }
    filename.close();
}



