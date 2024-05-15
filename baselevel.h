#ifndef BASELEVEL_H
#define BASELEVEL_H

#include <QGraphicsScene>
#include <QObject>
#include <QPainter>
#include <QRectF>
#include <QElapsedTimer>
#include "game.h"
#include "abdo.h"
#include "enemy/boss.h"
#include "levelsettings.h"

// This is a generic level that combines everything in common with all the 5 levels. Mainly, it has the game loop which gets called continously and contains the necessary code
// for the level.
class BaseLevel : public QGraphicsScene
{
    Q_OBJECT
public:
    BaseLevel(Game* game);
    ~BaseLevel();
    void killBoss();
protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    void initScene();
private:
    // Overriding drawForeground to show HUD elements like health and coins.
    void drawForeground(QPainter *painter, const QRectF &rect) override;

    // Quadratic functions to simulate smooth jump
    float jumpFunction(int time);
    float fallFunction(int time);

    // Function that all get called in the game loop
    void moveHorizontally();
    void moveVertically();
    void jumpPlayer();
    void fallPlayer();
    void checkCoins();
    void checkOil();
    void checkEnemies();
    void moveEnemies();
    void moveBullets();
    void spawnBoss();

    // Timer to calculate time (deltatime) between each game loop call and the other.
    QElapsedTimer elapsedTimer;
    int deltaTime;

    Game* game;
    Abdo* abdo;
    Boss* boss;
    QList<QGraphicsItem*> collidingItems;

    // elapsedTime Keeps incrementing to keep track on time spent during game
    int elapsedTime;

    int timeAfterJump;
    int timeWhenStartedFalling;
    int timeWhenShot;
    // Jumping States
    bool isJumping;
    bool isFalling;

    // Adjustable jump constants
    float jumpWidth;
    float jumpHeight;

    float initalSpeed;
    float speed;
    // Factor to multipy by Speed when player is jumping
    float speedJumpFactor;

    // Game Stats
    int health;
    int collectedCoins;

    // Keyboard Handling
    bool leftPressed, rightPressed, spacePressed, shootPressed;

    // This is used for double jump
    int currentJumpCount;
    int maxJumps;

    // This function will be overrided for each level
    virtual LevelSettings getLevelSettings() = 0;
    virtual Boss* newBoss() = 0;
    virtual int getLevelIndex() = 0;

    // Stores the time after the game has ended
    int finishedTime;

    // Game States
    bool isGameOver;
    bool isFightingBoss;
    bool isGoodGame;
    bool isTeleport;

    // Settings From Gamestate
    bool galabeyaGlideEnabled;
    bool doubleJumpEnabled;
    bool soundWaveEnabled;
    bool firstTimeGliding;
    bool firstTimeDoubleJumping;
private slots:
    void gameLoop();
signals:
    void restart();  // Signal to notify the view of the restart event
    void quit();
    void complete(int coinsCollected, int timeSpendinMs, int levelIndex);
};

#endif // BASELEVEL_H
