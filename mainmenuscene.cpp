#include "mainmenuscene.h"
#include <QPushButton>
#include <QGraphicsScene>

MainMenuScene::MainMenuScene(Game* game): QGraphicsScene(game) {
    this->game = game;

    QPushButton* newGameButton = new QPushButton();
    newGameButton->setText("New Game");
    newGameButton->setObjectName(QString("newGameButton"));
    newGameButton->setToolTip("New Game");
    newGameButton->setGeometry(QRect(640, 360, 100, 32));
    newGameButton->setAutoFillBackground(false);

    // newGameButton->setStyleSheet(newGameButton->styleSheet().append("background-color: transparent;"));

    QPushButton* continueButton = new QPushButton();
    continueButton->setText("Continue...");
    continueButton->setObjectName(QString("newGameButton"));
    continueButton->setToolTip("Continue");
    continueButton->setGeometry(QRect(640, 420, 100, 32));
    continueButton->setAutoFillBackground(false);


    this->addWidget(newGameButton);
    this->addWidget(continueButton);


    connect(newGameButton, SIGNAL(clicked()), this, SLOT(new_game()));
}

void MainMenuScene::new_game() {
    game->scene()->clear();
}


