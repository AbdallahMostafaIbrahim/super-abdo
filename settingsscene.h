#ifndef SETTINGSSCENE_H
#define SETTINGSSCENE_H

#include <QGraphicsScene>
#include <QPushButton>
#include <QSlider>
#include "game.h"
#include <QList>

class SettingsScene : public QGraphicsScene
{
Q_OBJECT
public:
    SettingsScene(Game* game);//constructor of settings scene sets background and buttons
private:
    Game* game;
    QPushButton* backButton;
    QPushButton* clearButton;
    QSlider* volumeSlider;
    QList<QWidget*> widgets;
private slots:
    void clearGameData();//function to clear game data and restart from the begining
    void back();//function to go back to menu
    void changeVolume();//function to change volume level
};

#endif // SETTINGSSCENE_H
