#include "gamesaver.h"
#include <QStandardPaths>
#include <QDir>
#include <QMessageBox>
#include "gamestate.h"
#include "soundplayer.h"

GameSaver::GameSaver() {}

QFile* GameSaver::file = nullptr;

void GameSaver::init()
{
    QString homeDir =
        QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    QString folderPath = homeDir + "/.super-abdo";

    QDir dir;

    if (!dir.exists(folderPath))
        dir.mkpath(folderPath);

    file = new QFile(folderPath + "/state.txt");

    if (!file->exists()) {
        file->open((QIODevice::ReadWrite | QIODevice::Text));
        file->close();

        // To Init the file with default values
        saveState();
    }
}

void GameSaver::clearState()
{
    GameState::itemsBought.clear();
    GameState::newlyPurchased.clear();
    GameState::levelReached = 1;
    GameState::totalTimeSpendinMs = 0;
    GameState::coinsCollected = 0;
}

void GameSaver::saveState() {
    if (!file->open((QIODevice::ReadWrite | QIODevice::Text))) {
        qDebug() << file->errorString();
        QMessageBox::critical(0, "Error", "Couldn't load level");
    }
    QTextStream stream(file);
    file->resize(0);

    stream << (int)(SoundPlayer::volumeFactor * 100) << " " << GameState::coinsCollected << " " << GameState::levelReached << " " << GameState::totalTimeSpendinMs << '\n';

    for(auto& item: GameState::itemsBought) {
        stream << item << " ";
    }

    stream.flush();
    file->close();
}

void GameSaver::loadState() {
    if (!file->open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(0, "Error", "Couldn't load level");
    }

    QTextStream in(file);
    float volume;
    in >> volume >> GameState::coinsCollected >> GameState::levelReached >> GameState::totalTimeSpendinMs;
    SoundPlayer::volumeFactor = volume / 100.0;
    GameState::itemsBought.clear();


    int item;
    while(!in.atEnd()) {
        in >> item;
        if (item >= DOUBLE_JUMP && item <= EXTRA_HEART) {
            GameState::itemsBought.insert(static_cast<ShopItem>(item));
        }
    }

    file->close();
}
