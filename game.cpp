#include "game.h"
#include "mainmenuscene.h"
#include "baselevel.h"
#include "level1.h"

Game::Game(int width, int height) {
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(width, height);
    setViewportMargins(-2, -10, -2, -10);
    currentLevel = nullptr;
    currentLevelIndex = -1;

    mainMenuScene = new MainMenuScene(this);
    setScene(mainMenuScene);
}

void Game::startLevel(int index)
{
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
        currentLevel = newLevel;
        currentLevelIndex = index;
        connect(currentLevel, &BaseLevel::restart, this, &Game::restartLevel);
        connect(currentLevel, &BaseLevel::quit, this, &Game::quitLevel);
        setScene(currentLevel);
    }
}

void Game::restartLevel() {
    if (currentLevel) {
        delete currentLevel;  // Properly delete the current level to avoid memory leaks
    }
    startLevel(currentLevelIndex);
}

void Game::quitLevel() {
    if (currentLevel) {
        delete currentLevel;  // Properly delete the current level to avoid memory leaks
    }
    setScene(mainMenuScene);
}


