#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>

// I am so smart :)
class BaseLevel;
class MainMenuScene;
class levelSelector;

class Game : public QGraphicsView
{
    Q_OBJECT
public:
    Game(int, int);
    void switchScene(QGraphicsScene*);
    void startLevel(int index);
    void goToLevelSelector();
private:
    // TODO: GameState
    BaseLevel* currentLevel;
    MainMenuScene* mainMenuScene;
    levelSelector* lSelector;
    int currentLevelIndex;
public slots:
    void restartLevel();
    void quitLevel();
};

#endif // GAME_H
