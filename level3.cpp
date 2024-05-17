#include "level3.h"
#include "enemy/splinter.h"
#include <QFile>

Level3::Level3(Game *game) : BaseLevel(game) {
    // Setting Level Settings
    levelSettings.doubleJumpEnabled = false;
    levelSettings.galabeyaGlideEnabled = false;
    levelSettings.soundWaveEnabled = true;
    levelSettings.triggerBossLoc = 6200;
    levelSettings.mapFile = ":/maps/map-3/map.txt";
    levelSettings.enemiesFile = ":/maps/map-3/enemies.txt";
    levelSettings.backgroundImage = ":/images/level-3/background.png";
    levelSettings.sceneWidth = 8100;

    // Call Init Scene to load level using the settings
    initScene();
}

LevelSettings Level3::getLevelSettings() {
    return levelSettings;
}

Boss *Level3::newBoss()
{
    return new Splinter;
}
