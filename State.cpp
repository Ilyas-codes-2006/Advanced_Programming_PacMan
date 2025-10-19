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
LevelState::LevelState(sf::RenderWindow *window) : State(window){
    if (!font.loadFromFile("C:/Users/Youssef/Advanced_Programming_PacMan/UF15XRU Arial.ttf")){
        cout << "Error loading font!" << endl;
    }

    titleText.setFont(font);
    titleText.setString("GAME IS PLAYING");
    titleText.setCharacterSize(60);
    titleText.setFillColor(sf::Color::Yellow);
    titleText.setPosition(160, 30);
}

void LevelState::Input(sf::Event *event) {
    if (event->type == sf::Event::KeyPressed) {
        if (event->key.code == sf::Keyboard::Escape) {
            cout << "Escape pressed, game paused" << endl;
        }
    }
}
void LevelState::update() {
}
void LevelState::render() {
    window->draw(titleText);
}
PausedState::PausedState(sf::RenderWindow* window) : State(window) {
    if (!font.loadFromFile("C:/Users/Youssef/Advanced_Programming_PacMan/UF15XRU Arial.ttf")) {
        cout << "Error loading font!" << endl;
    }

    paused.setFont(font);
    paused.setString("PAUSED");
    paused.setCharacterSize(60);
    paused.setFillColor(sf::Color::White);
    paused.setPosition(180, 50);

    resume.setFont(font);
    resume.setString("RESUME");
    resume.setCharacterSize(30);
    resume.setFillColor(sf::Color::White);
    resume.setPosition(220, 150);

    QuitGame.setFont(font);
    QuitGame.setString("QUIT TO MENU");
    QuitGame.setCharacterSize(30);
    QuitGame.setFillColor(sf::Color::White);
    QuitGame.setPosition(180, 220);

    ExitToDesktop.setFont(font);
    ExitToDesktop.setString("EXIT");
    ExitToDesktop.setCharacterSize(30);
    ExitToDesktop.setFillColor(sf::Color::White);
    ExitToDesktop.setPosition(230, 290);
}

void PausedState::Input(sf::Event *event) {
    if (event->type == sf::Event::KeyPressed) {
        if (event->key.code == sf::Keyboard::Escape) {
            cout << "resume" << endl;
        }
    }
    if (event->type == sf::Event::MouseButtonPressed) {
        sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
        if (resume.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
            cout << "Resume" << endl;
        }
        if (QuitGame.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
            cout << "Menu" << endl;
        }
        if (ExitToDesktop.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
            cout << "Exit" << endl;
            window->close();
        }
    }
}
void PausedState::update() {
}
void PausedState::render() {
    window->draw(paused);
    window->draw(resume);
    window->draw(QuitGame);
    window->draw(ExitToDesktop);
}

