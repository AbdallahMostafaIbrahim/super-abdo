#include "level1.h"
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include "abdo.h"
#include <iostream>
#include <QTimer>

Level1::Level1(Game* game) : QGraphicsScene() {
    this->game = game;
    QTimer *timer = new QTimer(this);
    timer->setInterval(20);
    connect(timer, SIGNAL(timeout()), this, SLOT(movePlayer()));
    timer->start();


}

void Level1::onLoad() {

    this->setSceneRect(0, 0, 5000, this->height());
    abdo = new Abdo();
    abdo->setPos(700, this->height() / 2);
    abdo->direction = 1;
    this->addItem(abdo);
}

void Level1::movePlayer() {
    if(abdo) {
        std::cout << abdo->pos().x() << std::endl;

        if(abdo->direction == 1){
            if(abdo->pos().x() >= 4000)
                abdo->direction = -1;
        }
        if(abdo->direction == -1) {
            if(abdo->pos().x() <= 50)
                abdo->direction = 1;
        }

        abdo->moveBy(10 * abdo->direction, 0);

        game->ensureVisible(abdo, 500, 0);
    }
}
