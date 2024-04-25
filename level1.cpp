#include "level1.h"
#include <QFile>

Level1::Level1(Game *game) : BaseLevel(game) {
    levelSettings.doubleJumpEnabled = false;
    levelSettings.galabeyaGlideEnabled = false;
    levelSettings.soundWaveEnabled = true;
    levelSettings.triggerBossLoc = 6000;
    levelSettings.mapFile = ":/maps/map-1/map.txt";
    levelSettings.enemiesFile = ":/maps/map-1/enemies.txt";
    levelSettings.sceneWidth = 8100;

    initScene();
}

LevelSettings Level1::getLevelSettings() {
    return levelSettings;
}
