#include "game.h"
#include "mainmenuscene.h"

Game::Game(int width, int height) {
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(width, height);
    setViewportMargins(-2, -10, -2, -10);

    setScene(new MainMenuScene(this));
}

void Game::switchScene(QGraphicsScene *s)
{
    delete scene();
    setScene(s);
}

