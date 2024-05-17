#ifndef LEVELSELECTOR_H
#define LEVELSELECTOR_H
#include <QGraphicsScene>
#include <QPushButton>
#include <QGraphicsProxyWidget>
#include "game.h"

// Level Selector Scene
class LevelSelector : public QGraphicsScene
{
Q_OBJECT
public:
    LevelSelector(Game* game);//constructor of level selectors sets background, buttons...
    void update();//updates if a new win happens, reset ...
private:
    QList<QPushButton*> levelButtons;
    Game* game;
    QPushButton* backButton;
private slots:
    void new_game(int index);//goes to new game with index of level
    void back();//goes back to mainmenu
};

#endif // LEVELSELECTOR_H
