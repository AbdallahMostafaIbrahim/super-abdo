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
    void drawForeground(QPainter *painter, const QRectF &rect) override;

    float jumpFunction(int time);
    float fallFunction(int time);

    void moveHorizontally();
    void moveVertically();
    void jumpPlayer();
    void fallPlayer();
    void checkCoins();
    void checkEnemies();
    void moveEnemies();
    void moveBullets();
    void spawnBoss();

    QElapsedTimer elapsedTimer;

    Game* game;
    Abdo* abdo;
    Boss* boss;
    QList<QGraphicsItem*> collidingItems;

    int elapsedTime;
    int timeAfterJump;
    int timeWhenStartedFalling;
    bool isJumping;
    bool isFalling;
    float jumpWidth;
    float jumpHeight;

    float speed;
    float speedJumpFactor;

    int health;
    int collectedCoins;

    int deltaTime;

    bool leftPressed, rightPressed, spacePressed, shootPressed;
    int currentJumpCount;
    int maxJumps;

    virtual LevelSettings getLevelSettings() = 0;

    int finishedTime;

    bool isGameOver;
    bool isFightingBoss;
    bool isGoodGame;
private slots:
    void gameLoop();
signals:
    void restart();  // Signal to notify the view of the restart event
    void quit();
};

#endif // BASELEVEL_H
