#include "mainmenuscene.h"
#include "level1.h"
#include "levelselector.h"
#include <QPushButton>
#include <QGraphicsScene>
#include <QGraphicsProxyWidget>
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
    playButton = new QPushButton();
    playButton->setText("Play");
    playButton->setObjectName(QString("playButton"));
    playButton->setToolTip("Play");
    playButton->setGeometry(QRect((this->width() / 2) - 210 / 2, 300, 100, 32));
    playButton->setAutoFillBackground(false);
    playButton->setCursor(Qt::PointingHandCursor);

    playButton->setStyleSheet(
        "QPushButton {"
        "   background-color: #4CAF50; " // Green background
        "   color: white; "              // White text
        "   border-style: solid; "
        "   border-width: 2px; "
        "   border-color: #429646; "
        "   font: bold 14px; "
        "   min-width: 10em; "
        "   padding: 6px; "
        "}"
        "QPushButton:hover {"
        "   background-color: #45A049;" // darker green on hover
        "}"
        "QPushButton:pressed {"
        "   background-color: #397D39;" // Even darker green when pressed
        "}");



    shopButton = new QPushButton();
    shopButton->setText("Shop");
    shopButton->setObjectName(QString("shopButton"));
    shopButton->setToolTip("View Shop");
    shopButton->setGeometry(QRect((this->width() / 2) - 210 / 2, 360, 100, 32));
    shopButton->setAutoFillBackground(false);
    shopButton->setCursor(Qt::PointingHandCursor);

    shopButton->setStyleSheet(
        "QPushButton {"
        "   background-color: #7238c9;" // Gradient blue background
        "   color: white; "              // White text
        "   border-style: solid; "
        "   border-width: 2px; "
        "   border-color: #592c9c; "     // Darker blue border
        "   font: bold 14px; "
        "   min-width: 10em; "
        "   padding: 6px; "
        "}"
        "QPushButton:hover {"
        "   background-color: #6d36bf;" // Darker blue on hover
        "}"
        "QPushButton:pressed {"
        "   background-color: #6331ad;" // Even darker blue when pressed
        "}");

    settingsButton = new QPushButton();
    settingsButton->setText("Settings");
    settingsButton->setObjectName(QString("settingsButton"));
    settingsButton->setToolTip("View Settings");
    settingsButton->setGeometry(QRect((this->width() / 2) - 210 / 2, 420, 100, 32));
    settingsButton->setAutoFillBackground(false);
    settingsButton->setCursor(Qt::PointingHandCursor);

    settingsButton->setStyleSheet(
        "QPushButton {"
        "   background-color: #CC49A5;" // Gradient blue background
        "   color: white; "              // White text
        "   border-style: solid; "
        "   border-width: 2px; "
        "   border-color: #9E3780; "     // Darker blue border
        "   font: bold 14px; "
        "   min-width: 10em; "
        "   padding: 6px; "
        "}"
        "QPushButton:hover {"
        "   background-color: #BD4499;" // Darker blue on hover
        "}"
        "QPushButton:pressed {"
        "   background-color: #AD3D8C;" // Even darker blue when pressed
        "}");


    // Add Buttons to Scene
    addWidget(playButton);
    addWidget(shopButton);
    addWidget(settingsButton);

    // Event Handlers
    connect(playButton, SIGNAL(clicked()), this, SLOT(new_game()));
}

void MainMenuScene::new_game() {
    // Remove Buttons
    playButton->close();

    // Create Level 1 and add the scene to the game
    game->startLevel(1);
}


