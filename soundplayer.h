#ifndef SOUNDPLAYER_H
#define SOUNDPLAYER_H
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QPushButton>

class SoundPlayer
{
private:

    static QMediaPlayer* mediaPlayer_hitAbdo;
    static QAudioOutput* audioOutput_hitAbdo;

    static QMediaPlayer* mediaPlayer_killAbdo;
    static QAudioOutput* audioOutput_killAbdo;

    static QMediaPlayer* mediaPlayer_gameOver;
    static QAudioOutput* audioOutput_gameOver;

    static QMediaPlayer* mediaPlayer_doubleFart;
    static QAudioOutput* audioOutput_doubleFart;

    static QMediaPlayer* mediaPlayer_fireSoundWave;
    static QAudioOutput* audioOutput_fireSoundWave;

    static QMediaPlayer* mediaPlayer_abdoJump;
    static QAudioOutput* audioOutput_abdoJump;

    static QMediaPlayer* mediaPlayer_levelFinish;
    static QAudioOutput* audioOutput_levelFinish;

    static QMediaPlayer* mediaPlayer_gameTheme;
    static QAudioOutput* audioOutput_gameTheme;

    static float volumeFactor;
public:
    SoundPlayer();
    static void hitAbdo();
    static void killAbdo();
    static void gameOver();
    static void doubleJump();
    static void fireSoundWave();
    static void abdoJump();
    static void levelFinish();
    static void gameTheme(bool start = true);
    static void muteTheme();
    static void setVolume(float v);
    static float getVolume();


    // TODO: add sounds after killing enemies
};

#endif // SOUNDPLAYER_H
