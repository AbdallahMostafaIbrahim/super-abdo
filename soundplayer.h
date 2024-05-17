#ifndef SOUNDPLAYER_H
#define SOUNDPLAYER_H
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QPushButton>

// Static Class that plays audio :)
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

    static QMediaPlayer* mediaPlayer_babyCrying;
    static QAudioOutput* audioOutput_babyCrying;
public:
    SoundPlayer();//constructor of Soundplayer
    static void hitAbdo();//sound of abdo when he gets hit
    static void killAbdo();//sound of abdo dies
    static void gameOver();//sound when game is over
    static void doubleJump();//sound when double jump happens
    static void fireSoundWave();//sound when shot is fired
    static void abdoJump();//sound when abdo jumps
    static void levelFinish();//sound when you finish level
    static void gameTheme(bool start = true);//game theme sound
    static void muteTheme();//function to mute the theme song
    static void babyCrying();//sound of baby crying when he dies
    static float volumeFactor;// sets volume factor
};

#endif // SOUNDPLAYER_H
