#ifndef LEVEL1_H
#define LEVEL1_H

#include "baselevel.h"
#include "game.h"
#include "levelsettings.h"

class Level1 : public BaseLevel
{
public:
    Level1(Game* game);
private:
    LevelSettings levelSettings;
    LevelSettings getLevelSettings() override;
};

#endif // LEVEL1_H
