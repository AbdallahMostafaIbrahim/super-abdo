#include "level1.h"
#include "abdo.h"
#include "platform.h"
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QTimer>
#include <QFile>
#include <QTextStream>
#include <QUrl>
#include <QMessageBox>
#include <QKeyEvent>
#include <QDebug>

Level1::Level1(Game* game) : QGraphicsScene() {
    this->game = game;

    QTimer *timer = new QTimer(this);

    // KeyPresses default to false
    rightPressed = false;
    leftPressed = false;
    spacePressed = false;

    // The interval will be 1000 / 60, so the gameLoop function is called 60 times in one second
    deltaTime = 1000.0 / 60.0;

    horizontal = 0;
    speed = 10;
    timeAfterJump = 0;
    speedJumpFactor = 0.7f;
    jumpWidth = 660;
    jumpHeight = 100;
    isJumping = false;

    // Connect and start the game loop
    connect(timer, SIGNAL(timeout()), this, SLOT(gameLoop()));
    timer->start(deltaTime);

    // Scene Init
    initScene();
}

void Level1::initScene() {
    // Set the scene width to be a big number
    this->setSceneRect(0, 0, 5000, game->height());

    // Create the player (abdo)
    abdo = new Abdo();

    abdo->setPos(50, game->height() - 200);

    this->addItem(abdo);

    // Open Map File to load the platforms
    QFile file(":/maps/map_1.txt");
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(0, "Error", "Couldn't load level");
    }

    QTextStream stream(&file);

    int x, y, w, h;
    stream >> x >> y >> w >> h;
    while(!stream.atEnd()) {
        // Create Current Platform
        // Platform* platform = new Platform(w, h);
        // platform->setPos(x, game->height() - y);
        // this->addItem(platform);
        stream >> x >> y >> w >> h;
    }

    file.close();
}

float Level1::jumpFunction(int time) {
    return -(1/jumpWidth) * pow(time - sqrt(jumpHeight * jumpWidth), 2) + jumpHeight;
}

void Level1::gameLoop() {
    if(abdo) {
        if((leftPressed || rightPressed) && !(leftPressed && rightPressed)) {
            if(abdo->x() > 0 || rightPressed)
                abdo->moveBy(speed * (leftPressed ? -1 : 1) * (isJumping ? speedJumpFactor : 1), 0);
        }

        if(spacePressed && !isJumping) {
            isJumping = true;
            timeAfterJump = 0;
        }

        if(isJumping) {
            abdo->moveBy(0, -(jumpFunction(timeAfterJump) - (timeAfterJump == 0 ? 0 : jumpFunction(timeAfterJump - deltaTime))));
            timeAfterJump += deltaTime;
            if(game->height() - abdo->y() < 199) {
                isJumping = false;
                timeAfterJump = 0;
                abdo->setPos(abdo->x(), game->height() - 200);
            }
        }

        game->ensureVisible(abdo, 500, 0);
        update();
    }
}

void Level1::keyPressEvent(QKeyEvent *event) {
    switch(event->key()){
        case Qt::Key_Space:
            spacePressed = true;
            break;
        case Qt::Key_Right:
            rightPressed = true;
            abdo->setDirection(1);
            // horizontal = 1;
            break;
        case Qt::Key_Left:
            leftPressed = true;
            abdo->setDirection(-1);
            // horizontal = -1;
            break;
    }
    update();
}

void Level1::keyReleaseEvent(QKeyEvent *event) {
    switch(event->key()){
    case Qt::Key_Right:
        rightPressed = false;
        break;
    case Qt::Key_Left:
        leftPressed = false;
        break;
    case Qt::Key_Space:
        spacePressed = false;
        break;
    }
    update();
}
