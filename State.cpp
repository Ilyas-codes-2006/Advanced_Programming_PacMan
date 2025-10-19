//
// Created by Youssef on 19/10/2025.
//

#include "State.h"
MenuState::MenuState(sf::RenderWindow *window) : State(window){
    if (!font.loadFromFile("C:/Users/Youssef/Advanced_Programming_PacMan/UF15XRU Arial.ttf")){
        cout << "Error loading font!" << endl;
    }

    titleText.setFont(font);
    titleText.setString("PAC-MAN");
    titleText.setCharacterSize(60);
    titleText.setFillColor(sf::Color::Yellow);
    titleText.setPosition(160, 30);

    playButton.setSize(sf::Vector2f(200, 60));
    playButton.setFillColor(sf::Color::Blue);
    playButton.setPosition(200, 150);

    playButtonText.setFont(font);
    playButtonText.setString("PLAY");
    playButtonText.setCharacterSize(30);
    playButtonText.setFillColor(sf::Color::White);
    playButtonText.setPosition(
        playButton.getPosition().x + 50,
        playButton.getPosition().y + 15
    );

    highScores.setFont(font);
    highScores.setString("1. ---\n2. ---\n3. ---\n4. ---\n5. ---");
    highScores.setCharacterSize(25);
    highScores.setFillColor(sf::Color::White);
    highScores.setPosition(270, 225);
}

void MenuState::Input(sf::Event *event) {
    if (event->type == sf::Event::MouseButtonPressed) {
        sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
        if (playButton.getGlobalBounds().contains(static_cast<float>(mousePosition.x),static_cast<float>(mousePosition.y))) {
            cout << "Play Clicked" << endl;
        }
    }
}
void MenuState::update() {
    playButton.setFillColor(sf::Color::Yellow);
}
void MenuState::render() {
    window->draw(titleText);
    window->draw(playButton);
    window->draw(playButtonText);
    window->draw(highScores);
}

