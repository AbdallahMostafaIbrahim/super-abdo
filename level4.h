#ifndef LEVEL4_H
#define LEVEL4_H
#include "levelsettings.h"
#include "baselevel.h"
#include "game.h"



class Level4 : public BaseLevel
{
public:
    Level4(Game* game);
private:
    LevelSettings levelSettings;
    LevelSettings getLevelSettings() override;
    int getLevelIndex() override;
    Boss *newBoss() override;
};

#endif // LEVEL4_H
