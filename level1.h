#ifndef LEVEL1_H
#define LEVEL1_H

#include <QGraphicsScene>
#include <QObject>
#include <QPainter>
#include <QRectF>
#include "game.h"
#include "abdo.h"
#include<QPushButton>

class Level1 : public QGraphicsScene
{
Q_OBJECT
public:
    Level1(Game* game);
    QPushButton* muteButton;
protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
private:
    void drawForeground(QPainter *painter, const QRectF &rect) override;

    void initScene();
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

    Game* game;
    Abdo* abdo;
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
    bool galabeyaGlideEnabled;
    bool doubleJumpEnabled;
    int currentJumpCount;
    int maxJumps;

    bool soundWaveEnabled;

    bool isGameOver;
    int finishedTime;
    bool isFightingBoss;
    int triggerBossLoc;
private slots:
    void gameLoop();
};

#endif // LEVEL1_H
