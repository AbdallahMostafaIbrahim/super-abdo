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
    LevelSelector(Game* game);
    void update();
private:
    QList<QPushButton*> levelButtons;
    Game* game;
    QPushButton* backButton;
private slots:
    void new_game(int index);
    void back();
};

#endif // LEVELSELECTOR_H
