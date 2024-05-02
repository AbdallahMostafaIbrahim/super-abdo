#include "level1.h"
#include <QFile>

Level1::Level1(Game *game) : BaseLevel(game) {
    // Setting Level Settings
    levelSettings.doubleJumpEnabled = false;
    levelSettings.galabeyaGlideEnabled = false;
    levelSettings.soundWaveEnabled = true;
    levelSettings.triggerBossLoc = 6000;
    levelSettings.mapFile = ":/maps/map-1/map.txt";
    levelSettings.enemiesFile = ":/maps/map-1/enemies.txt";
    levelSettings.backgroundImage = ":/images/background-1.png";
    levelSettings.sceneWidth = 8100;

    // Call Init Scene to load level using the settings
    initScene();
}

LevelSettings Level1::getLevelSettings() {
    return levelSettings;
}
