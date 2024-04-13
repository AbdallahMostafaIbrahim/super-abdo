#include "level1.h"
#include "abdo.h"
#include "level_props/platform.h"
#include "level_props/desk.h"
#include "level_props/pictureframe.h"
#include "level_props/ceilinglight.h"
#include "level_props/officewindow.h"
#include "levelloader.h"
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

    deltaTime = 5;

    speed = 3;
    timeAfterJump = 0;
    timeWhenStartedFalling = 0;
    speedJumpFactor = 0.6f;
    jumpWidth = 30;
    jumpHeight = 160;
    isJumping = false;
    isFalling = true;

    // Connect and start the game loop
    connect(timer, SIGNAL(timeout()), this, SLOT(gameLoop()));
    timer->start(deltaTime);

    // Scene Init
    initScene();
}

void Level1::initScene() {
    // Set the scene width to be a big number
    this->setSceneRect(0, 0, 10000, game->height());
    this->setBackgroundBrush(QBrush(QPixmap(":/images/background-1.png").scaledToHeight(game->height())));

    // Create the player (abdo)
    abdo = new Abdo();

    abdo->setPos(50, 0);

    this->addItem(abdo);

    // Open Map File to load the platforms
    QFile file(":/maps/map-1/map.txt");
    LevelLoader loader(file);
    loader.fillScene(this);



    // int x, y, w, h, tile;
    // QString url;
    // stream >> x >> y >> w >> h >> url >> tile;
    // while(!stream.atEnd()) {
    //     // Create Current Platform
    //     qDebug() << url;
    //     QPixmap p = QPixmap(url);
    //     if(tile == 1) {
    //         p = p.scaledToHeight(h);
    //     } else {
    //         p = p.scaled(w, h);
    //     }
    //     Platform* platform = new Platform(w, h, p);
    //     platform->setPos(x, game->height() - y - h);
    //     this->addItem(platform);
    //     stream >> x >> y >> w >> h >> url >> tile;
    // }

    // file.close();

    // Desk *desk = new Desk();
    // desk->setPos(150, game->height() - 60 - 55);
    // this->addItem(desk);

    // PictureFrame *frame = new PictureFrame();
    // frame->setPos(360, game->height() / 2);
    // frame->setZValue(-1);
    // this->addItem(frame);

    // CeilingLight *light = new CeilingLight();
    // light->setPos(320, 0);
    // light->setZValue(-1);
    // this->addItem(light);

    // OfficeWindow *window = new OfficeWindow();
    // window->setPos(720, (game->height() / 2) + window->pixmap().height() / 2);
    // window->setZValue(-1);
    // this->addItem(window);
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
            abdo->setPos(abdo->x(), ground->y() + ground->boundingRect().y() - abdo->boundingRect().height());
            isJumping = false;
            timeAfterJump = 0;
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
