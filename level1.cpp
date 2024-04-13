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

#define TERMINAL_VELOCITY 4.0

Level1::Level1(Game* game) : QGraphicsScene() {
    this->game = game;

    QTimer *timer = new QTimer(this);

    // KeyPresses default to false
    rightPressed = false;
    leftPressed = false;
    spacePressed = false;
    galabeyaGlideEnabled = true;
    doubleJumpEnabled = true;

    deltaTime = 5;

    speed = 3;
    timeAfterJump = 0;
    timeWhenStartedFalling = 0;
    speedJumpFactor = 0.6f;
    jumpWidth = 30;
    jumpHeight = 160;
    isJumping = false;
    isFalling = true;

    currentJumpCount = 0;
    maxJumps = 2;

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

    abdo->setPos(50, 0);

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
        Platform* platform = new Platform(w, h);
        platform->setPos(x, game->height() - y - h);
        this->addItem(platform);
        stream >> x >> y >> w >> h;
    }

    file.close();
}

float Level1::jumpFunction(int time) {
    return -pow((time/jumpWidth) - sqrt(jumpHeight), 2) + jumpHeight;
}

float Level1::fallFunction(int time) {
    if(galabeyaGlideEnabled){
        if(spacePressed) {
            return -pow(time / (jumpWidth * 3), 2);
        } else {
            return -pow(time / (jumpWidth), 2);
        }
    } else {
        return -pow(time / jumpWidth, 2);
    }
}

void Level1::moveHorizontally() {
    if(leftPressed && rightPressed) return;
    if(!leftPressed && !rightPressed) return;
    if(abdo->x() <= 0 && leftPressed) return;

    int direction = 0;
    GroundEntity* blocked = abdo->isBlockedHorizontally(direction);

    if(direction == 1 && rightPressed && blocked) {
        return;
    }
    if(direction == -1 && leftPressed && blocked) {
        return;
    }

    abdo->moveBy(speed * (leftPressed ? -1 : 1) * ((isJumping | isFalling) ? speedJumpFactor : 1), 0);
}

float min(float l, float r) {
    if(abs(l) < abs(r)) return l;
    else {
        if(l < 0) {
            return -abs(r);
        } else {
            return abs(r);
        }
    }
}

void Level1::moveVertically() {
    GroundEntity* ground = abdo->isGrounded();
    if(ground) {
        isFalling = false;
        if(spacePressed && !isJumping) {
            isJumping = true;
            abdo->moveBy(0, -1);
            timeAfterJump = deltaTime;
        } else {
            abdo->setPos(abdo->x(), ground->y() - abdo->boundingRect().height());
            isJumping = false;
            timeAfterJump = 0;
            currentJumpCount = 0;
        }
    } else {
        if(isJumping) {
            float deltaY = min(jumpFunction(timeAfterJump) - (jumpFunction(timeAfterJump - deltaTime)), TERMINAL_VELOCITY);
            abdo->moveBy(0, -deltaY);
            timeAfterJump += deltaTime;

            // Character is falling now
            if(deltaY < 0) {
                isJumping = false;
                timeAfterJump = 0;
                isFalling = true;
            }

            // Check if something is touching my head
            GroundEntity* ceiling = abdo->isTouchingHead();
            if(ceiling) {
                isJumping = false;
                timeAfterJump = 0;
                isFalling = true;
            }
        } else {
            float deltaY = min((fallFunction(timeAfterJump) - (timeAfterJump == 0 ? 0 : fallFunction(timeAfterJump - deltaTime))), TERMINAL_VELOCITY);
            abdo->moveBy(0, -deltaY);
            timeAfterJump += deltaTime;
        }
    }
}

void Level1::gameLoop() {
    moveHorizontally();
    moveVertically();
    game->ensureVisible(abdo, 500, 0);
    update();
}

void Level1::keyPressEvent(QKeyEvent *event) {
    switch(event->key()){
        case Qt::Key_Space:
        if(doubleJumpEnabled && (isJumping || isFalling)) {
                if(currentJumpCount < maxJumps - 1) {
                    isJumping = true;
                    abdo->moveBy(0, -1);
                    timeAfterJump = deltaTime;
                    currentJumpCount++;
                }
            }
            spacePressed = true;
            break;
        case Qt::Key_Right:
            rightPressed = true;
            abdo->setDirection(1);
            break;
        case Qt::Key_Left:
            leftPressed = true;
            abdo->setDirection(-1);
            break;
        case Qt::Key_Z:
            SoundWave* s = new SoundWave(abdo->getDirection());
            s->setPos(abdo->x()+20 * abdo->getDirection(),abdo->y()+abdo->boundingRect().height()/4);
            this->addItem(s);
    }
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
}
