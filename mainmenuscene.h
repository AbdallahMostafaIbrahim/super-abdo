#ifndef MAINMENUSCENE_H
#define MAINMENUSCENE_H

#include <QGraphicsScene>
#include <QPushButton>
#include "game.h"

class MainMenuScene : public QGraphicsScene
{
Q_OBJECT
public:
    MainMenuScene(Game* game);
private:
    Game* game;
    QPushButton* newGameButton;
    QPushButton* continueButton;
    QPushButton* shopButton;
    QPushButton* settingsButton;
private slots:
    void new_game();
};

#endif // MAINMENUSCENE_H
