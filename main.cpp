#include <iostream>
using namespace std;

#include <SFML/Graphics.hpp>
#include "Mapreader.h"
#include "Game.h"
int main() {
    Mapreader reader("../levelTest.txt");
    auto level = reader.readMap();
    sf::RenderWindow window(sf::VideoMode(2500, 1300), "PacMan");
    Game game = Game(&window);
    game.update();
    return 0;
}