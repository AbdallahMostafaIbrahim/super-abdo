#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>

class Game : public QGraphicsView
{
    Q_OBJECT
public:
    Game(int, int);
    void switchScene(QGraphicsScene*);
private:
    // TODO: GameState

};

#endif // GAME_H
