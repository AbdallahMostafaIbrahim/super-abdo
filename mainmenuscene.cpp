#include "mainmenuscene.h"
#include "level1.h"
#include <QPushButton>
#include <QGraphicsScene>

MainMenuScene::MainMenuScene(Game* game): QGraphicsScene(game) {
    this->game = game;

    // Create the buttons
    newGameButton = new QPushButton();
    newGameButton->setText("New Game");
    newGameButton->setObjectName(QString("newGameButton"));
    newGameButton->setToolTip("New Game");
    newGameButton->setGeometry(QRect(640, 360, 100, 32));
    newGameButton->setAutoFillBackground(false);

    continueButton = new QPushButton();
    continueButton->setText("Continue...");
    continueButton->setObjectName(QString("newGameButton"));
    continueButton->setToolTip("Continue");
    continueButton->setGeometry(QRect(640, 420, 100, 32));
    continueButton->setAutoFillBackground(false);

    // Add Buttons to Scene
    this->addWidget(newGameButton);
    this->addWidget(continueButton);


    // Event Handlers
    connect(newGameButton, SIGNAL(clicked()), this, SLOT(new_game()));
}

void MainMenuScene::new_game() {
    newGameButton->close();
    continueButton->close();
    Level1* level1 = new Level1(game);
    game->setScene(level1);
    level1->onLoad();
}


