#ifndef LEVEL1_H
#define LEVEL1_H

#include <QGraphicsScene>
#include <QObject>
#include "game.h"
#include "abdo.h"

class Level1 : public QGraphicsScene
{
Q_OBJECT
public:
    Level1(Game* game);
protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
private:
    void initScene();
    float jumpFunction(int time);

    Game* game;
    Abdo* abdo;

    int timeAfterJump;
    bool isJumping;
    float jumpWidth;
    float jumpHeight;

    int horizontal;
    float speed;
    float speedJumpFactor;

    int deltaTime;

    bool leftPressed, rightPressed, spacePressed;


private slots:
    void gameLoop();
};

#endif // LEVEL1_H
