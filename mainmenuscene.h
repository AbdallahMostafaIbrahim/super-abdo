#ifndef MAINMENUSCENE_H
#define MAINMENUSCENE_H

#include <QGraphicsScene>
#include "game.h"

class MainMenuScene : public QGraphicsScene
{
Q_OBJECT
public:
    MainMenuScene(Game* game);
private:
    Game* game;
private slots:
    void new_game();
};

#endif // MAINMENUSCENE_H
