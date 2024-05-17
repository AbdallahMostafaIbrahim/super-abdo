#include "level5.h"
#include "levelsettings.h"
#include "enemy/aliandjoshandabdallah.h"
#include "baselevel.h"
#include "game.h"

Level5::Level5(Game *game) : BaseLevel(game) {
    // Setting Level Settings

    levelSettings.triggerBossLoc = 5000;
    levelSettings.mapFile = ":/maps/map-5/map.txt";
    levelSettings.enemiesFile = ":/maps/map-5/enemies.txt";
    levelSettings.backgroundImage = ":/images/level-5/background-5.png";
    levelSettings.sceneWidth = 7000;
    levelSettings.sceneHeight = 850;

    // Call Init Scene to load level using the settings
    initScene();
}

LevelSettings Level5::getLevelSettings() {
    return levelSettings;
}

Boss *Level5::newBoss()
{
    return new AliAndJoshAndAbdallah;
}

int Level5::getLevelIndex()  {
    return 5;
}
