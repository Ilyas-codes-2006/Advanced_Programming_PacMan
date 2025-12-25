//
// Created by Youssef on 19/10/2025.
//

#include "State.h"

#include "Game.h"
#include "StateManager.h"

MenuState::MenuState(sf::RenderWindow *window,StateManager *stateManager) : State(window,stateManager){
    if (!font.loadFromFile("C:/Users/Youssef/Advanced_Programming_PacMan/UF15XRU Arial.ttf")){
        cout << "Error loading font!" << endl;
    }

    titleText.setFont(font);
    titleText.setString("PAC-MAN");
    titleText.setCharacterSize(60);
    titleText.setFillColor(sf::Color(255, 255, 0));
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
            stateManager->push(make_unique<LevelState>(window,stateManager));
        }
    }
}
void MenuState::update() {
    playButton.setFillColor(sf::Color(255, 255, 0));
}
void MenuState::render() {
    window->draw(titleText);
    window->draw(playButton);
    window->draw(playButtonText);
    window->draw(highScores);
}
LevelState::LevelState(sf::RenderWindow *window,StateManager *stateManager) : State(window,stateManager), camera(window->getSize().x,window->getSize().y) {
    if (!font.loadFromFile("C:/Users/Youssef/Advanced_Programming_PacMan/UF15XRU Arial.ttf")){
        cout << "Error loading font!" << endl;
    }
    scoreTxt.setFont(font);
    scoreTxt.setString("Score: 0");
    scoreTxt.setCharacterSize(50);
    scoreTxt.setFillColor(sf::Color(255, 255, 0));
    scoreTxt.setPosition(100,window->getSize().y-80);
    lives.setFont(font);
    lives.setString("Lives Remaining: 3");
    lives.setCharacterSize(50);
    lives.setFillColor(sf::Color(255, 255, 0));
    lives.setPosition(window->getSize().x/2+500,window->getSize().y-80);
    score = make_shared<Score>();
    factory = make_shared<ConcreteFactory>();
    world = make_shared<World>(factory);
    auto level = make_shared<Level>("../levelTest.txt",camera);
    world->addLevel(level);
    world->makeLevel(world->getCurrentLevel());
    for (auto& entity : world->getEntities()) {
        char symbol = entity->getSymbol();
        if (symbol == '#') {
            views.push_back(factory->WallView(entity, camera));
        }
        else if (symbol == '_') {
            views.push_back(factory->FloorView(entity, camera));
        }
    }
    for (auto& entity : world->getEntities()) {
        char symbol = entity->getSymbol();
        if (symbol == 'F') {
            entity->attach(score.get());
            auto FruitView = factory->FruitView(entity,camera);
            FruitView->setSprite("../PacMan.png");
            views.push_back(FruitView);
        }
        else if (symbol == '-') {
            entity->attach(score.get());
            auto CoinView = factory->CoinView(entity,camera);
            CoinView->setSprite("../PacMan.png");
            views.push_back(CoinView);
        }

    }
    auto pacView = factory->PacManView(world->getPacman(), camera);
    pacView->setSprite("../PacMan.png");
    views.push_back(pacView);
    for (auto& entity : world->getEntities()) {
        char symbol = entity->getSymbol();
        if (symbol == 'r') {
            entity->attach(score.get());
            auto Ghostview = factory->GhostView(entity,camera);
            Ghostview->setSprite("../PacMan.png");
            views.push_back(Ghostview);
        }
        else if (symbol == 'p') {
            entity->attach(score.get());
            auto Ghostview = factory->GhostView(entity,camera);
            Ghostview->setSprite("../PacMan.png");
            views.push_back(Ghostview);
        }
        else if (symbol == 'b') {
            entity->attach(score.get());
            auto Ghostview = factory->GhostView(entity,camera);
            Ghostview->setSprite("../PacMan.png");
            views.push_back(Ghostview);
        }
        else if (symbol == 'o') {
            entity->attach(score.get());
            auto Ghostview = factory->GhostView(entity,camera);
            Ghostview->setSprite("../PacMan.png");
            views.push_back(Ghostview);
        }
    }
}

void LevelState::Input(sf::Event *event) {
    if (event->type == sf::Event::KeyPressed) {
        if (event->key.code == sf::Keyboard::Escape) {
            stateManager->push(make_unique<PausedState>(window,stateManager));
        }
        if (event->key.code == sf::Keyboard::Up) {
            world->getPacman()->setnextDirection('u');
        }
        if (event->key.code == sf::Keyboard::Down) {
            world->getPacman()->setnextDirection('d');
        }
        if (event->key.code == sf::Keyboard::Left) {
            world->getPacman()->setnextDirection('l');
        }
        if (event->key.code == sf::Keyboard::Right) {
            world->getPacman()->setnextDirection('r');
        }
    }
}
void LevelState::update() {
    float deltatime = Stopwatch::getInstance().tick();
    world->updatePacman(deltatime);
    /*world->getPacman()->update(deltatime);*/
    /*world->checkCollision();*/
    world->GhostMovement(deltatime);
    world->checkEatenFruit();
    world->checkEaten();
    world->CheckGhost();
    scoreTxt.setString("Score: " + std::to_string(score->getScore()));
}
void LevelState::render() {
    window->clear();
    for (auto& view : views) {
        view->render(window);
    }
    window->draw(lives);
    window->draw(scoreTxt);
}
PausedState::PausedState(sf::RenderWindow* window,StateManager *stateManager) : State(window,stateManager) {
    if (!font.loadFromFile("C:/Users/Youssef/Advanced_Programming_PacMan/UF15XRU Arial.ttf")) {
        cout << "Error loading font!" << endl;
    }

    paused.setFont(font);
    paused.setString("PAUSED");
    paused.setCharacterSize(60);
    paused.setFillColor(sf::Color(255, 255, 0));
    paused.setPosition(180, 50);

    resume.setFont(font);
    resume.setString("Resume");
    resume.setCharacterSize(30);
    resume.setFillColor(sf::Color::White);
    resume.setPosition(180, 150);

    QuitGame.setFont(font);
    QuitGame.setString("Quit Game");
    QuitGame.setCharacterSize(30);
    QuitGame.setFillColor(sf::Color::White);
    QuitGame.setPosition(180, 220);

    ExitToDesktop.setFont(font);
    ExitToDesktop.setString("Exit to Desktop");
    ExitToDesktop.setCharacterSize(30);
    ExitToDesktop.setFillColor(sf::Color::White);
    ExitToDesktop.setPosition(180, 290);
}

void PausedState::Input(sf::Event *event) {
    if (event->type == sf::Event::KeyPressed) {
        if (event->key.code == sf::Keyboard::Escape) {
            stateManager->pop();
        }
    }
    if (event->type == sf::Event::MouseButtonPressed) {
        sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
        if (resume.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
            stateManager->pop();
        }
        if (QuitGame.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
            stateManager->pop();
            stateManager->pop();
        }
        if (ExitToDesktop.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
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
