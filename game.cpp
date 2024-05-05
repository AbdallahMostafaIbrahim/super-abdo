#include "game.h"
#include "mainmenuscene.h"
#include "baselevel.h"
#include "level1.h"
#include "levelselector.h"
#include "gamestate.h"

Game::Game(int width, int height) {
    // Remove Scrollbars
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // Set size of view
    setFixedSize(width, height);
    setViewportMargins(-2, -10, -2, -10);

    // At first, there is no level loader
    currentLevel = nullptr;
    currentLevelIndex = -1;

    mainMenuScene = new MainMenuScene(this);
    lSelector = new LevelSelector(this);

    // Start with main menu scene
    setScene(mainMenuScene);
}

void Game::startLevel(int index)
{
    // Create the correct level based on the index
    BaseLevel* newLevel = nullptr;
    switch (index) {
    case 1:
        newLevel = new Level1(this);
        break;
    default:
        qDebug() << "Unknown level index:" << index;
        return;
    }

    if (newLevel) {
        // Set the pointer and connect the events (signals) to their handlers (slots)
        currentLevel = newLevel;
        currentLevelIndex = index;
        connect(currentLevel, &BaseLevel::restart, this, &Game::restartLevel);
        connect(currentLevel, &BaseLevel::quit, this, &Game::quitLevel);
        connect(currentLevel, &BaseLevel::complete, this, &Game::completeLevel);
        setScene(currentLevel);
    }
}

void Game::goToLevelSelector()
{
    lSelector = new LevelSelector(this);
    setScene(lSelector);
}

void Game::goToMainMenu()
{
    mainMenuScene = new MainMenuScene(this);
    setScene(mainMenuScene);
}

void Game::restartLevel() {
    if (currentLevel) {
        delete currentLevel;
    }
    startLevel(currentLevelIndex);
}

void Game::quitLevel() {
    if (currentLevel) {
        delete currentLevel;
    }
    setScene(mainMenuScene);
}

void Game::completeLevel(int coinsCollected, int timeSpent, int levelIndex) {
    if (currentLevel) {
        delete currentLevel;
    }
    GameState::levelReached = levelIndex + 1;
    GameState::coinsCollected += coinsCollected;
    GameState::totalTimeSpendinMs += timeSpent;
    goToLevelSelector();
}



