#ifndef LEVEL2_H
#define LEVEL2_H

#include "baselevel.h"
#include "game.h"
#include "levelsettings.h"
#include <QGraphicsScene>

class Level2 : public BaseLevel
{
public:
    Level2(Game* game); //constructor
private:
    LevelSettings levelSettings;
    LevelSettings getLevelSettings() override;  //returns the level settings of this level
    int getLevelIndex() override;   //returns the level index of this level
    Boss *newBoss() override;   //creates the corresponding boss
};

#endif
