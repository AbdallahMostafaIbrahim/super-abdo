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
    SettingsScene(Game* game);
private:
    Game* game;
    QPushButton* backButton;
    QPushButton* clearButton;
    QSlider* volumeSlider;
    QList<QWidget*> widgets;
private slots:
    void clearGameData();
    void back();
    void changeVolume();
};

#endif // SETTINGSSCENE_H
