#ifndef LEVEL3_H
#define LEVEL3_H

#include "baselevel.h"
#include "game.h"
#include "levelsettings.h"

class Level3 : public BaseLevel
{
public:
    Level3(Game* game);
private:
    LevelSettings levelSettings;
    LevelSettings getLevelSettings() override;
    Boss *newBoss() override;
};

#endif // LEVEL3_H

