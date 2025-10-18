#include <iostream>
using namespace std;

#include <SFML/Graphics.hpp>
#include "Game.h"
int main() {
    sf::RenderWindow window(sf::VideoMode(600, 400), "PacMan");
    Game game = Game(&window);
    game.update();
    return 0;
}