#ifndef LEVEL3_H
#define LEVEL3_H

#include "baselevel.h"
#include "game.h"
#include "levelsettings.h"

class Level3 : public BaseLevel
{
public:
    Level3(Game* game); //constructor
private:
    LevelSettings levelSettings;
    LevelSettings getLevelSettings() override;  //returns the level settings of this level
    int getLevelIndex() override;   //returns the level index of this level
    Boss *newBoss() override;   //creates the corresponding boss
};

#endif // LEVEL3_H

