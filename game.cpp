#include "game.h"
#include "mainmenuscene.h"
#include "baselevel.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"
#include "level5.h"
#include "levelselector.h"
#include "shopscene.h"
#include "gamestate.h"
#include "settingsscene.h"

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
    levelSelectorScene = new LevelSelector(this);
    shopScene = new ShopScene(this);
    settingsScene = new SettingsScene(this);

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
    case 2:
        newLevel = new Level2(this);
        break;
    case 3:
        newLevel = new Level3(this);
        break;
    case 4:
        newLevel = new Level4(this);
        break;
    case 5:
        newLevel = new Level5(this);
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
    levelSelectorScene->update();
    setScene(levelSelectorScene);
}

void Game::gotoSettings()
{
    setScene(settingsScene);
}

void Game::goToShop()
{
    shopScene->update();
    setScene(shopScene);
}

void Game::goToMainMenu()
{
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
    GameState::levelReached = std::max(levelIndex + 1, GameState::levelReached);
    GameState::coinsCollected += coinsCollected;
    GameState::totalTimeSpendinMs += timeSpent;
    GameState::newlyPurchased.clear();
    if(levelIndex == 5) {
        goToMainMenu();
        mainMenuScene->playOutro();
    } else {
        goToLevelSelector();
    }
}



