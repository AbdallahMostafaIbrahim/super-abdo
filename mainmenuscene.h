#ifndef MAINMENUSCENE_H
#define MAINMENUSCENE_H

#include <QGraphicsScene>
#include <QPushButton>
#include <QMediaPlayer>
#include <QGraphicsVideoItem>
#include "game.h"

// Home Screen
class MainMenuScene : public QGraphicsScene
{
Q_OBJECT
public:
    MainMenuScene(Game* game);//constructor of main menu, sets background and buttons
    ~MainMenuScene();//destructor clears and removes connects
    void playOutro();
private:
    Game* game;
    QPushButton* playButton;
    QPushButton* shopButton;
    QPushButton* settingsButton;
    QMediaPlayer* videoPlayer;
    QGraphicsVideoItem* videoItem;
    void stopVideo();
protected:
    void keyPressEvent(QKeyEvent* event) override;
private slots:
    void new_game();//goes to new game
    void shop();//goes to shop
    void settings();//goes to settings
    void handleVideoStatusChange(QMediaPlayer::MediaStatus status); // removes the video when stopped
};

#endif // MAINMENUSCENE_H
