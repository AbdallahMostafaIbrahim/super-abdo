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
    MainMenuScene(Game* game);//constructor of main menu, sets background and buttons
    ~MainMenuScene();//destructor clears and removes connects
private:
    Game* game;
    QPushButton* playButton;
    QPushButton* shopButton;
    QPushButton* settingsButton;
private slots:
    void new_game();//goes to new game
    void shop();//goes to shop
    void settings();//goes to settings
};

#endif // MAINMENUSCENE_H
