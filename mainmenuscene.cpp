#include "mainmenuscene.h"
#include "utils.h"
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

    // Create the buttons (I am in love this function <8)
    playButton = Utils::createPushButton("Play", (width() / 2) - 210 / 2, 300, 100, 32, QColor::fromString("#4CAF50"));
    shopButton = Utils::createPushButton("Shop", (width() / 2) - 210 / 2, 360, 100, 32, QColor::fromString("#7238c9"));
    settingsButton = Utils::createPushButton("Settings", (width() / 2) - 210 / 2, 420, 100, 32, QColor::fromString("#CC49A5"));

    // Add Buttons to Scene
    addWidget(playButton);
    addWidget(shopButton);
    addWidget(settingsButton);

    // Event Handlers
    connect(playButton, SIGNAL(clicked()), this, SLOT(new_game()));
    connect(shopButton, SIGNAL(clicked()), this, SLOT(shop()));
}

MainMenuScene::~MainMenuScene()
{
    clear();
    disconnect();
}

void MainMenuScene::new_game() {
    game->goToLevelSelector();
}

void MainMenuScene::shop() {
    game->goToShop();
}


