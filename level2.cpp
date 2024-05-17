#include "level2.h"
#include "baselevel.h"
#include "levelloader.h"
#include "enemy/radar.h"
#include "QGraphicsTextItem"
#include "QGraphicsScene"
#include <QFile>

Level2::Level2(Game *game) : BaseLevel(game) {
    // Setting Level Settings
    levelSettings.triggerBossLoc = 11500;
    levelSettings.mapFile = ":/maps/map-2/map.txt";
    levelSettings.enemiesFile = ":/maps/map-2/enemies.txt";
    levelSettings.backgroundImage = ":/images/level-2/background-2.png";
    levelSettings.sceneWidth = 13500;
    levelSettings.sceneHeight = 2075;
    levelSettings.teleportStartX = 7000;
    levelSettings.teleportEndX = 7408;
    levelSettings.teleportStartY = 2075;
    levelSettings.teleportEndY = 1375;


    // Call Init Scene to load level using the settings
    initScene();
}

LevelSettings Level2::getLevelSettings() {
    return levelSettings;
}

Boss *Level2::newBoss()
{
    return new Radar;
}

int Level2::getLevelIndex()  {
    return 2;
}
