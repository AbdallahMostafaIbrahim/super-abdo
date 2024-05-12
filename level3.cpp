#include "level3.h"
#include "enemy/karen.h"
#include <QFile>

Level3::Level3(Game *game) : BaseLevel(game) {
    // Setting Level Settings
    levelSettings.doubleJumpEnabled = false;
    levelSettings.galabeyaGlideEnabled = false;
    levelSettings.soundWaveEnabled = true;
    levelSettings.triggerBossLoc = 6000;
    levelSettings.mapFile = ":/maps/map-1/level_3_map";
    levelSettings.enemiesFile = ":/maps/map-1/level_3_enemies";
    levelSettings.backgroundImage = ":/images/Level 3/background.png";
    levelSettings.sceneWidth = 8100;

    // Call Init Scene to load level using the settings
    initScene();
}

LevelSettings Level3::getLevelSettings() {
    return levelSettings;
}

Boss *Level3::newBoss()
{
    return new Karen;
}
