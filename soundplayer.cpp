#include "soundplayer.h"
#include <QMediaPlayer>
#include <QAudioOutput>

SoundPlayer::SoundPlayer() {

    // QAudioOutput* audioOutput = new QAudioOutput();
    // QMediaPlayer* mediaPlayer = new QMediaPlayer();
    // mediaPlayer->setSource(QUrl("qrc:/sounds/sounds/soundtrack.mp3"));
    // mediaPlayer->setAudioOutput(audioOutput);
    // audioOutput->setVolume(50);
    // mediaPlayer->setLoops(1000);
    // mediaPlayer->play();

}

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


void SoundPlayer::hitAbdo()
{
    mediaPlayer_hitAbdo->setSource(QUrl("qrc:/sound effects/AbdoHit.m4a"));
    mediaPlayer_hitAbdo->setAudioOutput(audioOutput_hitAbdo);
    audioOutput_hitAbdo->setVolume(50);
    mediaPlayer_hitAbdo->play();
}

void SoundPlayer::killAbdo()
{
    mediaPlayer_killAbdo->setSource(QUrl("qrc:/sounds/sounds/soundtrack.mp3"));
    mediaPlayer_killAbdo->setAudioOutput(audioOutput_killAbdo);
    audioOutput_killAbdo->setVolume(50);
    mediaPlayer_killAbdo->play();
}

void SoundPlayer::gameOver()
{
    mediaPlayer_gameOver->setSource(QUrl("qrc:/sounds/sounds/soundtrack.mp3"));
    mediaPlayer_gameOver->setAudioOutput(audioOutput_gameOver);
    audioOutput_gameOver->setVolume(50);
    mediaPlayer_gameOver->play();
}

void SoundPlayer::doubleFart()
{
    mediaPlayer_doubleFart->setSource(QUrl("qrc:/sounds/sounds/soundtrack.mp3"));
    mediaPlayer_doubleFart->setAudioOutput(audioOutput_doubleFart);
    audioOutput_doubleFart->setVolume(50);
    mediaPlayer_doubleFart->play();
}

void SoundPlayer::fireSoundWave()
{
    mediaPlayer_fireSoundWave->setSource(QUrl("qrc:/sounds/sounds/soundtrack.mp3"));
    mediaPlayer_fireSoundWave->setAudioOutput(audioOutput_fireSoundWave);
    audioOutput_fireSoundWave->setVolume(50);
    mediaPlayer_fireSoundWave->play();
}

void SoundPlayer::abdoJump()
{
    mediaPlayer_abdoJump->setSource(QUrl("qrc:/sounds/sounds/soundtrack.mp3"));
    mediaPlayer_abdoJump->setAudioOutput(audioOutput_abdoJump);
    audioOutput_abdoJump->setVolume(50);
    mediaPlayer_abdoJump->play();
}

void SoundPlayer::levelFinish()
{
    mediaPlayer_levelFinish->setSource(QUrl("qrc:/sounds/sounds/soundtrack.mp3"));
    mediaPlayer_levelFinish->setAudioOutput(audioOutput_levelFinish);
    audioOutput_levelFinish->setVolume(50);
    mediaPlayer_levelFinish->play();
}

void SoundPlayer::gameTheme()
{
    mediaPlayer_gameTheme->setSource(QUrl("qrc:/sounds/sounds/soundtrack.mp3"));
    mediaPlayer_gameTheme->setAudioOutput(audioOutput_gameTheme);
    audioOutput_gameTheme->setVolume(50);
    mediaPlayer_gameTheme->setLoops(1000);
    mediaPlayer_gameTheme->play();
}
