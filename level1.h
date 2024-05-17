#ifndef LEVEL1_H
#define LEVEL1_H

#include "baselevel.h"
#include "game.h"
#include "levelsettings.h"

class Level1 : public BaseLevel
{
public:
    Level1(Game* game);    //constructor
private:
    LevelSettings levelSettings;
    LevelSettings getLevelSettings() override; //returns the level settings of this level
    int getLevelIndex() override;   //returns the level index of this level
    Boss *newBoss() override;   //creates the corresponding boss
};

#endif // LEVEL1_H
