#ifndef GAMESAVER_H
#define GAMESAVER_H

#include <QFile>

class GameSaver
{
public:
    GameSaver();    //constructor
    static void saveState();    //saves the game data to an external file
    static void loadState();    //loads the game data from an external file
    static void init();         //initializes the game from the data from the external file
    static void clearState();   //deletes the game data
private:
    static QFile *file;
};

#endif // GAMESAVER_H
