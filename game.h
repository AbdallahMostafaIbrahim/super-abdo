#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>

// I am so smart :)
// This is used to prevent recursive importing errors.
class BaseLevel;
class MainMenuScene;
class LevelSelector;
class ShopScene;
class SettingsScene;

class Game : public QGraphicsView
{
    Q_OBJECT
public:
    Game(int, int);
    void startLevel(int index);
    void goToLevelSelector();
    void gotoSettings();
    void goToShop();
    void goToMainMenu();
private:
    // Storing pointers to scenes that will be set on the view
    BaseLevel* currentLevel;
    MainMenuScene* mainMenuScene;
    LevelSelector* levelSelectorScene;
    ShopScene* shopScene;
    SettingsScene* settingsScene;
    int currentLevelIndex;
public slots:
    // Event Handlers for events that will happen in the levels
    void restartLevel();
    void quitLevel();
    void completeLevel(int coinsCollected, int timeSpentinMs, int levelIndex);
};

#endif // GAME_H
