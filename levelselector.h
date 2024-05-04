#ifndef LEVELSELECTOR_H
#define LEVELSELECTOR_H
#include <QGraphicsScene>
#include <QPushButton>
#include "game.h"

// Level Selector Scene
class LevelSelector : public QGraphicsScene
{
Q_OBJECT
public:
    LevelSelector(Game* game);
private:
    QPushButton* Level_1;
    QPushButton* Level_2;
    QPushButton* Level_3;
    QPushButton* Level_4;
    QPushButton* level5Button;
    QList<QPushButton*> levelButtons;
    Game* game;
private slots:
    void new_game(int index);
};

#endif // LEVELSELECTOR_H
