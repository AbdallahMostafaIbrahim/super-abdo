#include "mainmenuscene.h"
#include "level1.h"
#include <QPushButton>
#include <QGraphicsScene>
#include <QBrush>
#include <QLabel>
#include <QColor>

MainMenuScene::MainMenuScene(Game* game): QGraphicsScene(game) {
    this->game = game;
    this->setSceneRect(0,0, game->width(), game->height());

    // Set Background Image
    QBrush bgBrush(QColor(0, 1, 26));
    this->setBackgroundBrush(bgBrush);

    // Create the buttons
    newGameButton = new QPushButton();
    newGameButton->setText("New Game");
    newGameButton->setObjectName(QString("newGameButton"));
    newGameButton->setToolTip("New Game");
    newGameButton->setGeometry(QRect((this->width() / 2) - 100 / 2, 360, 100, 32));
    newGameButton->setAutoFillBackground(false);

    continueButton = new QPushButton();
    continueButton->setText("Continue...");
    continueButton->setObjectName(QString("newGameButton"));
    continueButton->setToolTip("Continue");
    continueButton->setGeometry(QRect((this->width() / 2) - 100 / 2, 420, 100, 32));
    continueButton->setAutoFillBackground(false);

    // Add Buttons to Scene
    this->addWidget(newGameButton);
    this->addWidget(continueButton);


    // Event Handlers
    connect(newGameButton, SIGNAL(clicked()), this, SLOT(new_game()));
}

void MainMenuScene::new_game() {
    // Remove Buttons
    newGameButton->close();
    continueButton->close();

    // Create Level 1 and add the scene to the game
    Level1* level1 = new Level1(game);
    game->setScene(level1);
}


