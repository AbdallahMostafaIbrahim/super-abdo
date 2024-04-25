#include "mainmenuscene.h"
#include "level1.h"
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
    newGameButton = new QPushButton();
    newGameButton->setText("New Game");
    newGameButton->setObjectName(QString("newGameButton"));
    newGameButton->setToolTip("New Game");
    newGameButton->setGeometry(QRect((this->width() / 2) - 135 / 2, 360, 100, 32));
    newGameButton->setAutoFillBackground(false);
    newGameButton->setCursor(Qt::PointingHandCursor);

    newGameButton->setStyleSheet(
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

    continueButton = new QPushButton();
    continueButton->setText("Continue...");
    continueButton->setObjectName(QString("newGameButton"));
    continueButton->setToolTip("Continue");
    continueButton->setGeometry(QRect((this->width() / 2) - 135 / 2, 420, 100, 32));
    continueButton->setAutoFillBackground(false);
    continueButton->setCursor(Qt::PointingHandCursor);

    continueButton->setStyleSheet(
        "QPushButton {"
        "   background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #2196F3, stop:1 #64B5F6); " // Gradient blue background
        "   color: white; "              // White text
        "   border-style: solid; "
        "   border-width: 2px; "
        "   border-color: #1976D2; "     // Darker blue border
        "   font: bold 14px; "
        "   min-width: 10em; "
        "   padding: 6px; "
        "}"
        "QPushButton:hover {"
        "   background-color: #1976D2;" // Darker blue on hover
        "}"
        "QPushButton:pressed {"
        "   background-color: #1565C0;" // Even darker blue when pressed
        "}");

    shopButton = new QPushButton();
    shopButton->setText("Shop");
    shopButton->setObjectName(QString("shopButton"));
    shopButton->setToolTip("View Shop");
    shopButton->setGeometry(QRect((this->width() / 2) - 135 / 2, 480, 100, 32));
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
    settingsButton->setGeometry(QRect((this->width() / 2) - 135 / 2, 540, 100, 32));
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
    addWidget(newGameButton);
    addWidget(continueButton);
    addWidget(shopButton);
    addWidget(settingsButton);

    // Event Handlers
    connect(newGameButton, SIGNAL(clicked()), this, SLOT(new_game()));
}

void MainMenuScene::new_game() {
    // Remove Buttons
    newGameButton->close();
    continueButton->close();

    // Create Level 1 and add the scene to the game
    game->startLevel(1);
}


