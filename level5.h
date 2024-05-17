#ifndef LEVEL5_H
#define LEVEL5_H
#include "levelsettings.h"
#include "baselevel.h"
#include "game.h"

class Level5 : public BaseLevel
{
public:
    Level5(Game* game);
private:
    LevelSettings levelSettings;
    LevelSettings getLevelSettings() override;
    int getLevelIndex() override;
    Boss *newBoss() override;
};

#endif // LEVEL5_H
