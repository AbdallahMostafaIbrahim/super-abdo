#ifndef LEVELSELECTOR_H
#define LEVELSELECTOR_H
#include <QGraphicsScene>
#include <QPushButton>
#include "game.h"

class levelSelector : public QGraphicsScene
{
Q_OBJECT
public:
    levelSelector(Game* game);
private:
    QPushButton* Level_1;
    QPushButton* Level_2;
    QPushButton* Level_3;
    QPushButton* Level_4;
    QPushButton* Level_5;
    Game* game;
private slots:
    void new_game_1();
    void new_game_2();
    void new_game_3();
    void new_game_4();
    void new_game_5();

};

#endif // LEVELSELECTOR_H
