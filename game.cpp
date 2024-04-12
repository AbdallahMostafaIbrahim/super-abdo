#include "game.h"
#include "mainmenuscene.h"

Game::Game(int width, int height) {
    // this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setFixedSize(width, height);
    setViewportMargins(-2, -2, -2, -2);


    currentScene = new MainMenuScene(this);
    this->setScene(currentScene);
}

