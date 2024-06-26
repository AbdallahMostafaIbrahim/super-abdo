#include "level1.h"
#include "enemy/karen.h"
#include <QFile>

Level1::Level1(Game *game) : BaseLevel(game) {
    // Setting Level Settings
    levelSettings.triggerBossLoc = 6000;
    levelSettings.mapFile = ":/maps/map-1/map.txt";
    levelSettings.enemiesFile = ":/maps/map-1/enemies.txt";
    levelSettings.backgroundImage = ":/images/background-1.png";
    levelSettings.sceneWidth = 8100;
    levelSettings.sceneHeight = game->height();

    // Call Init Scene to load level using the settings
    initScene();
}

LevelSettings Level1::getLevelSettings() {
    return levelSettings;
}

Boss *Level1::newBoss()
{
    return new Karen;
}

int Level1::getLevelIndex()  {
    return 1;
}
