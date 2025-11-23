#include <iostream>
using namespace std;

#include <SFML/Graphics.hpp>
#include "Mapreader.h"
#include "Game.h"
int main() {
    Mapreader reader("../levelTest.txt");
    auto level = reader.readMap();
    sf::RenderWindow window(sf::VideoMode(600, 400), "PacMan");
    Game game = Game(&window);
    game.update();
    return 0;
}