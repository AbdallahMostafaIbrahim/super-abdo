#ifndef LEVEL2_H
#define LEVEL2_H

#include "baselevel.h"
#include "game.h"
#include "levelsettings.h"

class Level2 : public BaseLevel
{
public:
    Level2(Game* game);
private:
    LevelSettings levelSettings;
    LevelSettings getLevelSettings() override;
    int getLevelIndex() override;
    Boss *newBoss() override;
};

#endif
