#ifndef LEVEL4_H
#define LEVEL4_H
#include "levelsettings.h"
#include "baselevel.h"
#include "game.h"



class Level4 : public BaseLevel
{
public:
    Level4(Game* game); //constructor
private:
    LevelSettings levelSettings;
    LevelSettings getLevelSettings() override;  //returns the level settings of this level
    int getLevelIndex() override;   //returns the level index of this level
    Boss *newBoss() override;   //creates the corresponding boss
};

#endif // LEVEL4_H
