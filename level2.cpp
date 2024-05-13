#include "level2.h"
#include "enemy/karen.h"
#include <QFile>

Level2::Level2(Game *game) : BaseLevel(game) {
    // Setting Level Settings
    levelSettings.triggerBossLoc = 6000;
    levelSettings.mapFile = ":/maps/map-2/map.txt";
    levelSettings.enemiesFile = ":/maps/map-2/enemies.txt";
    levelSettings.backgroundImage = ":/images/background-1.png";
    levelSettings.sceneWidth = 8100;

    // Call Init Scene to load level using the settings
    initScene();
}

LevelSettings Level2::getLevelSettings() {
    return levelSettings;
}

Boss *Level2::newBoss()
{
    return new Karen;
}

int Level2::getLevelIndex()  {
    return 2;
}
