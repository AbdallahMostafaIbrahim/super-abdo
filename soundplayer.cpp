#include "soundplayer.h"
#include <QMediaPlayer>
#include <QAudioOutput>


SoundPlayer::SoundPlayer() {
}

float SoundPlayer::volumeFactor = 1.0;

QAudioOutput* SoundPlayer::audioOutput_hitAbdo = new QAudioOutput();
QMediaPlayer* SoundPlayer::mediaPlayer_hitAbdo = new QMediaPlayer();

QAudioOutput* SoundPlayer::audioOutput_killAbdo = new QAudioOutput();
QMediaPlayer* SoundPlayer::mediaPlayer_killAbdo = new QMediaPlayer();

QAudioOutput* SoundPlayer::audioOutput_gameOver = new QAudioOutput();
QMediaPlayer* SoundPlayer::mediaPlayer_gameOver = new QMediaPlayer();

QAudioOutput* SoundPlayer::audioOutput_doubleFart = new QAudioOutput();
QMediaPlayer* SoundPlayer::mediaPlayer_doubleFart = new QMediaPlayer();

QAudioOutput* SoundPlayer::audioOutput_fireSoundWave = new QAudioOutput();
QMediaPlayer* SoundPlayer::mediaPlayer_fireSoundWave = new QMediaPlayer();

QAudioOutput* SoundPlayer::audioOutput_abdoJump = new QAudioOutput();
QMediaPlayer* SoundPlayer::mediaPlayer_abdoJump = new QMediaPlayer();

QAudioOutput* SoundPlayer::audioOutput_levelFinish = new QAudioOutput();
QMediaPlayer* SoundPlayer::mediaPlayer_levelFinish = new QMediaPlayer();

QAudioOutput* SoundPlayer::audioOutput_gameTheme = new QAudioOutput();
QMediaPlayer* SoundPlayer::mediaPlayer_gameTheme = new QMediaPlayer();

QAudioOutput* SoundPlayer::audioOutput_babyCrying = new QAudioOutput();
QMediaPlayer* SoundPlayer::mediaPlayer_babyCrying = new QMediaPlayer();

void SoundPlayer::setVolume(float v) {
    volumeFactor = v;
}

float SoundPlayer::getVolume() {
    return volumeFactor;
}

void SoundPlayer::babyCrying()
{
    mediaPlayer_babyCrying->setSource(QUrl("qrc:/sound-effects/crying.mp3"));
    mediaPlayer_babyCrying->setAudioOutput(audioOutput_hitAbdo);
    audioOutput_babyCrying->setVolume(1);
    mediaPlayer_babyCrying->play();
}

void SoundPlayer::hitAbdo()
{
    mediaPlayer_hitAbdo->setSource(QUrl("qrc:/sound-effects/ouch.m4a"));
    mediaPlayer_hitAbdo->setAudioOutput(audioOutput_hitAbdo);
    audioOutput_hitAbdo->setVolume(1);
    mediaPlayer_hitAbdo->play();
}

void SoundPlayer::killAbdo()
{
    mediaPlayer_killAbdo->setSource(QUrl("qrc:/sound-effects/ouch.m4a"));
    mediaPlayer_killAbdo->setAudioOutput(audioOutput_killAbdo);
    audioOutput_killAbdo->setVolume(1);
    mediaPlayer_killAbdo->play();
}

void SoundPlayer::gameOver()
{
    mediaPlayer_gameOver->setSource(QUrl("qrc:/sound-effects/ouch.m4a"));
    mediaPlayer_gameOver->setAudioOutput(audioOutput_gameOver);
    audioOutput_gameOver->setVolume(1);
    mediaPlayer_gameOver->play();
}

void SoundPlayer::doubleJump()
{
    mediaPlayer_doubleFart->setSource(QUrl("qrc:/sound-effects/double-jump.mp3"));
    mediaPlayer_doubleFart->setAudioOutput(audioOutput_doubleFart);
    audioOutput_doubleFart->setVolume(1);
    mediaPlayer_doubleFart->play();
}

void SoundPlayer::fireSoundWave()
{
    mediaPlayer_fireSoundWave->setSource(QUrl("qrc:/sound-effects/gun-shot.mp3"));
    mediaPlayer_fireSoundWave->setAudioOutput(audioOutput_fireSoundWave);
    audioOutput_fireSoundWave->setVolume(0.5);
    mediaPlayer_fireSoundWave->play();
}

void SoundPlayer::abdoJump()
{
    mediaPlayer_abdoJump->setSource(QUrl("qrc:/sound-effects/jump.m4a"));
    mediaPlayer_abdoJump->setAudioOutput(audioOutput_abdoJump);
    audioOutput_abdoJump->setVolume(1);
    mediaPlayer_abdoJump->play();
}

void SoundPlayer::levelFinish()
{
    mediaPlayer_levelFinish->setSource(QUrl("qrc:/sound-effects/gun-shot.mp3"));
    mediaPlayer_levelFinish->setAudioOutput(audioOutput_levelFinish);
    audioOutput_levelFinish->setVolume(1);
    mediaPlayer_levelFinish->play();
}

void SoundPlayer::gameTheme(bool start)
{
    mediaPlayer_gameTheme->setSource(QUrl("qrc:/sound-effects/game-theme.mp3"));
    mediaPlayer_gameTheme->setAudioOutput(audioOutput_gameTheme);
    audioOutput_gameTheme->setVolume(0.1);
    mediaPlayer_gameTheme->setLoops(100);
    if(start)
        mediaPlayer_gameTheme->play();
    else
        mediaPlayer_gameTheme->stop();
}

void SoundPlayer::muteTheme()
{
    mediaPlayer_gameTheme->pause();
}
