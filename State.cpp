//
// Created by Youssef on 19/10/2025.
//

#include "State.h"
#include "Game.h"
#include "StateManager.h"
#include "Highscore.h"

using namespace std;
/**
 * @Functionality Pacman eats coin
 *
 * @Explanation We use the same system as for walls only now the hitboxes are much smaller
 * so it only triggers when we are almost in the middle. We also make use of an event here.
 * To tell our view that the coin needs to disappear. The coin itself gets deleted from
 * eatenEntities and also all the entities.
 */
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
    highScores.setString("Top 1:   " + to_string(highscore.getHighscores()[0])+ "\nTop 2:   "+ to_string(highscore.getHighscores()[1])+"\nTop 3:   "+ to_string(highscore.getHighscores()[2])+"\nTop 4:   " + to_string(highscore.getHighscores()[3])+"\nTop 5:   " + to_string(highscore.getHighscores()[4]));
    highScores.setCharacterSize(25);
    highScores.setFillColor(sf::Color::Yellow);
    highScores.setPosition(270, 225);
}
/**
 * @Functionality Pacman eats coin
 *
 * @Explanation We use the same system as for walls only now the hitboxes are much smaller
 * so it only triggers when we are almost in the middle. We also make use of an event here.
 * To tell our view that the coin needs to disappear. The coin itself gets deleted from
 * eatenEntities and also all the entities.
 */
void MenuState::Input(sf::Event *event) {
    if (event->type == sf::Event::MouseButtonPressed) {
        sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
        if (playButton.getGlobalBounds().contains(static_cast<float>(mousePosition.x),static_cast<float>(mousePosition.y))) {
            stateManager->push(make_unique<LevelState>(window,stateManager));
        }
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
void MenuState::update() {
    playButton.setFillColor(sf::Color(255, 255, 0));
}
/**
 * @Functionality Pacman eats coin
 *
 * @Explanation We use the same system as for walls only now the hitboxes are much smaller
 * so it only triggers when we are almost in the middle. We also make use of an event here.
 * To tell our view that the coin needs to disappear. The coin itself gets deleted from
 * eatenEntities and also all the entities.
 */
void MenuState::render() {
    window->draw(titleText);
    window->draw(playButton);
    window->draw(playButtonText);
    window->draw(highScores);
}
/**
 * @Functionality Pacman eats coin
 *
 * @Explanation We use the same system as for walls only now the hitboxes are much smaller
 * so it only triggers when we are almost in the middle. We also make use of an event here.
 * To tell our view that the coin needs to disappear. The coin itself gets deleted from
 * eatenEntities and also all the entities.
 */
VictoryState::VictoryState(sf::RenderWindow *window,StateManager *stateManager, int ScoreOfTheGame) : State(window,stateManager), ScoreOfTheGame(ScoreOfTheGame) {
    if (!font.loadFromFile("C:/Users/Youssef/Advanced_Programming_PacMan/UF15XRU Arial.ttf")){
        cout << "Error loading font!" << endl;
    }

    VictoryText.setFont(font);
    VictoryText.setString("YOU WON!");
    VictoryText.setCharacterSize(60);
    VictoryText.setFillColor(sf::Color(255, 255, 0));
    VictoryText.setPosition(160, 30);

    BackButton.setSize(sf::Vector2f(200, 60));
    BackButton.setFillColor(sf::Color::Blue);
    BackButton.setPosition(200, 150);

    BackButtonText.setFont(font);
    BackButtonText.setString("Return to home menu");
    BackButtonText.setCharacterSize(15);
    BackButtonText.setFillColor(sf::Color::White);
    BackButtonText.setPosition(200,150);

    Score.setFont(font);
    Score.setString("Score: " + to_string(ScoreOfTheGame));
    Score.setCharacterSize(25);
    Score.setFillColor(sf::Color::Yellow);
    Score.setPosition(270, 225);
}
/**
 * @Functionality Pacman eats coin
 *
 * @Explanation We use the same system as for walls only now the hitboxes are much smaller
 * so it only triggers when we are almost in the middle. We also make use of an event here.
 * To tell our view that the coin needs to disappear. The coin itself gets deleted from
 * eatenEntities and also all the entities.
 */
void VictoryState::Input(sf::Event *event) {
    if (event->type == sf::Event::MouseButtonPressed) {
        sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
        if (BackButton.getGlobalBounds().contains(static_cast<float>(mousePosition.x),static_cast<float>(mousePosition.y))) {
            window->close();
        }
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
void VictoryState::update() {
    BackButton.setFillColor(sf::Color(255, 255, 0));
}
/**
 * @Functionality Pacman eats coin
 *
 * @Explanation We use the same system as for walls only now the hitboxes are much smaller
 * so it only triggers when we are almost in the middle. We also make use of an event here.
 * To tell our view that the coin needs to disappear. The coin itself gets deleted from
 * eatenEntities and also all the entities.
 */
void VictoryState::render() {
    window->draw(VictoryText);
    window->draw(BackButton);
    window->draw(BackButtonText);
    window->draw(Score);
}
/**
 * @Functionality Pacman eats coin
 *
 * @Explanation We use the same system as for walls only now the hitboxes are much smaller
 * so it only triggers when we are almost in the middle. We also make use of an event here.
 * To tell our view that the coin needs to disappear. The coin itself gets deleted from
 * eatenEntities and also all the entities.
 */
GameOverState::GameOverState(sf::RenderWindow *window,StateManager *stateManager, int ScoreOfTheGame) : State(window,stateManager) , ScoreOfTheGame(ScoreOfTheGame){
    if (!font.loadFromFile("C:/Users/Youssef/Advanced_Programming_PacMan/UF15XRU Arial.ttf")){
        cout << "Error loading font!" << endl;
    }

    GameOverText.setFont(font);
    GameOverText.setString("YOU LOST!");
    GameOverText.setCharacterSize(60);
    GameOverText.setFillColor(sf::Color(255, 255, 0));
    GameOverText.setPosition(160, 30);

    BackButton.setSize(sf::Vector2f(200, 60));
    BackButton.setFillColor(sf::Color::Blue);
    BackButton.setPosition(200, 150);

    BackButtonText.setFont(font);
    BackButtonText.setString("Return to home menu");
    BackButtonText.setCharacterSize(50);
    BackButtonText.setFillColor(sf::Color::White);
    BackButtonText.setPosition(200,200);

    Score.setFont(font);
    Score.setString("Score: " + to_string(ScoreOfTheGame));
    Score.setCharacterSize(25);
    Score.setFillColor(sf::Color::Yellow);
    Score.setPosition(270, 225);
}
/**
 * @Functionality Pacman eats coin
 *
 * @Explanation We use the same system as for walls only now the hitboxes are much smaller
 * so it only triggers when we are almost in the middle. We also make use of an event here.
 * To tell our view that the coin needs to disappear. The coin itself gets deleted from
 * eatenEntities and also all the entities.
 */
void GameOverState::Input(sf::Event *event) {
    if (event->type == sf::Event::MouseButtonPressed) {
        sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
        if (BackButton.getGlobalBounds().contains(static_cast<float>(mousePosition.x),static_cast<float>(mousePosition.y))) {
            window->close();
        }
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
void GameOverState::update() {
    BackButton.setFillColor(sf::Color(255, 255, 0));
}
/**
 * @Functionality Pacman eats coin
 *
 * @Explanation We use the same system as for walls only now the hitboxes are much smaller
 * so it only triggers when we are almost in the middle. We also make use of an event here.
 * To tell our view that the coin needs to disappear. The coin itself gets deleted from
 * eatenEntities and also all the entities.
 */
void GameOverState::render() {
    window->draw(GameOverText);
    window->draw(BackButton);
    window->draw(BackButtonText);
    window->draw(Score);
}
/**
 * @Functionality Pacman eats coin
 *
 * @Explanation We use the same system as for walls only now the hitboxes are much smaller
 * so it only triggers when we are almost in the middle. We also make use of an event here.
 * To tell our view that the coin needs to disappear. The coin itself gets deleted from
 * eatenEntities and also all the entities.
 */
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
    lives.setCharacterSize(50);
    lives.setFillColor(sf::Color(255, 255, 0));
    lives.setPosition(window->getSize().x/2+500,window->getSize().y-80);
    score = make_shared<Score>();
    factory = make_shared<ConcreteFactory>();
    world = make_shared<World>(factory);
    newLevel(0);
    lives.setString("Lives Remaining: " + std::to_string(world->getPacman()->getlives()));
}
/**
 * @Functionality Pacman eats coin
 *
 * @Explanation We use the same system as for walls only now the hitboxes are much smaller
 * so it only triggers when we are almost in the middle. We also make use of an event here.
 * To tell our view that the coin needs to disappear. The coin itself gets deleted from
 * eatenEntities and also all the entities.
 */
void LevelState::newLevel(int levelNumber) {
    if (levelNumber == 0) {
        auto level = make_shared<Level>("../levelTest.txt",camera);
        world->addLevel(level);
        world->setCurrentLevel(levelNumber);
        world->makeLevel(world->getCurrentLevel());
        for (auto& entity : world->getEntities()) {
            char symbol = entity->getSymbol();
            if (symbol == '#') {
                views.push_back(factory->WallView(entity, camera));
            }
            else if (symbol == '_') {
                views.push_back(factory->FloorView(entity, camera));
            }
            else if (symbol == 'S') {
                views.push_back(factory->SpawnView(entity,camera));
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
        world->getPacman()->attach(score.get());
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
    else {
        clearEverything();
        auto level = make_shared<Level>("../levelTest.txt",camera);
        world->addLevel(level);
        world->setCurrentLevel(levelNumber);
        world->makeLevel(world->getCurrentLevel());
        for (auto& entity : world->getEntities()) {
            char symbol = entity->getSymbol();
            if (symbol == '#') {
                views.push_back(factory->WallView(entity, camera));
            }
            else if (symbol == '_') {
                views.push_back(factory->FloorView(entity, camera));
            }
            else if (symbol == 'S') {
                views.push_back(factory->SpawnView(entity,camera));
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
        world->getPacman()->attach(score.get());
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
}
/**
 * @Functionality Pacman eats coin
 *
 * @Explanation We use the same system as for walls only now the hitboxes are much smaller
 * so it only triggers when we are almost in the middle. We also make use of an event here.
 * To tell our view that the coin needs to disappear. The coin itself gets deleted from
 * eatenEntities and also all the entities.
 */
void LevelState::clearEverything() {
    views.clear();
    world->setEntities({});
    world->set_ghosts({});
    world->set_to_be_eaten({});
    world->set_spawn({});
    world->set_time(0.0f);
    world->set_level_done(false);
    world->set_pac_h_it_once(0);
    world->set_countb(0);
    world->set_counto(0);
    world->set_countp(0);
    world->set_countr(0);
}
/**
 * @Functionality Pacman eats coin
 *
 * @Explanation We use the same system as for walls only now the hitboxes are much smaller
 * so it only triggers when we are almost in the middle. We also make use of an event here.
 * To tell our view that the coin needs to disappear. The coin itself gets deleted from
 * eatenEntities and also all the entities.
 */
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
/**
 * @Functionality Pacman eats coin
 *
 * @Explanation We use the same system as for walls only now the hitboxes are much smaller
 * so it only triggers when we are almost in the middle. We also make use of an event here.
 * To tell our view that the coin needs to disappear. The coin itself gets deleted from
 * eatenEntities and also all the entities.
 */
void LevelState::update() {
    if (!world->getLevelDone() && world->getPacman()->getlives() != 0) {
        lives.setString("Lives Remaining: " + std::to_string(world->getPacman()->getlives()));
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
    else {
        if (world->getWon()) {
            if (world->getCurLevel() == 3) {
                int GameScore = score->getScore();
                highscore.change(GameScore);
                stateManager->push(make_unique<VictoryState>(window,stateManager,GameScore));
            }
            else {
                world->set_pacmanlives(world->getPacman()->getlives());
                world->setCurrentLevel(world->getCurLevel()+1);
                int nextLevel = world->getCurLevel();
                world->set_won(false);
                newLevel(nextLevel);
            }
        }
        else {
            int GameScore = score->getScore();
            highscore.change(GameScore);
            stateManager->push(make_unique<GameOverState>(window,stateManager,GameScore));
        }
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
void LevelState::render() {
    window->clear();
    for (auto& view : views) {
        view->render(window);
    }
    window->draw(lives);
    window->draw(scoreTxt);
}
/**
 * @Functionality Pacman eats coin
 *
 * @Explanation We use the same system as for walls only now the hitboxes are much smaller
 * so it only triggers when we are almost in the middle. We also make use of an event here.
 * To tell our view that the coin needs to disappear. The coin itself gets deleted from
 * eatenEntities and also all the entities.
 */
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
/**
 * @Functionality Pacman eats coin
 *
 * @Explanation We use the same system as for walls only now the hitboxes are much smaller
 * so it only triggers when we are almost in the middle. We also make use of an event here.
 * To tell our view that the coin needs to disappear. The coin itself gets deleted from
 * eatenEntities and also all the entities.
 */
void PausedState::Input(sf::Event *event) {
    if (event->type == sf::Event::KeyPressed) {
        if (event->key.code == sf::Keyboard::Escape) {
            Stopwatch::getInstance().reset();
            stateManager->pop();
        }
    }
    if (event->type == sf::Event::MouseButtonPressed) {
        sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
        if (resume.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
            Stopwatch::getInstance().reset();
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
/**
 * @Functionality Pacman eats coin
 *
 * @Explanation We use the same system as for walls only now the hitboxes are much smaller
 * so it only triggers when we are almost in the middle. We also make use of an event here.
 * To tell our view that the coin needs to disappear. The coin itself gets deleted from
 * eatenEntities and also all the entities.
 */
void PausedState::update() {
}
/**
 * @Functionality Pacman eats coin
 *
 * @Explanation We use the same system as for walls only now the hitboxes are much smaller
 * so it only triggers when we are almost in the middle. We also make use of an event here.
 * To tell our view that the coin needs to disappear. The coin itself gets deleted from
 * eatenEntities and also all the entities.
 */
void PausedState::render() {
    window->draw(paused);
    window->draw(resume);
    window->draw(QuitGame);
    window->draw(ExitToDesktop);
}