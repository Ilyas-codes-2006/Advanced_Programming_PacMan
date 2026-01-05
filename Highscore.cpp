//
// Created by Youssef on 31/12/2025.
//

#include "Highscore.h"

#include <algorithm>
#include <fstream>
#include <iostream>

/**
 * @Functionality We read all the highscores of the game from a .txt file.
 *
 * @Explanation AI advised me to use greater<>{} as its a great way to sort something from big to small in one line.
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
 * @Functionality Change the highscore or not.
 *
 * @Explanation This function gets called when the game ends and it directly checks if the new score is high enough to be in the top 5.
 * If so we delete the one who is now basically the 6th highest score.
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
 * @Functionality The Highscore stats get updated.
 *
 * @Explanation The .txt file gets updated with the newhighscores vector.
 */
void Highscore::changeFile(vector<int> newHighScores) {
    ofstream filename(highscores);
    for (auto score: newHighScores) {
        filename << score << "\n";
    }
    filename.close();
}



