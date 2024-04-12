#ifndef LEVEL1_H
#define LEVEL1_H

#include <QGraphicsScene>
#include <QObject>
#include "game.h"
#include "abdo.h"

class Level1 : public QGraphicsScene
{
Q_OBJECT
public:
    Level1(Game* game);
    void onLoad();
private:
    Game* game;
    Abdo* abdo;
private slots:
    void movePlayer();
};

#endif // LEVEL1_H
