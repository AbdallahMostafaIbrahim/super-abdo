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

class Game : public QGraphicsView
{
    Q_OBJECT
public:
    Game(int, int);
    void startLevel(int index);
    void goToLevelSelector();
    void goToMainMenu();
private:
    // TODO: GameState like total coins and level reached

    // Storing pointers to scenes that will be set on the view
    BaseLevel* currentLevel;
    MainMenuScene* mainMenuScene;
    LevelSelector* lSelector;
    int currentLevelIndex;
public slots:
    // Event Handlers for events that will happen in the levels
    void restartLevel();
    void quitLevel();
    void completeLevel(int coinsCollected, int timeSpentinMs, int levelIndex);
};

#endif // GAME_H
