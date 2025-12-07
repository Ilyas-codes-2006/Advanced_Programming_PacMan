#include <iostream>
using namespace std;

#include <SFML/Graphics.hpp>
#include "Mapreader.h"
#include "Game.h"
int main() {
    Camera camera(2000,1100);
    tuple<float,float> pixel = {1,-1};
    auto world = camera.worldCoToPixelsCo(pixel,100);
    Mapreader reader("../levelTest.txt");
    auto level = reader.readMap(camera);
    sf::RenderWindow window(sf::VideoMode(2000, 1100), "PacMan");
    Game game = Game(&window);
    game.update();
    return 0;
}