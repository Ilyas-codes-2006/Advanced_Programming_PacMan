//
// Created by Youssef on 31/12/2025.
//

#ifndef ADVANCEDPROGRAMMING_PACMAN_HIGHSCORE_H
#define ADVANCEDPROGRAMMING_PACMAN_HIGHSCORE_H
#include <string>
#include <vector>

using namespace std;

class Highscore {
private:
    string highscores = "C:/Users/Youssef/Advanced_Programming_PacMan/Highscores.txt";
    vector<int> highscoresVector;
public:
    Highscore();
    void change(int highscore);
    void changeFile(vector<int> newHighScores);

    [[nodiscard]] vector<int> getHighscores() const {
        return highscoresVector;
    }
};


#endif //ADVANCEDPROGRAMMING_PACMAN_HIGHSCORE_H