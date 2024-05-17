#ifndef GAMESAVER_H
#define GAMESAVER_H

#include <QFile>

class GameSaver
{
public:
    GameSaver();
    static void saveState();
    static void loadState();
    static void init();
    static void clearState();
private:
    static QFile *file;
};

#endif // GAMESAVER_H
