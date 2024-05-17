#ifndef MAINMENUSCENE_H
#define MAINMENUSCENE_H

#include <QGraphicsScene>
#include <QPushButton>
#include "game.h"

// Home Screen
class MainMenuScene : public QGraphicsScene
{
Q_OBJECT
public:
    MainMenuScene(Game* game);
    ~MainMenuScene();
private:
    Game* game;
    QPushButton* playButton;
    QPushButton* shopButton;
    QPushButton* settingsButton;
private slots:
    void new_game();
    void shop();
    void settings();
};

#endif // MAINMENUSCENE_H
